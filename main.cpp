#include "cstring"
#include "iostream"
#include "stdlib.h"


/* 기준을 잡아서, 기준 앞에는 오름차순, 기준 뒤에는 내림차순. */
bool next_permutation(int *arr, int n)
{
    int i = n-1;
    while(i > 0 && arr[i-1] >= arr[i]) --i; //Find Pivot
    if(i == 0) return false;

    int j = n-1;
    while(arr[i-1] >= arr[j]) --j;

    int tmp = arr[i-1];
    arr[i-1] = arr[j];
    arr[j] = tmp;
    int k = n-1;
    while(i < k)
    {
        tmp = arr[i];
        arr[i] = arr[k];
        arr[k] = tmp;
        i++; 
        k--;
    }
    return true;
}
void exec_1(int argc, char** argv)
{
    int n = atoi(argv[1]);
    int* arr = NULL;
    arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0 ; i < n ; i++) arr[i] = i+1;

    do
    {
        for(int i = 0 ; i < n ; i++)
            printf("%d ",arr[i]);
        printf("\r\n");
    } while (next_permutation(arr,n));

}
int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    int* arr = NULL;
    arr = (int*)malloc(sizeof(int)*n);
    for(int i = 0 ; i < n ; i++) arr[i] = i+1;

    do
    {
        for(int i = 0 ; i < n ; i++)
            printf("%d ",arr[i]);
        printf("\r\n");
    } while (next_permutation(arr,n));
    

    return 0 ;
}

