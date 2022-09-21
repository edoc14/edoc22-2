import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_2110 {
	
	public static int counterRounter(int dist, int home[]) { //���� ������ �� ������ ������ �Ÿ��� dist�̵��� �����⸦ ��ġ���� ��, ��ġ�� �������� ����
		int cnt = 1; //ù��° ���� ������ ��ġ
		int now = home[0]; //���� �����⸦ ��ġ�� ���� ��ġ
		for(int i=1; i<home.length;i++) {
			if(home[i]-now >= dist) {  //���� ��-���������� ������ ��ġ�� �� �� �Ÿ��� dist���� �̻��� �� ��ġ�ؾ� ��
				cnt++;
				now= home[i];
			}
		}
		return cnt; //��ġ�� �������� ���� return�ϱ�
	}
	
	public static int getUpperbound(int left, int right, int target, int home[]) { //��ġ ������ �������� ������ c�� �ʰ��ϴ� ������ ���Ѵ�
		while(left<=right) {
			int mid = (left + right)/2;
			int count = counterRounter(mid, home); //���� ������ �� ������ ������ �Ÿ��� mid�̵��� �����⸦ ��ġ���� ��, ��ġ�� �������� �� ����
			
			if(count >= target)  //��ġ�ؾߵǴ� �������� �� ��ġ�� ��� -> �Ÿ��� �ø���
				left = mid+1;
			else //��ġ�ؾߵǴ� �������� ���� ��ġ�� ��� -> �Ÿ��� ������
				right = mid - 1;
			
		}
		return left;		
	}
	
	public static int solution(int n, int c, int home[]) {
		int answer = 0;
		//�̺�Ž���� ���ĵ� ���¿��� �����
		Arrays.sort(home);
		answer = getUpperbound(1, home[n-1]-home[0], c, home)-1;  //������ ������ �ִ� �Ÿ�(left) = 1, ������ ������ ����Ÿ�(right) = ���� �ָ��ִ� �� �� ������ �Ÿ� = home[n-1] - home[0]
		//upperbound�� �ʰ��� ������ return �ϹǷ� �� ������ -1�� ����� ����Ÿ��� ���´�.
		return answer;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()); //���� ����
		int C = Integer.parseInt(st.nextToken()); //������ ����
		
		int home[] = new int [N];
		
		for(int i=0;i<N;i++) {
			home[i] = Integer.parseInt(br.readLine()); 
		}
		
		System.out.println(solution(N, C, home));
		

	}

}
