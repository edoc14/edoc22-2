import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main {
	
	static int n;	//도시의 수
	static boolean[] visited;	//방문 여부 기록용 배열
	static ArrayList<ArrayList<Integer>> info = new ArrayList<ArrayList<Integer>>();
	static int answer;	//정답을 저장할 변수

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		/*
		 * 입력값 받아오기
		 */
		n = Integer.parseInt(br.readLine());
		
		visited = new boolean[n];
		for(int i=0; i<n; i++) info.add(new ArrayList<Integer>());
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			for(int j=0; j<n; j++)
				info.get(i).add(Integer.parseInt(st.nextToken()));
		}
		
		
		/*
		 * 문제 해결
		 */
		
		answer = Integer.MAX_VALUE;
		
		for(int i=0; i<n; i++) {
			Arrays.fill(visited, false);
			visited[i] = true;
			for(int j=0; j<n; j++) {
				int cost = info.get(i).get(j);
				if(cost == 0) continue;	//갈 수 없는 도시이면 무시
				solve(i, j, cost);
			}
		}
		
		
		/*
		 * 정답 출력
		 */
		System.out.print(answer);
		

	}
	
	//재귀적으로 정의된 문제해결 함수
	//매개변수는 출발한 첫 도시(start), 현재 있는 도시(cur), 현재까지 든 비용(sum)
	public static void solve(int start, int cur, int sum) {
		//이미 방문한 도시인 경우 리턴
		if (visited[cur]) return;

		
		//처음 온 도시인 경우
		//이 도시에 새로 방문했음을 표시
		visited[cur] = true;
			
		
		//이번 도시에 옴으로써 모든 도시를 다 방문한 경우
		//첫 도시로 돌아가는 비용을 더하여 최종 계산을 한 후 리턴
		if(allTrue()) {
			//만약 현재 도시에서 출발지점으로 돌아가는 길이 없는 경우 그냥 리턴
			if(info.get(cur).get(start) == 0) {
				visited[cur] = false;
				return;
			}
			//그렇지 않은 경우엔 최종 계산 수행
			sum += info.get(cur).get(start);
			answer = Math.min(answer, sum);
			visited[cur] = false;
			return;
		}
		
		
		//아직 갈 도시가 더 남은 경우
		//이 도시에서부터 길이 뻗어있는 모든 도시에 대하여 재귀
		for(int i=0; i<n; i++) {
			int cost = info.get(cur).get(i);
			if (cost == 0) continue;	//갈 수 없는 도시이면 무시
			solve(start, i, sum + cost);
		}
		
		visited[cur] = false;
		return;
		
	}
	
	//모든 도시를 다 방문했는지 체크하는 함수
	//아직 안 간 도시가 하나라도 있으면 false를 리턴, 모든 도시를 갔으면 true를 리턴
	public static boolean allTrue() {
		for(boolean b: visited) {
			if(!b) return false;
		}
		return true;
	}

}
