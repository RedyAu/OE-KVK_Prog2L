#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

#define FNEV "adat.dat"

int main()
{
	char k[] = "Hip\nHipi!";
	short int si = 100+10*256, st[] = {2,3,5,7,11,13,17,19,23,29,31};

	//Fájl létezik-e?
	int fh, y, yy;
	fh = open(FNEV, O_RDONLY);
	printf("fh: %i\n%s ilyen fajl.\n", fh, ((fh < 0) ? "nincs" : "van"));
	//Ha van: stdin stdout stderr után: 3
	//Ha nincs: -1

	//Fájl létrehozása (olvashato)
	fh = open(FNEV, O_CREAT | O_RDWR | O_BINARY | O_TRUNC, S_IREAD | S_IWRITE);
	//BINARY tag: ne szövegként legyen kezelve
	//TRUNC: Kitörli a meglévő tartalmat
	//APPEND: Lehet folytatni
	printf("fh: %i\n%s ilyen fajl.\n", fh, ((fh < 0) ? "nincs" : "van"));

	//Fájlba írás
	y = write(fh, st, sizeof(st)); //Visszatérési érték: Kiírt byteok száma
	//y = y + write(fh, &k, sizeof(k)); //y-ban a teljes kiírt adatmennyiség lesz
	printf("y: %i\n\n---\n\n", y);

	//Bezárás - mindig kell
	close(fh);

	///////////////////////////////

	//Megnyitás olvasásra
	fh = open(FNEV, O_RDWR | O_BINARY);

	//Olvasás elemenként
	while(read(fh, &si, sizeof(si))) {
		if (!(si % 5)) {
			si *= 2;
			lseek(fh, -sizeof(si), SEEK_CUR);
			write(fh, &si, sizeof(si));
		}
		printf("%10i", si);
	}

	printf("\nsi: %i\n", si);
	printf("yy: %i\n", yy);
	printf("fh: %i\n", fh);

	close(fh);
    return 0;
}
