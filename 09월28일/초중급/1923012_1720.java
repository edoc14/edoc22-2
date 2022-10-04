import java.util.Scanner;

public class Main {
	private static long dp[]; 
	private static long sym[];

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		int n = scanner.nextInt();
		//문제에서 정한 N의 최댓값에 맞추어 배열의 길이 설정
		dp = new long[31];
		sym = new long[31];
		
		
		System.out.println(tile_code(n));
	}
	private static long tile_code(int n) {
		return (tile(n)-symmetry(n))/2 + symmetry(n);
	}
	//모든 타일
	private static long tile(int n) {
		if(dp[n] != 0)
			return dp[n];
		if(n == 1)
			return dp[1] = 1;
		if(n == 2)
			return dp[2] = 3;
		
		//점화식
		dp[n] = tile(n-1) + 2*tile(n-2);
		
		
		return dp[n];
	}
	//좌우대칭인 경우를 조건문으로 처리
	private static long symmetry(int n) {
		if(sym[n] != 0)
			return sym[n];
		if(n == 1) 
			return sym[1] = 1;
		if(n == 2)
			return sym[2] = 3;
		if(n == 3)
			return sym[3] = 1;
		if(n == 4)
			return sym[4] = 5; 
		
		return sym[n] = symmetry(n-2) + 2*symmetry(n-4);
	}

}


