#include <stdio.h>
#include <stdlib.h>

int fgv(char *tmb, char check);

int main()
{
    int a = 11, b = 223344556, c = 33, x = 0;
	unsigned char *ap, *bp, *cp;
	ap = &a;
	bp = &b;
	cp = &c;

    printf("a=%i, @:%p, *:%i\nb=%i, @:%p, *:%i\nc=%i, @:%p, *:%i\n", a, ap, *ap, b, bp, *bp, c, cp, *cp);

    //bp++;
    //printf("bp-t inkrementalva: %p adat: %i\n\n", bp, *bp);

    x = *bp;
    bp++;
    x = x + 0x100/*256*/ * *bp;
    bp++;
    x = x + 0x10000/*65536*/ * *bp;
    bp++;
    x = x + 0x1000000/*16777216*/ * *bp;

	printf("x: %d\n", x);

	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

	char tmb[] = {"Kando Kalman"}, check = 'a';
	char *pnt = tmb;
	int len = 0, i, dbK = 0;

	do {
		len++;
		dbK += (*pnt == check);
	}
	while(*pnt++);

	for (i = 0;*(tmb+i);i++);

	int kimenet = fgv("Kando Kalman", 'a');

	printf("\n\n---\n\nSzoveg: %s\nTombmeret: %d\nTomb hossza: %d\nHasznos hossz: %d\n'%c' szama: %d\n\n---\nFgv kimenete: %d\n", tmb, sizeof(tmb), len, i, check, dbK, kimenet);

    return 0;

    /*
    HF:
    - Egyik karaktert masikra cserelo fgv egy stringben (3 param)
	- Ket bemeneti tomb: A kettot osszerakja
    */
}

int fgv(char *tmb, char check) {
	int db = 0;

	do db += (*tmb == check);
	while(*tmb++);

	return db;
}
