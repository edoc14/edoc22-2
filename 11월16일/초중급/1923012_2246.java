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
		
		int n = Integer.parseInt(br.readLine());
		
		Condo[] condoes = new Condo[n];
		
		for(int i=0; i<n; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			condoes[i] = new Condo(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		
		//거리 순으로 오름차순 정렬하는 Comparator
		Comparator<Condo> cpd = new Comparator<Condo>() {
			@Override
			public int compare (Condo c1, Condo c2) {
				if(c1.getD() > c2.getD()) return 1;
				else if (c1.getD() == c2.getD()) {
					if(c1.getC() < c2.getC()) return 1;
					else return -1;
				}
				else return -1;
			}
		};
		
		//가격 순으로 오름차순 정렬하는 Comparator
		Comparator<Condo> cpc = new Comparator<Condo>() {
			@Override
			public int compare(Condo c1, Condo c2) {
				if(c1.getC() > c2.getC()) return 1;
				else if(c1.getC() == c2.getC()) {
					if(c1.getD() < c2.getD()) return 1;
					else return -1;
				}
				else return -1;
			}
		};
		
		//거리 순으로 오름차순 정렬
		Arrays.sort(condoes, cpd);
		
		//모든 콘도에 대하여, 나보다 바닷가에 가까운 콘도 중 가격이 더 싸거나 같은 것이 있는지 판단
		for(int i=0; i<n; i++) {
			for(int j=0; j<i; j++) {
				if (condoes[i].getC()>=condoes[j].getC()) {
					condoes[i].setCheck(false);
					break;
					}
			}
		}
		
		
		//가격 순으로 오름차순 정렬
		Arrays.sort(condoes, cpc);
		
		//모든 콘도에 대하여, 나보다 싼 콘도 중 거리가 바닷가에 가깝거나 같은 것이 있는지 판단
		for(int i=0; i<n; i++) {
			for(int j=0; j<i; j++) {
				if (condoes[i].getD() >= condoes[j].getD()) {
					condoes[i].setCheck(false);
					break;
				}
			}
		}

		
		int answer = 0;
		for(Condo c: condoes) {
			if(c.getCheck()) answer++;
		}
		
		System.out.print(answer);
	}

}

class Condo {
	private int d;	//거리
	private int c;	//가격
	private boolean check;	//false가 되면 후보 탈락
	public Condo(int d, int c) {
		this.d = d;
		this.c = c;
		this.check = true;
	}
	public int getD() {return d;}
	public int getC() {return c;}
	public void setCheck(boolean check) {this.check = check;}
	public boolean getCheck() {return check;}
}
