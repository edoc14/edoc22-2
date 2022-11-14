import java.util.*;

// 감소하는 수의 최댓값은 9876543210으로 1022번째이다.
// 따라서 1023 이상의 값이 n으로 입력되면 -1을 출력.

public class BOJ1038 {
	public static ArrayList NumList(long num, int digit, ArrayList list) {
		if(digit > 10) return list;
		
		list.add(num);
		for(int i = 0; i < 10; i++) {
			if(num % 10 > i) NumList((num * 10) + i, digit + 1, list);
		}
		
		return list;
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		
		if(num >= 1023) {
			System.out.println(-1);
		}
		else {
			ArrayList<Integer> list = new ArrayList<>();
		
			for(int i = 0; i < 10; i++) {
				NumList(i, 1, list);
			}
		
			Collections.sort(list);
			
			System.out.println(list.get(num));
		}
		
		sc.close();
	}
}
