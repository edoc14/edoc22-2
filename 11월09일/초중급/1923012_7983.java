//성공한 코드입니다
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		/*
		 * 입력값 읽어오기
		 */
		//과제의 개수
		int n = Integer.parseInt(br.readLine());
		//과제들
		Homework[] hws = new Homework[n];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			hws[i] = new Homework(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		
		//과제를 마감 일자가 늦은 순으로 정렬
		Arrays.sort(hws, new Comparator<Homework>() {

			@Override
			public int compare(Homework h1, Homework h2) {
				// TODO Auto-generated method stub
				if (h1.getT()<h2.getT()) return 1;
				else return -1;
			}
			
		});
		
		/*
		 * 정답 구하기
		 */
		int ans = Integer.MAX_VALUE;
		
		for(Homework h: hws) {
			if(h.getT()>ans) ans = ans - h.getD();
			else ans = h.getT() - h.getD();
		}
		System.out.print(ans);

	}

}

//과제 클래스
class Homework {
	private int d;	//하는 데 걸리는 일 수
	private int t;	//마감일자
	public Homework (int d, int t) {
		this.d = d;
		this.t = t;
	}
	
	public int getD(){
		return d;
	}
	public int getT() {
		return t;
	}
}
