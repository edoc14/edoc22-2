import java.util.Scanner;

public class Main1712 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);

		int a = scanner.nextInt();
		int b = scanner.nextInt();
		int c = scanner.nextInt();

		int result;
		if (c <= b) {
			result = -2;
		} else {
			result = a / (c - b);
		}
		System.out.println(result + 1);

		scanner.close();
	}

}
