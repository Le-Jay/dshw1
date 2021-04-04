#include <stdio.h>

int main()
{
    int index[100];
    int num = 0;
    int i = 0;
    int j = 0;

    FILE* fpString = fopen("string.txt","r");
    FILE* fpArray = fopen("pattern.txt","r");
    char arr[1000];
    char arr1[1000];

    char* pString = fgets(arr,100,fpString);
    char *pArray = fgets(arr1, 100, fpArray);
    while(1){
        if(arr[i]==arr1[i]){
            num++;
            index[j] = i;
            j++;
    }
    printf("num: %d\n",num);
    for(i=0;i<j;i++)
        printf("%d ",index[i]);


    fclose(pString);
    fclose(pArray);
    return 0;
}