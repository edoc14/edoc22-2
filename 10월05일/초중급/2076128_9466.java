import java.io.*;
import java.util.StringTokenizer;

public class 2076128_9466 {
	public static int[] stu;
	public static int[] visited;	// �ʱⰪ false.
	public static int[] cyc;
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		while(T != 0) {
			int n = Integer.parseInt(br.readLine());
			stu = new int[n + 1];
			visited = new int[n + 1];
			cyc = new int[n + 1];
			
			st = new StringTokenizer(br.readLine());
			for(int i = 1; i <= n; i++) 
				stu[i] = Integer.parseInt(st.nextToken());
			
			int cnt = 0;
			for(int i = 1; i <= n; i++) {
				if(visited[i] != 0) continue;
				if(visited[stu[i]] == 0) 
					cnt += dfs(i, i, 1);
			}
			bw.write((n - cnt) + "\n");			
			T--;
		}
		bw.flush();
		bw.close();
	}
	
	public static int dfs(int s, int num, int h) {
		visited[num] = h;
		cyc[num] = s;
		
		int next = stu[num];
		
		if(visited[next] != 0 && s == cyc[next]) 
			return h - visited[next] + 1;
		else if(visited[next] != 0 && s != cyc[next]) 
			return 0;
		return dfs(s,next, h + 1);
	}
}
