/* https://www.acmicpc.net/problem/15486 */
import java.util.*;
class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String enter = sc.next();
        int N = Integer.parseInt(enter);
        int T[] = new int[N+2];
        int P[] = new int[N+2];
        int dp[] = new int[N+2];
        
        
        for(int i = 1; i <= N ; i++){
            enter = sc.next();
            T[i] = Integer.parseInt(enter);
            enter = sc.next();
            P[i] = Integer.parseInt(enter);
        }
        for(int i = N; i >= 1 ; i--){
            if((i-1)+T[i] > N){
                dp[i] = dp[i+1];
            }
            else{
                dp[i] = dp[i+1] > P[i] + dp[i + T[i]] ? dp[i+1] : P[i] + dp[i + T[i]];
            }
        }
        System.out.println(dp[1]);
    }
}