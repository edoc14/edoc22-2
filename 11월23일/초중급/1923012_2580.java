import java.util.Scanner;

public class Main {
	
	static int[][] arr = new int[9][9];	//스도쿠 판
	static StringBuilder sb;

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		//스도쿠 판의 내용 읽어오기
		for(int i = 0; i<9; i++) {
			for(int j = 0; j<9; j++) {
				arr[i][j] = sc.nextInt();
			}
		}
		
		//문제 풀어서 출력하기
		sb = new StringBuilder();
		sudoku(0,0);
		
		sc.close();

	}
	
	static void sudoku(int row, int col) {
		//해당 행을 다 살폈다면 다음 행의 첫 칸으로 넘어가서 재귀
		if(col == 9) {
			sudoku(row+1, 0);
			return;
		}
		
		//마지막 행(row == 8인 행)까지 다 채워졌다면 출력
		if(row == 9) {
			for(int i = 0; i<9; i++) {
				for(int j = 0; j<9; j++) {
					sb.append(arr[i][j] + System.getProperty("line.separator"));
				}
				sb.append(System.getProperty("line.separator"));
			}
			System.out.print(sb);
			System.exit(0);
		}
		
		//이번 칸이 빈칸이라면 가능한 수를 찾아 적어넣어준 후, 같은 줄 다음 칸으로 재귀
		if(arr[row][col] == 0) {
			for(int i = 1; i<=9; i++) {
				if(possible(row,col,i)) {
					arr[row][col] = i;
					sudoku(row,col+1);
				}
			}
			arr[row][col] = 0;
			return;
		}
		
		//이번 칸이 빈칸이 아니라면 그냥 같은 줄 다음 칸으로 재귀
		sudoku(row, col+1);
	}
	
	//(row,col)에 num이 들어갈 수 있는지를 체크하는 함수(들어갈 수 있으면 true, 아니면 false를 리턴)
	static boolean possible(int row, int col, int num) {
		//1. 같은 행에 겹치는 수가 있는지 체크
		for(int i = 0; i<9; i++) {
			if(arr[row][i] == num) return false;	//겹치는 수가 있으면 즉시 false를 리턴
		}
		//2. 같은 열에 겹치는 수가 있는지 체크
		for(int i = 0; i<9; i++) {
			if(arr[i][col] == num) return false;	//겹치는 수가 있으면 즉시 false를 리턴
		}
		//3. 같은 3x3 구역에 겹치는 수가 있는지 체크
		//해당 칸이 속한 3x3구역의 첫 칸의 좌표 구하기
		int startrow = (row/3)*3;
		int startcol = (col/3)*3;
		for(int i = startrow; i<startrow+3; i++) {
			for(int j = startcol; j<startcol+3; j++) {
				if(arr[i][j] == num) return false;	//겹치는 수가 있으면 즉시 false를 리턴
			}
		}
		
		//위의 세 단계에서 한 번도 false를 리턴하지 않았다면 true를 리턴
		return true;
	}

}
