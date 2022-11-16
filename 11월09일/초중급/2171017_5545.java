import java.util.Arrays;
import java.util.Scanner;

public class Main5545 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);

		int topnum = scanner.nextInt();

		int doucost = scanner.nextInt();
		int topcost = scanner.nextInt();

		int doucal = scanner.nextInt();

		int[] topcal = new int[topnum];
		for (int i = 0; i < topnum; i++)
			topcal[i] = scanner.nextInt();

		Arrays.sort(topcal);

		/*
		 * for(int i=0;i<topnum;i++) System.out.println(topcal[i]);
		 */

		int cost = doucost;
		int cal = doucal;
		int best = cal / cost;

		int index = topnum - 1;

		while (index >= 0) {
			cost += topcost;
			cal += topcal[index];

			if (best > cal / cost)
				break;
			else {
				best = cal / cost;
				index--;
			}
		}

		System.out.println(best);

	}

}
