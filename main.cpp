#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

/*
https://programmers.co.kr/learn/courses/30/lessons/72412

카카오 - 순위검색.

*/
vector<int> P[3][2][2][2]; //그룹화하는 벡터.

int getValue(string str)
{
    if(str == "cpp") return 0;
    if(str == "java") return 1;
    if(str == "python") return 2;
    if(str == "backend") return 0;
    if(str == "frontend") return 1;
    if(str == "junior") return 0;
    if(str == "senior") return 1;
    if(str == "chicken") return 0;
    if(str == "pizza") return 1;
    return -1;    
}
int get(vector<int> list, int score)
{
    int idx = lower_bound(list.begin(),list.end(),score) - list.begin();
    if(idx == list.size()) return 0;
    return list.size() - idx;       
}
int getResult(string query)
{
    vector<int> q;
    string str = "";
    for (int j = 0; j < query.length(); j++)
    {
        if (query[j] == ' ')
        {
            if(str != "and")
                q.push_back(getValue(str));
            str = "";            
        }
        else
            str += query[j];
    }
    int score = atoi(str.c_str());
    q.push_back(score);

    int ret = 0;
    for (int a = 0; a < 3; a++)
    {
        if (q[0] != -1 && q[0] != a)
            continue; //언어에 대하여, -1이면 a값을 모두 탐색한다. -1이 아니면, 맞는 언어만.
        for (int b = 0; b < 2; b++)
        {
            if (q[1] != -1 && q[1] != b)
                continue;
            for (int c = 0; c < 2; c++)
            {
                if (q[2] != -1 && q[2] != c)
                    continue;
                for (int d = 0; d < 2; d++)
                {
                    if (q[3] != -1 && q[3] != d)
                        continue;
                    ret += get(P[a][b][c][d], q[4]);              
                }
            }
        }        
    }
    return ret;
}


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i = 0 ; i < info.size() ; i++)
    {
        string str = "";
        vector<string> arr;
        for(int j = 0; j < info[i].length(); j++)
        {
            if(info[i][j] == ' ')
            {            
                arr.push_back(str);
                str = "";
            }
            else str+=info[i][j];
        }
        int it[4];
        for(int j = 0; j < arr.size() ; j++)
        {
            it[j] = getValue(arr[j]);
        }
        int score = atoi(str.c_str());
        
        P[it[0]][it[1]][it[2]][it[3]].push_back(score);        
    }
    for (int a = 0; a < 3; a++)
     for (int b = 0; b < 2; b++)
            for (int c = 0; c < 2; c++)
                for (int d = 0; d < 2; d++)
                    sort(P[a][b][c][d].begin(), P[a][b][c][d].end());


    for(int i = 0 ; i < query.size() ; i++)
    {
        int ret = getResult(query[i]);
        answer.push_back(ret);
    }
    
    return answer;
}
int main()
{
    vector<string> a = {"java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"};
    vector<string> b = {"java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"};
    solution(a,b);

    return 0;
}