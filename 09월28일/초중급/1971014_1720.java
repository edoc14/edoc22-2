import java.io.*;
import java.util.*;

public class BOJ_1720 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine()); // 타일 크기 N
		
		int[] dp=new int[31];
		dp[1]=1;
		dp[2]=3;
		for(int i=3;i<31;i++) {
			dp[i] = dp[i-1] + dp[i-2]*2;
		}
		
		int[] ans=new int[31];	// 결과 저장
		ans[1]=1;
		ans[2]=3;
		for(int i=3;i<31;i++) {	// 좌우대칭인 경우 고려
			if(i%2==0) {	// 짝수인 경우
				ans[i]=(dp[i] + dp[i/2] + dp[(i-2)/2]*2)/2;
			}
			else {	// 홀수인 경우
				ans[i]=(dp[i] + dp[(i-1)/2])/2;
			}
		}
		
		System.out.println(ans[N]);
	}
}
