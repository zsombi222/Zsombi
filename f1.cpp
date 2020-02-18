// _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char myid[] = "A'rvai Zsombor,1MI,2,L2 <arvaizsombor@gmail.com> VC2WTQ\n";
char mytask[] = "Feladat = 1\n";

int main()
{
	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid);
	printf(mytask);
	printf("Program\n");
	char ch;
	while ((ch = getchar()) != EOF)
		putchar(ch);                      // ch-ban van a következõ karakter
	return 0;
}