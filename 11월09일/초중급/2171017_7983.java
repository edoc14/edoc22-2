import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Iterator;
import java.util.Scanner;

class Assign {
	int d, t;

	public Assign(int d, int t) {
		this.d = d;
		this.t = t;
	}
}

public class Main7983 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int testcase = scanner.nextInt();

		ArrayList<Assign> myAssign = new ArrayList<Assign>();

		int din, tin;
		for (int i = 0; i < testcase; i++) {
			din = scanner.nextInt();
			tin = scanner.nextInt();
			myAssign.add(new Assign(din, tin));
		}

		Collections.sort(myAssign, new Comparator<Assign>() {
			public int compare(Assign a1, Assign a2) {
				if (a1.t == a2.t)
					return a2.d - a1.d;
				else
					return a2.t - a1.t;
			}
		});

		int day = myAssign.get(0).t; // 가장 나중에 있는 마감날짜

		/*
		 * for (int i = 0; i < testcase; i++) { Assign thisAssign = myAssign.get(i);
		 * System.out.println(thisAssign.d + " " + thisAssign.t); }
		 */

		Iterator<Assign> it = myAssign.iterator();

		while (it.hasNext()) {
			Assign nowAssign = it.next();
			if (nowAssign.t < day)
				day = nowAssign.t;

			day -= nowAssign.d;
			// System.out.println(nowAssign.d + " " + nowAssign.t);
		}
		System.out.println(day);
		scanner.close();
	}

}
