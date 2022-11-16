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
		int N = Integer.parseInt(br.readLine());	// 과제 수
		Work[] w = new Work[N];
		int d, t;
		
		StringTokenizer st;
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			d = Integer.parseInt(st.nextToken());
			t = Integer.parseInt(st.nextToken());
			w[i] = new Work(d, t);
		}
		
		Arrays.sort(w); // t 기준 내림차순 정렬. (가장 늦게 끝내도되는 과제가 처음)
		int lD = w[0].t;	// last Date. 현재 일정없는 가장 마지막 날짜
		int max = 0;

		for(int i = 0; i < N; i++) {
			int tempD = w[i].d;	// D일 걸림
			int tempT = w[i].t;	// T일이 끝나기전에 제출
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