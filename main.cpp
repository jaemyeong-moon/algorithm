#include "cstring"
#include "iostream"
#include "stdlib.h"
#include "queue"
using namespace std;
typedef unsigned long long UINT64;
#define MAX(a,b) a>b ? a : b
#define MIN(a,b) a<b ? a : b

/*

https://www.acmicpc.net/problem/15953

카카오 페스티벌 예선 문제 1
*/

UINT64 a,b;
int pow(UINT64 a, UINT64 b)
{
    if(b == 0) return 1;
    return a*pow(a,b-1);
}
int main()
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);     
    scanf("%lld %lld", &a, &b);
    

    UINT64 max = MAX(a,b);
    UINT64 min = MIN(a,b);
    UINT64 temp;
    
    while( (max = max % min) != 0)
    {
        if(max < min)
        {
            temp = max;
            max = min;
            min = temp;
        }
    }

    if( min > 10000000) min = 10000000;
    for(int i = 0 ; i < min ; i++)
    {
        printf("1");
    }
    



     
}