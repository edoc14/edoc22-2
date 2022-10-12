import java.io.*;
import java.util.*;

public class BOJ_13565 {
    static int M, N;	// 격자 크기 M, N
    static int[] dr = {-1, 0, 1, 0};	// 행 이동
    static int[] dc = {0, -1, 0, 1};	// 열 이동
    static int[][] map;		// 격자 저장
    static boolean[][] visited;	// 방문 여부 체크
    static boolean flag = false;// 전류 잘 전달되는지 저장
    
    static void solve(int r, int c) {
        visited[r][c] = true;	// 방문했음을 저장
        
        if (r == M - 1) {
            flag = true;	// 전류 잘 전달됨 체크
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];	// 행 이동
            int nc = c + dc[i];	// 열 이동
            
            if (nr < 0 || nc < 0 || nr >= M || nc >= N) continue;
            if (visited[nr][nc]) continue;
            if (map[nr][nc] == 1) continue;
            solve(nr, nc);
        }
    }
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        M = Integer.parseInt(st.nextToken());	// 격자 크기 M
        N = Integer.parseInt(st.nextToken());	// 격자 크기 N
        map = new int[M][N];			// 격자 저장
        visited = new boolean[M][N];	// 방문 여부 체크
        
        for (int i = 0; i < M; i++) {
            String str = br.readLine();
            
            for (int j = 0; j < N; j ++) {
                map[i][j] = str.charAt(j)-'0';	// 입력을 map 배열에 저장
            }
        }
        
        for (int i = 0; i < N; i++) {
            if (map[0][i] == 0) {	// 전류가 잘 통하면
                solve(0, i);
            }
        }
        System.out.println(flag ? "YES" : "NO"); // 전류 잘 전달되면 YES 출력
    }
}