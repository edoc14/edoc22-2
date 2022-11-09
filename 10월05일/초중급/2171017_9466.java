import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main9466 {
	static int stoi(String s) {
		return Integer.parseInt(s);
	}

	static int n; // 학생 수
	static int[] arr; // 선택된 학생들 배열
	static int count = 0;
	static boolean[] visited; // 방문 여부
	static boolean[] finished;
	// 사이클이 이미 다른 노드 탐색에서 나왔는가?

	public static void main(String[] args) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;

		int tc = stoi(br.readLine()); // 테스트케이스

		for (int t = 0; t < tc; t++) {
			n = stoi(br.readLine()); // 학생 수
			arr = new int[n + 1];
			visited = new boolean[n + 1];
			finished = new boolean[n + 1];
			count = 0;

			st = new StringTokenizer(br.readLine());
			for (int i = 1; i <= n; i++) {
				arr[i] = stoi(st.nextToken());
			} // BufferedReader로 입력받은 값을 Token 단위로 나누어 배열에 저장

			for (int i = 1; i <= n; i++) {
				dfs(i);
			}

			System.out.println(n - count);
		}
	}

	static void dfs(int now) {
		if (visited[now]) {
			return; // 탐색완료한 경우 return
		}
		visited[now] = true; // 현재 탐색중인 index
		int next = arr[now]; // 현재 index가 가리키는 사람

		if (visited[next] != true) { // next를 방문하지 않았을 경우
			dfs(next); // next 탐색
		} else {
			if (finished[next] != true) {
				// 방문은 했는데 사이클이 안 나왔다
				// 사이클은 무조건 나오게 되어있다
				count++;
				for (int i = next; i != now; i = arr[i]) {
					count++;
				}
			}
		}
		finished[now] = true; // 사이클 탐색 완

	}

}
