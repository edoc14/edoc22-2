import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class BOJ_1720 {

	static int N;
	static int[] dp = new int[31];
	static int[][] dp2 = new int[31][31];
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		N = Integer.parseInt(br.readLine());
		dp[1] = 1;
		dp[2] = 3;
		for (int i = 3; i <= N; i++) {
			dp[i] = dp[i- 1] + dp[i -2] * 2;
		}

		if (N % 2 == 0) {  // N이 짝수일 때
			//가장 가운데 두칸짜리로부터 좌우로 구간 넓히기
			dp2[N / 2][N / 2 + 1] = 3;
			dp2[N / 2 - 1][N / 2 + 2] = 5;
			
			int i = N/2 -2;
			int j = N/2 +3;
			while (i >= 1 && j <= N) {
				dp2[i][j] = dp2[i+1][j -1] + dp2[i + 2][j - 2] * 2;
				i--;
				j++;
			}
		}
		else {  // N이 홀수일 때
			//가장 가운데의 한칸짜리로부터 좌우 구간 넓히기
			dp2[(N/2) + 1][(N/2) + 1] = 1;
			dp2[N/2][(N/2) + 2] = 1;
			int i = (N/2) - 1;
			int j = (N/2) + 3;
			while (i >= 1 && j <= N) {
				dp2[i][j] = dp2[i + 1][j -1] + dp2[i + 2][j -2]* 2;
				i--;
				j++;
			}
		}

		int res = (dp[N] - dp2[1][N]) / 2 + dp2[1][N];

		bw.write(res + "\n");
		bw.flush();
	}

}
