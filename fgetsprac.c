#include <stdio.h>

int main()
{
    FILE* pFile = fopen("fgetsprac.txt","r");

    char arr[100];

    char* pChar = fgets(arr,100,pFile);
    printf("fgets return : %s\n", pChar);
    printf("fgets 1sr arg : %s",arr);

    fclose(pFile);
    return 0;
}