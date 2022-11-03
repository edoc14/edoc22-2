import java.util.Scanner;

class Location {
	private char x;
	private int y;

	public Location(String loc) {
		x = loc.charAt(0);
		y = loc.charAt(1) - '0';
	}

	public char getX() {
		return x;
	}

	public int getY() {
		return y;
	}

	public void moveR() {
		x = (char) ((int) x + 1);
	}

	public void moveL() {
		x = (char) ((int) x - 1);
	}

	public void moveT() {
		y++;
	}

	public void moveB() {
		y--;
	}

}

public class Main1063 {

	static Location king;
	static Location rock;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);

		String kingloc = sc.next();
		String rockloc = sc.next();

		int n = sc.nextInt();

		king = new Location(kingloc);
		rock = new Location(rockloc);

		for (int i = 0; i < n; i++) {
			String input = sc.next();

			if (input.compareTo("R") == 0)
				R();
			else if (input.compareTo("L") == 0)
				L();
			else if (input.compareTo("B") == 0)
				B();
			else if (input.compareTo("T") == 0)
				T();
			else if (input.compareTo("RT") == 0)
				RT();
			else if (input.compareTo("LT") == 0)
				LT();
			else if (input.compareTo("RB") == 0)
				RB();
			else
				LB();

		}
		System.out.print((char) king.getX());
		System.out.println(king.getY());
		System.out.print((char) rock.getX());
		System.out.println(rock.getY());

		sc.close();
	}

	public static void R() {
		if (king.getX() + 1 == rock.getX() && king.getY() == rock.getY()) {
			if (rock.getX() == 'H')
				return;
			else {
				king.moveR();
				rock.moveR();
			}
		} else {
			if (king.getX() == 'H')
				return;
			else {
				king.moveR();
			}
		}
	}

	public static void L() {
		if (king.getX() - 1 == rock.getX() && king.getY() == rock.getY()) {
			if (rock.getX() == 'A')
				return;
			else {
				king.moveL();
				rock.moveL();
			}
		} else {
			if (king.getX() == 'A')
				return;
			else {
				king.moveL();
			}
		}
	}

	public static void B() {
		if (king.getX() == rock.getX() && king.getY() - 1 == rock.getY()) {
			if (rock.getY() == 1)
				return;
			else {
				king.moveB();
				rock.moveB();
			}
		} else {
			if (king.getY() == 1)
				return;
			else {
				king.moveB();
			}
		}
	}

	public static void T() {
		if (king.getX() == rock.getX() && king.getY() + 1 == rock.getY()) {
			if (rock.getY() == 8)
				return;
			else {
				king.moveT();
				rock.moveT();
			}
		} else {
			if (king.getY() == 8)
				return;
			else {
				king.moveT();
			}
		}
	}

	public static void RT() {
		if (king.getX() + 1 == rock.getX() && king.getY() + 1 == rock.getY()) {
			if (rock.getX() == 'H' || rock.getY() == 8)
				return;
			else {
				king.moveR();
				king.moveT();
				rock.moveR();
				rock.moveT();
			}
		} else {
			if (king.getX() == 'H' || king.getY() == 8)
				return;
			else {
				king.moveR();
				king.moveT();
			}
		}
	}

	public static void LT() {
		if (king.getX() - 1 == rock.getX() && king.getY() + 1 == rock.getY()) {
			if (rock.getX() == 'A' || rock.getY() == 8)
				return;
			else {
				king.moveL();
				king.moveT();
				rock.moveL();
				rock.moveT();
			}
		} else {
			if (king.getX() == 'A' || king.getY() == 8)
				return;
			else {
				king.moveL();
				king.moveT();
			}
		}
	}

	public static void RB() {
		if (king.getX() + 1 == rock.getX() && king.getY() - 1 == rock.getY()) {
			if (rock.getX() == 'H' || rock.getY() == 1)
				return;
			else {
				king.moveR();
				king.moveB();
				rock.moveR();
				rock.moveB();
			}
		} else {
			if (king.getX() == 'H' || king.getY() == 1)
				return;
			else {
				king.moveR();
				king.moveB();
			}
		}
	}

	public static void LB() {
		if (king.getX() - 1 == rock.getX() && king.getY() - 1 == rock.getY()) {
			if (rock.getX() == 'A' || rock.getY() == 1)
				return;
			else {
				king.moveL();
				king.moveB();
				rock.moveL();
				rock.moveB();
			}
		} else {
			if (king.getX() == 'A' || king.getY() == 1)
				return;
			else {
				king.moveL();
				king.moveB();
			}
		}
	}
}
