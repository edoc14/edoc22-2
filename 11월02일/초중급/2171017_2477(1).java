import java.util.Scanner;

public class Main2477 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);

		int k = scanner.nextInt();

		int[] array = new int[6];
		int biggestIdx = 0;

		for (int i = 0; i < 6; i++) {
			scanner.nextInt();
			array[i] = scanner.nextInt();
			if (array[i] > array[biggestIdx]) {
				biggestIdx = i;
			}
		}

		int SecbigIdx = 0;
		int a, b;

		if (array[(biggestIdx - 1 + 6) % 6] > array[(biggestIdx + 1) % 6]) {
			SecbigIdx = (biggestIdx - 1 + 6) % 6;
			a = (biggestIdx + 2) % 6;
			b = (SecbigIdx - 2 + 6) % 6;
		} else {
			SecbigIdx = (biggestIdx + 1) % 6;
			a = (biggestIdx - 2 + 6) % 6;
			b = (SecbigIdx + 2) % 6;
		}

		int area = array[biggestIdx] * array[SecbigIdx] - array[a] * array[b];

		System.out.println(area * k);

	}

}
