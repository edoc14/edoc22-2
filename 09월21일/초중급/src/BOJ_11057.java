package edoc;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class BOJ_11057 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		int dp[][] = new int [N+1][10];  //N번째 자리수, 끝자리
		
		for(int i=0;i<10;i++) {
			dp[1][i] = 1;
		}

		for(int i=2;i<=N;i++) {
			for(int j=0;j<10;j++) {
				for(int w=0; w<=j;w++) {
					dp[i][j] += dp[i-1][w];
				}
				dp[i][j] %= 10007;
			}
		}
		
		int sum = 0;
		for(int i=0;i<10;i++) {
			sum += dp[N][i];
		}
		System.out.println(sum%10007);
		
		
	}

}
