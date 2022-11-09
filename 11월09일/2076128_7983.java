import java.util.*;
import java.io.*;

public class BOJ7983 {
	private static class Work implements Comparable<Work>{
		int d, t;

		Work(int d, int t) {
			this.d = d;
			this.t = t;
		}
		
		@Override
		public int compareTo(Work other) {
			return other.t - this.t;
		}
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());	// ���� ��
		Work[] w = new Work[N];
		int d, t;
		
		StringTokenizer st;
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			d = Integer.parseInt(st.nextToken());
			t = Integer.parseInt(st.nextToken());
			w[i] = new Work(d, t);
		}
		
		Arrays.sort(w); // t ���� �������� ����. (���� �ʰ� �������Ǵ� ������ ó��)
		int lD = w[0].t;	// last Date. ���� �������� ���� ������ ��¥
		int max = 0;

		for(int i = 0; i < N; i++) {
			int tempD = w[i].d;	// D�� �ɸ�
			int tempT = w[i].t;	// T���� ���������� ����
			if(lD > tempT) {
				lD = tempT;
				if(max < lD - tempT) max = lD - tempT;
			}
	
			lD -= tempD;
		}
		if(max < lD) max = lD;
		System.out.println(max);
	}
}