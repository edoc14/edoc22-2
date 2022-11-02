import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_1712 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int A = 0, B = 0, C = 0;
		A = Integer.parseInt(st.nextToken()); //고정비용
		B = Integer.parseInt(st.nextToken()); //가변비용
		C = Integer.parseInt(st.nextToken()); //노트북 가격
		int earning = C - B; //노트북 1대 팔 때마다 얻는 이익
		if (earning <= 0)
			System.out.println(-1);
		else {
			double num = A / earning;
			System.out.println((int)num + 1);
		}
	}
}
