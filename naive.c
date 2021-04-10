#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR 10000000
#define MAX_ARR1 10000

char arr[MAX_ARR];
char arr1[MAX_ARR1];

void print(FILE*, int*);

int main()
{
    FILE* fpString = fopen("string.txt","r");
    FILE* fpArray = fopen("pattern.txt","r");
    FILE* fpResult = fopen("result_naive.txt","w");

    if(!fpString){
        printf("The string file does not exist.\n");
        return 0;
    }
    if(!fpArray){
        printf("The Pattern file does not exist.\n");
        return 0;
    }

    fgets(arr,MAX_ARR,fpString);
    fgets(arr1,MAX_ARR1, fpArray);

    int i,j,start = 0;

    int* printarr = (int*)malloc(sizeof(int));
    *printarr = 0;
    int index = 0;
    int lasts = strlen(arr) - 1;
    int lastp = strlen(arr1) - 1;
    int endmatch = lastp;
    for(i=0 ; endmatch <= lasts ; endmatch++, start++){
        if(arr[endmatch] == arr1[lastp])
            for(j = 0, i = start ; j < lastp && arr[i] == arr1[j] ; i++, j++);
            if(j == lastp && (arr[endmatch] == arr1[lastp])){
                index++;
                printarr = (int*)realloc(printarr,(index +1) * sizeof(int));
                ++printarr[0];
                printarr[index] = start;
            }
    }

    print(fpResult,printarr);

    fclose(fpString);
    fclose(fpArray);
    fclose(fpResult);
    free(printarr);

    return 0;
}
void print(FILE *fpResult, int* printarr)
{
    fprintf(fpResult,"%d\n",printarr[0]);
    for(int i = 1; i <= printarr[0]; i++)
        fprintf(fpResult,"%d ",printarr[i]);
    fprintf(fpResult,"\n");
    printf("Saved on result_naive.txt\n");
}
