import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main1720 {

	static int N;
	static int[] dp = new int[31]; // 좌우대칭 고려안한 전체개수 저장할 배열
	static int[][] dp2 = new int[31][31]; // 좌우대칭 경우의 수 저장할 배열

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		N = Integer.parseInt(br.readLine());

		dp[1] = 1; // n=1일때 경우의 수는 1
		dp[2] = 3; // n=2일때 경우의 수는 3
		for (int i = 3; i <= N; i++) {
			dp[i] = dp[i - 1] + dp[i - 2] * 2;
		} // n=i일때 경우의 수

		if (N % 2 == 0) { // N이 짝수일 때
			dp2[N / 2][N / 2 + 1] = 3; // 가운데 2*2칸의 경우의 수는 3
			dp2[N / 2 - 1][N / 2 + 2] = 5; // 가운데 4*2칸의 경우의 수는 5

			int i = N / 2 - 2;
			int j = N / 2 + 3;
			while (i >= 1 && j <= N) {
				dp2[i][j] = dp2[i + 1][j - 1] + dp2[i + 2][j - 2] * 2;
				i--;
				j++;
			}
		} else { // N이 홀수일 때
			dp2[N / 2 + 1][N / 2 + 1] = 1; // 가운데 1*2칸의 경우의 수는 3
			dp2[N / 2][N / 2 + 2] = 1; // 가운데 3*2칸의 경우의 수는 5

			int i = N / 2 - 1;
			int j = N / 2 + 3;
			while (i >= 1 && j <= N) {
				dp2[i][j] = dp2[i + 1][j - 1] + dp2[i + 2][j - 2] * 2;
				i--;
				j++;
			}
		}
		int result = (dp[N] - dp2[1][N]) / 2 + dp2[1][N];

		bw.write(result + "\n");
		bw.flush();
	}

}
