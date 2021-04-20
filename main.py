text = input()
# text = "1,2,3,5,4,2"
# text = "1,2,3,2,4,3,2,1"
# text = "1,2,3,3,4,5,2,1"
# text = "1,2,3,4,5,4,3,2,1"
# text = "-5,2,5,3,2,1,-3"
inp = text.split(',')
pfs = 0


class Page:
    def __init__(self, name):
        self.name = name
        self.freeze_count = 0
        self.lastUsed = 0
        self.frame = -1
        self.dirty_data = False

    def frozen(self):
        return self.freeze_count > 0


A = Page("A")
B = Page("B")
C = Page("C")
pages = [A, B, C]  # fifo
out = ""


def step_fifo():
    tmp = pages[0]
    pages[0] = pages[1]
    pages[1] = pages[2]
    pages[2] = tmp


def get_first_smallest_not_frozen():
    minimum = 100
    minindex = -1
    for i in range(3):
        if not pages[i].frozen() and pages[i].lastUsed < minimum:
            minindex = i
            minimum = pages[i].lastUsed
    return minindex


def decrease_freeze():
    for j in range(3):
        if pages[j].frozen():
            pages[j].freeze_count -= 1


for i in range(len(inp)):
    a = abs(int(inp[i]))
    ind = -1
    tobreak = False
    for j in range(3):
        if pages[j].frame == a:
            pages[j].freeze_count = 0
            pages[j].lastUsed = i
            out += "-"
            tobreak = True
            decrease_freeze()
            break

    if tobreak:
        continue

    ind = get_first_smallest_not_frozen()
    if ind >= 0:
        pages[ind].frame = a
        pages[ind].freeze_count = 4
        pages[ind].lastUsed = i
        out += pages[ind].name
        pfs += 1
        step_fifo()
    else:
        out += "*"
        pfs += 1
    decrease_freeze()

print(out)
print(pfs)
