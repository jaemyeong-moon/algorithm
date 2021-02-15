#include "cstring"
#include "iostream"
#include "stdlib.h"
#include "queue"
using namespace std;
/*
N×M크기의 배열로 표현되는 미로가 있다.

1	0	1	1	1	1
1	0	1	0	1	0
1	0	1	0	1	1
1	1	1	0	1	1
미로에서 1은 이동할 수 있는 칸을 나타내고, 0은 이동할 수 없는 칸을 나타낸다. 이러한 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동할 때 지나야 하는 최소의 칸 수를 구하는 프로그램을 작성하시오. 한 칸에서 다른 칸으로 이동할 때, 서로 인접한 칸으로만 이동할 수 있다.

위의 예에서는 15칸을 지나야 (N, M)의 위치로 이동할 수 있다. 칸을 셀 때에는 시작 위치와 도착 위치도 포함한다.

입력
첫째 줄에 두 정수 N, M(2 ≤ N, M ≤ 100)이 주어진다. 다음 N개의 줄에는 M개의 정수로 미로가 주어진다. 각각의 수들은 붙어서 입력으로 주어진다.

출력
첫째 줄에 지나야 하는 최소의 칸 수를 출력한다. 항상 도착위치로 이동할 수 있는 경우만 입력으로 주어진다.

예제 입력 1 
4 6
101111
101010
101011
111011
예제 출력 1 
15

https://www.acmicpc.net/problem/2178

예전에 자바로 제출한적 있음. 
*/
int a=0, b=0;
int arr[100][100];
bool tracker[100][100];
int X[]= {1,0,-1,0};
int Y[]= {0,1,0,-1};

struct point
{
    int x;
    int y;
    int depth;
};

struct point p;

struct point Point(int x,int y, int d)
{
    p.x =x;
    p.y = y;
    p.depth = d;
    return p;
}

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
    scanf("%d %d", &a, &b);
    queue<struct point> q;
    p.x = p.y = p.depth = 0;  
    for(int i = 0; i < a; i++)
    {   char str[101];             
        scanf("%s",str);       
        for(int z = 0; z < b ; z++)
        {
            arr[i][z] = str[z] - '0';        
            tracker[i][z] = false;
        }
    }   
    q.push(Point(0,0,1));     
    int prv_x,prv_y;
    while(!q.empty())
    {
        struct point p = q.front();
		q.pop();
        if(p.x == a-1 && p.y == b-1)
        {
            printf("%d\n",p.depth);
			break;
        }
        for(int i = 0; i < 4; i++) //4방향으로 갈수있는 경우를 게산.
        {    
            int x = p.x+X[i];
            int y = p.y+Y[i];        
            if(x>=0 && x<a && y >=0 && y <b && tracker[x][y] == false && arr[x][y] == 1 )
            {                
                q.push(Point(x,y,p.depth+1));  
                tracker[x][y] = true;
            }           
        }
    }
    return 0 ;
}