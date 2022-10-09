import java.util.*;

public class Main {

	public static class Table implements Comparable<Table> {
		int s;
		int t;
		int l;

		public Table(int s, int t) {
			if (s < t) {
				this.s = s;
				this.t = t;
			} else {
				this.s = t;
				this.t = s;
			}
			this.l = Math.abs(s - t);
		}

		@Override
		public int compareTo(Table o) {
			if (s == o.s)
				return Integer.compare(l, o.l);
			return Integer.compare(s, o.s);
		}
	};

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int T = sc.nextInt();
		int s, t;
		List<Table> list = new ArrayList<>();
		for (int tc = 0; tc < T; tc++) {
			int N = sc.nextInt();
			for (int i = 0; i < N; i++) {
				s = (sc.nextInt()-1)/2;
				t = (sc.nextInt()-1)/2;
				list.add(new Table(s, t));
			}

			int ans = 0;
			Collections.sort(list);
			while (!list.isEmpty()) {
				t = Integer.MIN_VALUE;
				ans+=10;
				List<Table> tmp = new ArrayList<>();
				for (int i = 0; i < list.size(); i++) {
					if (list.get(i).s > t) {
							t = list.get(i).t;
					}else {
						tmp.add(list.get(i));
					}
				}
				list = tmp;
			}
			System.out.println(ans);
		}
	}
}
