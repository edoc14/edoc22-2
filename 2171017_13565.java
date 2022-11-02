import java.util.Scanner;

public class Main13565 {
	static boolean[] visited;
	static int[] array;

	static int[][] graph;

	static void dfs(int nodeIndex) {
		if (array[nodeIndex] == 0) {
			visited[nodeIndex] = true;
			
			for(int node:graph[nodeIndex]) {
				if(!visited[node]) {
					dfs(node);
				}
			}
		}
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		int n = scanner.nextInt();

		visited = new boolean[m * n];
		array = new int[m * n];
		graph = new int[m * n][m * n];

		for (int i = 0; i < m * n; i++) {
			graph[i][0] = i - m;
			graph[i][1] = i - 1;
			graph[i][2] = i + 1;
			graph[i][3] = i + m;
		}

		for (int i = 0; i < m; i++) {
			String line = scanner.nextLine();
			for (int j = 0; j < n; j++) {
				array[i * n + j] = (int) line.charAt(i) - '0';
			}
		}
		
		dfs(0);
		
		

	}

}
