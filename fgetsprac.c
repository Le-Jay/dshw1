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
    for(i=0; i < ; i++){
        for(int k=0; k ; k++){
            if(arr[i]==arr1[k]){
                index[j]=i; //일치 시작하는 부분의 인덱스(이따 출력용), 일치하는 개수는 이 출력하는 배열의 원소의개수
                i++;
            }
            //pattern의 index k가 끝에 닿으면 다시 0으로
        }
    }
    printf("num: %d\n",num);
    for(i=0;i<j;i++)
        printf("%d ",index[i]);


    fclose(pString);
    fclose(pArray);
    return 0;
}