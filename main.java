//https://programmers.co.kr/learn/courses/30/lessons/43165
class Solution {
    int answer = 0;
    public int solution(int[] numbers, int target) {
        dfs(numbers, target, 0, 0);
        return answer;
    }
    public void dfs(int[] numbers, int target, int sum, int pos){
        if(numbers.length == pos){
            if(sum == target) answer++;
            return ;
        }
        
        sum += numbers[pos];
        dfs(numbers, target, sum, pos+1);
        sum -= numbers[pos] ;
        
        sum += numbers[pos]*(-1);
        dfs(numbers, target, sum, pos+1);
    }
}