import java.util.Scanner;

public class Main9466 {
	static int[] mem;
	static boolean[] team;
	
	public int Find(int idx) {
		if(mem[idx]==idx) {
			team[idx]=true;
		}else {
			Find(mem[idx]);
		}
	}

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int testcase = scanner.nextInt();

		for (int i = 0; i < testcase; i++) {
			int n = scanner.nextInt();
			
			mem = new int[n];
			for (int j = 0; j < n; j++) {
				mem[j]=scanner.nextInt();
			}
			
		}
	}

}
