#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ARR 10000000
#define MAX_ARR1 5000

void print(FILE* ,int*);
void failarr();

char arr[MAX_ARR];
char arr1[MAX_ARR1];
int failure[MAX_ARR1];
int lens = 0;
int lenp = 0;


int main()
{
    FILE* fpString = fopen("string.txt","r");
    FILE* fpArray = fopen("pattern.txt","r");
    FILE* fpResult = fopen("result_kmp.txt","w");

    if(!fpString){
        printf("The String file does not exist.\n");
        return 0;
    }
    if(!fpArray){
        printf("The Pattern file does not exist.\n");
        return 0;
    }
    fgets(arr,MAX_ARR,fpString);
    fgets(arr1,MAX_ARR1,fpArray);

    lens = strlen(arr);
    lenp = strlen(arr1);

    failarr();

 printf("\n");
    int i = 0, j = 0;
    int index = 0;
    int* printarr = (int*)malloc(sizeof(int));
    *printarr = 0;

    while(i<lens){
        if(arr[i] == arr1[j]){
            i++;
            j++;
        }
        else if(j==0)
            i++;
        else
            j = failure[j-1] + 1;
    if(j==lenp){
        index++;
        (*printarr)++;
        printarr = (int*)realloc(printarr,(index+1)*sizeof(int));
        printarr[index] = i-lenp;
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
    if(fpResult != NULL){
        fprintf(fpResult,"%d\n",printarr[0]);
    for(int i = 1; i <= printarr[0]; i++)
        fprintf(fpResult,"%d ",printarr[i]);
    }
    fprintf(fpResult,"\n");
    printf("Saved on result_kmp.txt\n");
}
//kmp - failfunc
void failarr(){
/* compute pattern's failure function */
 int i, j =0;
failure[0] = -1;

for(j=1; j<lenp; j++) {
 i = failure[j-1];
while((arr1[j] != arr1[i+1]) && (i >= 0)) i = failure[i];
if(arr1[j] == arr1[i+1]) failure[j] = i+1;
    else failure[j] = -1;
 }
}
