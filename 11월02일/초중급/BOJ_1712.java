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
		A = Integer.parseInt(st.nextToken()); //�������
		B = Integer.parseInt(st.nextToken()); //�������
		C = Integer.parseInt(st.nextToken()); //��Ʈ�� ����
		int earning = C - B; //��Ʈ�� 1�� �� ������ ��� ����
		if (earning <= 0)
			System.out.println(-1);
		else {
			double num = A / earning;
			System.out.println((int)num + 1);
		}
	}
}
