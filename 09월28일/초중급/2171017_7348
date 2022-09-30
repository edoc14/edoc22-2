import java.util.Arrays;
import java.util.Scanner;

public class Main7348 {

	static int[] cor = new int[201];	//복도 배열

	static void fillwith(int from, int to) {	//from번째 방에서 to번째 방으로 옮길 때
		if (from > to) {	//from>to 일 경우 swap해줌
			int temp = from;
			from = to;
			to = temp;
		}
		int corfrom = (from % 2 == 0 ? (from / 2) : (from + 1) / 2);
		int corto = (to % 2 == 0 ? (to / 2) : (to + 1) / 2);
		//from이 짝수일 경우 corfrom에 from/2 저장, 홀수일 경우 (from+1)/2 저장
		//to도 마찬가지

		for (int i = corfrom; i <= corto; i++) {
			cor[i]++;
		}	//from에서 to로 옮길 경우 corfrom번째 복도부터 corto번째 복도까지 사용한다
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int testcase = scanner.nextInt();	//testcase 입력받기

		for (int i = 0; i < testcase; i++) {
			Arrays.fill(cor, 0);	//cor 배열을 0으로 초기화
			int n = scanner.nextInt();	//n 입력받기
			for (int j = 0; j < n; j++) {
				int from = scanner.nextInt();
				int to = scanner.nextInt();
				fillwith(from, to);	//from과 to 입력받고 fillwith함수 사용
			}
			Arrays.sort(cor);	//오름차순으로 정렬
			System.out.println(cor[200] * 10);	//cor[200](가장 많이 사용하는 복도)*10분 
		}
		scanner.close();
	}

}
