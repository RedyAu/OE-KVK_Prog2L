#include <stdio.h>
#include <stdlib.h>

#define StringsNum 10
#define StringsLen 50

int szamjegyekOsszege(int);

int main()
{
    int szam = 15932;
    int i, j, longest = -1, longestLength = 0;
    char strings[StringsNum][StringsLen] =
        {"Lorem",
        "ipsum",
        "dolor sit",
        "amet, explicit",
        "avec sum trio oum.",
        "indeed yes, very much",
        "much text",
        "very very long, meaningless sentence",
        "a",
        "b"};
        
    for (i = 0; i < StringsNum; i++)
    {
        j = 0;
        while (strings[i][j]) {
            j++;
        }
        if (j > longestLength) {
            longestLength = j;
            longest = i;
        }
    }

    printf("%d szamjegyeinek osszege: %d\nA leghosszabb string a tombben a %d., igy szol:\n%s", szam, szamjegyekOsszege(szam), longest + 1, (longest == -1) ? "hiba" : strings[longest]);
}

int szamjegyekOsszege(int szam)
{
    int sum = 0;
    do
    {
        sum += szam % 10;
        szam /= 10;
    } while (szam);

    return sum;
}