#include <stdio.h>
#include <stdlib.h>

#define SOR 3
#define OSZLOP 5

int main()
{
    int tomb[SOR][OSZLOP] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}};
    int i, j, k, l, m;

    //Feltolt 1
    /*
for (i = 0; i < SOR; i++) {
for (j = 0; j < OSZLOP; j++) {
switch (i) {
case 0:
tomb[i][j] = 10 + (j * 2);
break;
case 1:
tomb[i][j] = 100 + (j * 3);
break;
default:
tomb[i][j] = 1000 + (j * 5);
break;
}
}
}
*/
    //Feltolt 2
    k = 100;
    for (i = SOR - 1; i >= 0; i--)
    {
        for (j = OSZLOP - 1; j >= 0; j--)
        {
            tomb[i][j] = k++;
        }
    }
    int maxsum = 0;
    //Print
    for (i = 0; i < SOR; i++)
    {
        for (j = 0; j < OSZLOP; j++)
        {
            printf("%12d", tomb[i][j]);
            //Maxkereses
            k = tomb[i][j];
            l = k % 10 + k % 100 / 10 + k % 1000 / 100;
            if (maxsum < l)
                maxsum = l, m = k;
        }
        printf("\n");
    }

    printf("Legnagyobb szamjegyek osszege: %d\nEz a szam: %d", maxsum, m);

    return 0;
}