import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main1038 {

	static ArrayList<Long> list;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);

		int n = scanner.nextInt();
		list = new ArrayList<>();

		if (n <= 10) {
			System.out.println(n);
		} else if (n > 1022) {
			System.out.println(-1);
		} else {
			for (int i = 0; i < 10; i++) {
				bp(i, 1);
			}
			Collections.sort(list);

			System.out.println(list.get(n));
		}
		scanner.close();

	}

	public static void bp(long num, int idx) {
		if (idx > 10)
			return;

		list.add(num);
		for (int i = 0; i < num % 10; i++) {
			bp((num * 10) + i, idx + 1);
		}
	}
}
