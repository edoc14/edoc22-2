import java.io.*;
import java.util.StringTokenizer;

public class 2076128_13565 {
	public static int N, M;
	public static int[][] fib;
	public static int[][] xy = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
	public static boolean[][] vis;
	public static boolean res;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		fib = new int[N][M];
		vis = new boolean[N][M];
		
		for(int i = 0; i < N; i++) {
			char[] str = br.readLine().toCharArray();
			for(int j = 0; j < M; j++) {
				fib[i][j] = str[j] - '0';
			}
		}
		
		for(int i = 0; i < M; i++) {
			if(fib[0][i] == 0) dfs(0, i);
		}
		
		System.out.println(res ? "YES" : "NO");
	}
	
	public static void dfs(int r, int c) {
		vis[r][c] = true;
		
		if(r == N - 1 && fib[r][c] == 0) {
			res = true; 
			return;
		}
		
		for(int i = 0; i < xy.length; i++) {
			int nr = r + xy[i][0];
			int nc = c + xy[i][1];
			
			if(nr >= 0 && nc >= 0 && nr < N && nc < M && !vis[nr][nc] && fib[nr][nc] == 0)
                dfs(nr, nc);
		}
	}
}
