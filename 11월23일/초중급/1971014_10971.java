import java.io.*;
import java.util.*;
public class BOJ_10971 {
	static int N, minCost;
	static int[][] W;
	static boolean[] check;
	
	public static void dfs(int start, int cur, int cost, int cnt) {
		if(cnt==N) {	// 모든 도시를 방문한 경우
			if(cur==start) {
				minCost=Math.min(cost+W[cur][start], minCost); // 적은 비용 저장
			}
			return;
		}
		
		for(int i=1;i<=N;i++) {	// 순회
			if(!check[i] && W[cur][i]!=0) {
				check[i]=true;
				dfs(start,i,cost+W[cur][i],cnt+1);
				check[i]=false;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);

		N=sc.nextInt();		// 도시 수
		W=new int[N+1][N+1];// 비용 행렬
		check=new boolean[N+1];	// 방문 체크
		
		for(int i=1;i<=N;i++) {	// 비용 행렬 저장
			for(int j=1;j<=N;j++) {
				W[i][j]=sc.nextInt();
			}
		}
		
		minCost=Integer.MAX_VALUE;	// 최소 비용 저장 변수
		for(int i=1;i<=N;i++) {
			Arrays.fill(check, false);
			dfs(i,i,0,0);
		}
		
		System.out.println(minCost);
		
		sc.close();
	}
}