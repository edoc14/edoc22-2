import java.io.*;
import java.util.StringTokenizer;
import java.util.Arrays;

public class BOJ1063 {
	static void move(String mm, char[] next) {
		switch(mm) {
			case "R": next[0]++; break;
			case "L": next[0]--; break;
			case "B": next[1]--; break;
			case "T": next[1]++; break;
			case "RT": next[0]++; next[1]++; break;
			case "LT": next[0]--; next[1]++; break;
			case "RB": next[0]++; next[1]--; break;
			case "LB": next[0]--; next[1]--; break;
		}
	}
	
	static boolean range(char[] next) {
		// ���� ���̸� true, ���̸� false
		return (next[0] < 'A' || next[0] > 'H' || next[1] < '1' || next[1] > '8');
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		char[] k = st.nextToken().toCharArray();
		char[] s = st.nextToken().toCharArray();
		int N = Integer.parseInt(st.nextToken());
		
		for(int i = 0; i < N; i++) {
			String mm = br.readLine();
			char[] kM = k.clone();
			char[] sM = s.clone();
			move(mm, kM);
			
			// ���� �� �Ѿ�� ���� �������� �Ѿ
			if(range(kM)) continue;
			
			// ���̶� ŷ�̶� ���� ��ġ�� ���
			if(Arrays.equals(kM, sM)) {
				move(mm, sM);
				if(range(sM)) continue;
			}
			
			// ���� �Ѿ�� ���� ��� �̵��� ���� �ݿ�
			k = kM;
			s = sM;
		}
		
		System.out.println(k + "\n" + s);
	}
}
