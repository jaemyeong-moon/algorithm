#include "cstring"
#include "iostream"
#include "stdlib.h"
#include "queue"
using namespace std;

/*

https://www.acmicpc.net/problem/10451

순열 사이클
*/
#include <iostream>

#include <cstring>

using namespace std;

const int MAX = 1000 + 1;

int N;
int arr[MAX];
bool visited[MAX];
void DFS(int node)
{
    visited[node] = true;
    if (!visited[arr[node]])
        DFS(arr[node]);
}

int main(void)
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin >> T;
    for (int t = 0; t < T; t++)
    {
        memset(visited, false, sizeof(visited));
        cin >> N;

        for (int i = 1; i <= N; i++)
            cin >> arr[i];
        int cnt = 0;
        for (int i = 1; i <= N; i++)
            //컴포넌트 개수
            if (!visited[i])
            {
                DFS(i);
                cnt++;
            }
        cout << cnt << "\n";
    }

    return 0;
}
