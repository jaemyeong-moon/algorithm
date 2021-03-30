#include "cstring"
#include "iostream"
#include "stdlib.h"
#include "queue"
using namespace std;
/*

https://www.acmicpc.net/problem/2839

상근이는 요즘 설탕공장에서 설탕을 배달하고 있다. 상근이는 지금 사탕가게에 설탕을 정확하게 N킬로그램을 배달해야 한다. 설탕공장에서 만드는 설탕은 봉지에 담겨져 있다. 봉지는 3킬로그램 봉지와 5킬로그램 봉지가 있다.

상근이는 귀찮기 때문에, 최대한 적은 봉지를 들고 가려고 한다. 예를 들어, 18킬로그램 설탕을 배달해야 할 때, 3킬로그램 봉지 6개를 가져가도 되지만, 5킬로그램 3개와 3킬로그램 1개를 배달하면, 더 적은 개수의 봉지를 배달할 수 있다.

상근이가 설탕을 정확하게 N킬로그램 배달해야 할 때, 봉지 몇 개를 가져가면 되는지 그 수를 구하는 프로그램을 작성하시오.
*/
int a;

int calculate(int v)
{
    if(v < 3 || v > 5000) {
       
       return -1;
   }
   //3a + 5b = v
   //b가 가장 큰 경우를 구하라.
   int start = v / 5;
   int left;
   int i; // 5키로짜리 갯수
   for(i = start ; i > -1 ; i-- )
   {
       left = v - 5*i;
       if(left % 3 == 0 ) break;
   }
   if(i < 0 ) return i;
   return i + (left/3);


}
int main()
{   
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    scanf("%d", &a);
    int re = calculate(a);
    
    cout << re << endl;
    

}