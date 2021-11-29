#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FNEV "adat.dat"
#define FNEV2 "adat.txt"
//#define FNEV "main.c"

int main()
{
	char k = 0x23, kt[] = "EXXER! yes.", kk;
	int y, x = 10+10*256, xt[] = {2,3,5,7,10,13,17,20}, xx;
    //MAGASSZINTŰ FÁJLKEZELÉS
    FILE *fp, *fp2;
    //Megnyitás
	fp = fopen(FNEV, "r");
	//Bezárás, puffer ürítés
	fclose(fp);
	//Létezés ellenőrzése
	if (fp == NULL) {
		printf("nincs\n");
	} else {
		printf("van\n");
		fp = fopen(FNEV, "wb"); //b: nem szöveges, bináris
		//y = fileno(fp); //Alacsony szintű fájlazonosító visszanyerése
		y = fwrite(xt,sizeof(xt),1,fp);
		/*
		1. adat címe
		2. adat mérete
		3. szorzó (mérethez) - kiírandó blokkok száma
		4. file struct pointer

		visszatér: kiírt blokkok száma (3. paraméter visszajön)
		*/

		fflush(fp);
		fclose(fp);

		fp = fopen(FNEV, "r+b");
		while(fread(&xx, sizeof(xx), 1, fp)) {
			printf("%10i", xx);
			if (!(xx % 2)) {
				xx /= 2;
				fseek(fp, -sizeof(xx), SEEK_CUR);
				fwrite(&xx, sizeof(xx), 1, fp);
				fflush(fp);
			}
			printf("%10i\n", xx);
		}
		printf("\n");
		fclose(fp);
	}

	printf("fp: %p\n", fp);
	printf("y: %i\n", y);
	printf("k: %i\n", k);

	//printf fájlba

	fp2 = fopen(FNEV2, "w+");

	int i;
	for(i = 0; i < sizeof(xt) / sizeof(xt[0]); i++) {
		fprintf(fp2, "%i\n", xt[i]);
	}

	fflush(fp);
	fclose(fp);

	//formátumozott olvasás

	fp2 = fopen(FNEV2, "r");

	while(1) {
		if (fscanf(fp, "%i", &xx) < 0) break;
		printf("O: %10i\n", xx);
	}

	fflush(fp);
	fclose(fp);
    return 0;
}
