#include <iostream>
#include <iomanip>
#include <cmath> //cématek inklúd

double f(double x) {
	if (x > 7) {
		return (x / 113.90);
	}
	else {
		return (pow(x, 4) * 0.444 - pow(x, 3) * 0.889 + pow(x, 2) * 56.88 + 7 * x - 7);
	}

}

char myid[] = "A'rvai Zsombor,1MI,2,L2 <arvaizsombor@gmail.com> VC2WTQ\n";
char mytask[] = "Feladat = 2\n";

int main(void) {

	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid);
	printf(mytask);
	printf("program\n");



	double d;
	while(std::cin >> d)
		std::cout << std::fixed << std::setprecision(4) << f(d) << std::endl;
	
	return 0;
}
