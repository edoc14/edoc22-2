import java.io.*;
import java.util.*;

public class BOJ_9466 {
	static int n, cnt;
	static int[] num;
	static boolean[] check, isEnd;
	
	static void dfs(int node) {
		check[node] = true;	// 해당 노드 방문했음을 체크
		int next = num[node];
		
		if(!check[next]) { // 다음 노드를 방문하지 않았다면 방문
			dfs(next);
		}
		
		else {	// 다음 노드를 방문했다면
			if(!isEnd[next]) {
				cnt++;
				
				while(next != node) {
					cnt++;
					next = num[next];
				}
			}
		}
		
		isEnd[node] = true; // 탐색 종료 체크하기
	}
	
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int T = Integer.parseInt(br.readLine());	// 테스트 케이스 개수
		
		for(int i=0; i<T; i++) {	// 테스트 케이스 개수만큼 반복
			n = Integer.parseInt(br.readLine()); // 학생 수
			num = new int[n+1]; // 선택된 학생들 번호
			check = new boolean[n+1]; // 방문 여부 체크
			isEnd = new boolean[n+1]; // 노드 탐색 종료 여부 저장
			cnt =0;	// 팀에 속한 학생 수
			
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=1; j<n+1; j++) {	// 선택된 학생들 번호 저장
				num[j]=Integer.parseInt(st.nextToken());
			}
			
			for(int j=1; j<n+1; j++) {
				dfs(j);	// 탐색
			}
			
			System.out.println(n-cnt);	// 팀에 속하지 못한 학생 수 출력
		}
		
	}
}
