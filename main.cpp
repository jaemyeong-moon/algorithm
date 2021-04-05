#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

/*
https://www.acmicpc.net/problem/1202

보석넣기 문제

priority_queue 사용 

priority_queue 는 기본적으로 오름차순.
priority_queue<int, vector<int>, (비교함수)greater<int> > 를쓰면 오름차순/내림차순 설정가능 

sort 사용

sort(int*, int* + N) = 포인터부터 N개만큼 정렬
sort(vector.begin(), vector.begin() + N) = 포인터부터 N개만큼 정렬



sort(vector.begin(), vector.end()) 
sort(vector.begin(), vector.end(), 함수를 만들어서 넣는다. 앞에 인자에 대하여 ) 
int A[100]
ex) sort(A,A+100,desc)
bool desc(int a, int b){ return a > b ;} 내림차순 시.


greater<>()



*/

int N,K;
int bag[300000]; //각 가방 무게
// int jewelry[300000][2]; // M / V 

vector<pair<int, int> > jewelry;
priority_queue<int> pq;
int main()
{
    cin >> N;
    cin >> K;

    for(int i = 0 ; i < N ; i++)
    {
        int m,v;        
        // cin >> jewelry[i][0];
        // cin >> jewelry[i][1];
        cin >> m;
        cin >> v;
        jewelry.push_back(make_pair(m,v));
    }
    for(int i = 0 ; i < K; i++)
        cin >> bag[i];

        
    // sort(jewelry.begin(),jewelry.end());
    sort(jewelry.begin(),jewelry.end(), greater<>());
    
    sort(bag, bag + K );

    long long sum = 0;
    int idx = 0;
    for(int i = 0 ; i < K  ; i++ ) // K 개의 가방에 담아야하고,
    {
        // 가방에 담을 수 있는 주얼리를 pq에 넣는다.
        while( idx < N && jewelry[idx].first <= bag[i] )
            pq.push(jewelry[idx++].second);
        if( !pq.empty() ) //pq가 비어있찌 않으면
        {
            sum += pq.top();  //가장 비싼놈을 꺼내서 합한다.
            pq.pop();
        }        
    } 

    cout << sum << '\n';

    return 0;
}
