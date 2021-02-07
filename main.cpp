#include "cstring"
#include "iostream"
#include "stdlib.h"

using namespace std;
/*
최대 공약수와 최소공배수 


유클리드 호제법 예)
1071과 1029의 최대공약수를 구하면,
1071은 1029로 나누어떨어지지 않기 때문에, 1071을 1029로 나눈 나머지를 구한다. ≫ 42
1029는 42로 나누어떨어지지 않기 때문에, 1029를 42로 나눈 나머지를 구한다. ≫ 21
42는 21로 나누어떨어진다.
따라서, 최대공약수는 21이다.



https://www.acmicpc.net/problem/2609




*/

int uclid(int a, int b)
{
    int v1,v2,remain;

    if(a > b)
    {
        v1 = a;
        v2 = b;
    } 
    else
    {
        v1 = b;
        v2 = a;
    } 
    if( (v1==0 || v2 == 0) ) return -1;   
    do
    {      
      remain = v1%v2;
      v1 = v2;
      v2 = remain;
    }    
    while(remain != 0);
    
    return v1;

}
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    int a=1,b=1,re1=1,re2=1;
    scanf("%d %d", &a, &b);
    re1 = uclid(a,b);
    if(re1 > 0 ) re2 = a*b/re1;
    cout << re1 <<'\n';
    cout << re2 <<'\n';
    return 0 ;
}


