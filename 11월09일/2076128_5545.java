import java.io.*;
import java.util.*;

public class BOJ5545 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N, A, B, C;
		
		N = Integer.parseInt(br.readLine()); 	// ���� ���� ��
		int[] D = new int[N];	
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		A = Integer.parseInt(st.nextToken()); 	// ���� ����
		B = Integer.parseInt(st.nextToken()); 	// ���� ����
		
		C = Integer.parseInt(br.readLine());	// ���� ����
		
		for(int i = 0; i < N; i++) {
			D[i] = Integer.parseInt(br.readLine());	// �� ������ ����
		}
		Arrays.sort(D); // �������� ����
		
		int cost = A, kcal = C;	// ���츸 �ִ� ����
		double best = C / A;
		double temp = 0;
		
		for(int i = N-1; i >= 0; i--) { // �迭�� ������������ ���ĵǾ������Ƿ� �Ųٷ�.
			// ������ ���� ������� ������ �߰��غ���.
			temp = (kcal + D[i]) / (cost + B);
			
			if(best > temp) {
				// �������� ������ �������ٸ� break. ������ ���°� �ְ��� �����̴�.
				// ���� ��ü�� ������ ���� ���� ������ ���� �پ���.
				// ���� �� �� ������ '1���� ����'�� �ٽ� ������������
				break;
			}
			else { 
				// �������� ������ �����ߴٸ� ���� ���¸� ����.
				kcal += D[i];
				cost += B;
				best = temp;
			}
		}
		
		System.out.print((int)best);
	}
}
