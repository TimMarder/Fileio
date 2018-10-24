#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    int file1;
    char *stuff1 = (char *)malloc(360); //will hold contents of file1

    printf("Opening file1...\n");
    file1 = open("read.txt", O_RDONLY); //opening read.txt in read-only mode
    printf("Reading file1...\n");
    read(file1, stuff1, 360); //putting contents of file1 into stuff1
    printf("Showing contents...\n");
    printf("%s\n", stuff1); //printing the contents of file1

    close(file1); //closing file1

    int file2;
    char *stuff2 = (char *)malloc(360); //will hold contents of file2

    printf("Opening file2...\n");
    file2 = open("edit.txt", O_RDWR); //opening edit.txt in read/write mode
    printf("Writing into file2...\n");
    write(file2, stuff1, 360); //copying contents of file1 into file2
    printf("Copied contents of file1 into file2.\n");
    strcpy(stuff2, stuff1);

    printf("Reading file2...\n");
    read(file2, stuff2, 360); //putting contents from file1 into stuff2 variable
    printf("Showing contents...\n");
    printf("%s\n", stuff2); //printing the contents of file2

    close(file2); //closing file2
    fclose(fopen("edit.txt", "w")); //clears edit.txt for multiple tests
    return 0;

}
