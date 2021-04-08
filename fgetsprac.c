#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{

    FILE* fpString = fopen("string.txt","r");
    FILE* fpArray = fopen("pattern.txt","r");
    char arr[1000];
    char arr1[1000];
    char* pString = fgets(arr,100,fpString);
    char *pArray = fgets(arr1, 100, fpArray);
    strstr(arr,arr1);
    nfind(arr,arr1);

    fclose(pString);
    fclose(pArray);
    return 0;
}
 //for(i=0 ; i<string[i+strlen(pArray)] ; i++)
int nfind(char *string, char *pat)
{
    int num = 0;
    int i,j,start = 0;
    int lasts = strlen(string) - 1;
    int lastp = strlen(pat) - 1;
    int endmatch = lastp;
    for(i=0 ; endmatch <= lasts ; endmatch++, start++){
        if(string[endmatch] == pat[lastp])
            for(j = 0, i = start ; j < lastp && string[i] == pat[j] ; i++, j++);
            if(j == lastp && (string[endmatch] == pat[lastp])){
                num++;
                printf("%d ",start);
            }
    }
    printf("\n%d",num);
}