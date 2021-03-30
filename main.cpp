#include "cstring"
#include "iostream"
#include "stdlib.h"
#include "queue"
using namespace std;
/*

https://www.acmicpc.net/problem/15953

카카오 페스티벌 예선 문제 1
*/
int _2017[100] = {0,5000000,3000000,2000000,500000,300000,100000};
int _2018[100] = {0,5120000,2560000,1280000,640000,320000};
int result[1000] = {0,};
int a,b;
int pow(int a, int b)
{
    if(b == 0) return 1;
    return a*pow(a,b-1);
}
int main()
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int T = 0;;
    scanf("%d",&T);
    if(T < 0 || T > 1000) return -1;
    for(int i = 0 ; i < T ; i++)
    {
        scanf("%d %d", &a, &b);
        if(a < 1 || a > 100 ) a = 0 ;
        else if( b < 1 || b > 64) b = 0;
        int rank1 = 0, rank2 = 0;
        
        for(int j = 1 ; a > 0 ; j++)
        {
            if( (a = a - j) < 1 ) 
            {
                rank1 = j;
                break;
            }
        }
        for(int j = 1 ; b > 0 ; j++)
        {
            if( (b = b - pow(2,j-1)) < 1 )
            {
                rank2 = j;
                break;
            } 
        }        
        result[i] = _2017[rank1]+_2018[rank2];
    }
    for(int i = 0 ; i < T; i++)
    {
       cout << result[i] << '\n';
    }
}