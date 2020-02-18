#include <stdio.h>

char myid[] = "A'rvai Zsombor,1MI,2,L2 <arvaizsombor@gmail.com> VC2WTQ\n";
char mytask[] = "Feladat = 3\n";

int main()
{
	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid);
	printf(mytask);
	printf("Program\n");
	char ch;
	FILE* f = fopen("fel_3.txt","w");         //mostmár 3as feladat
	while ((ch = getchar()) != EOF)
		fputc(ch,f);                      // ch-ban van a következõ karakter
	fclose(f);
	return 0;
}
