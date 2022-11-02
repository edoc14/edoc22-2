import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        //스캐너 선언
		Scanner sc = new Scanner(System.in);
		
        //읽어오기
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		
        //판단 및 정답 출력
		if(b>=c) {
			System.out.print(-1);
		}else System.out.print(a/(c-b) + 1);
		
		sc.close();

	}

}
