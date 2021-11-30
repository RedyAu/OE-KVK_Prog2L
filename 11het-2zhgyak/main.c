#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

int intBinaryToFile(int szam, char* fnev);
int intTextToFile(int szam, char* fnev);
int intListToBinary(int* list, int size, char* fnev);
int printBinaryIntContent(char* fnev);

int main() {
    int i = 123;
    int list[] = {1,2,3,4,5,6,7,8,9};
    intBinaryToFile(i, "intbinary.bin");
    intTextToFile(i, "inttext.txt");
    intListToBinary(list, sizeof(list), "intList.bin");
    printBinaryIntContent("intList.bin");
}

int printBinaryIntContent(char* fnev) {
    //to be continued
}

int intListToBinary(int* list, int size, char* fnev) {
    int fileAz;
    fileAz = open(fnev, O_CREAT | O_RDWR | O_TRUNC | O_BINARY, S_IREAD | S_IWRITE);

    int y = write(fileAz, &list, size);
    printf("fileAz = %i\n binary printed %i bytes.\n\n", fileAz, y);
    close(fileAz);
}

int intBinaryToFile(int szam, char* fnev) {
    int fileAz;
    fileAz = open(fnev, O_CREAT | O_RDWR | O_BINARY | O_TRUNC, S_IREAD | S_IWRITE);
    int y = write(fileAz, &szam, sizeof(int));
    printf("fileAz = %i\n binary printed %i bytes.\n\n", fileAz, y);
    close(fileAz);
}

int intTextToFile(int szam, char* fnev) {
    int fileAz;
    char content[15];
    fileAz = open(fnev, O_CREAT | O_RDWR | O_TRUNC, S_IREAD | S_IWRITE);

    sprintf(content, "%i", szam);
    int y = write(fileAz, content, sizeof(content));
    printf("fileAz = %i\n text printed %i bytes.\n\n", fileAz, y);
    close(fileAz);
}