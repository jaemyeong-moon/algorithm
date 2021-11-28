// https://programmers.co.kr/learn/courses/30/lessons/43162
class Solution {
    public int solution(int n, int[][] computers) {
        int answer = 0;
        boolean check[] = new boolean[n];
        for(int i = 0 ; i < n ; i++){
            if(check[i]) continue;
            if(network(n, computers, check, i)) answer++;
        }
        return answer;
    }
    public boolean network(int n, int[][] computers, boolean check[], int pos ){
        boolean ret = false;
        for(int i = 0; i < n ; i++){
            if(!check[i] && computers[pos][i] == 1) {
                check[i] = ret = true;
                if(pos != i)
                    network(n, computers, check, i);
            }
        }
        return ret;
    }
    
    
}