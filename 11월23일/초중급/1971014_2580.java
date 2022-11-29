import java.io.*;
import java.util.*;
public class BOJ_2580 {
	static int[][] s;
	
	public static void dfs(int row, int col) {
		if(col==9) {		// 마지막 열이면
			dfs(row+1,0); 	// 다음 행으로 이동
			return;
		}
		
		if(row==9) {		// 마지막 행이면 출력
			StringBuilder sb = new StringBuilder();
			for (int i=0;i<9;i++) {
				for (int j=0;j<9;j++) {
					sb.append(s[i][j]).append(' ');
				}
				sb.append('\n');
			}
			System.out.println(sb);
			
			System.exit(0);
		}
		
		if(s[row][col]==0) {	// 비어있는 칸이면
			for(int i=1;i<=9;i++) {
				if(check(row,col,i)) {	// 가능한 숫자일 때
					s[row][col]=i;		// 스도쿠 행렬에 저장
					dfs(row,col+1);		// 다음으로 넘어가기
				}
			}
			s[row][col]=0;
			return;
		}
		
		dfs(row,col+1);
	}
	
	public static boolean check(int row, int col, int num) {
		for(int i=0;i<9;i++) {
			if(s[row][i]==num) { // 해당 행에 해당 숫자가 이미 있는 경우
				return false;
			}
		}
		
		for(int i=0;i<9;i++) {
			if(s[i][col]==num) { // 해당 열에 해당 숫자가 이미 있는 경우
				return false;
			}
		}
		
		int square_row=(row/3)*3;	// 정사각형 행
		int square_col=(col/3)*3;	// 정사각형 열
		
		for(int i=square_row;i<square_row+3;i++) {
			for(int j=square_col;j<square_col+3;j++) {
				if(s[i][j] ==num)	// 정사각형 안에 해당 숫자가 이미 있는 경우
					return false;
			}
		}
		
		return true;
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		s=new int[9][9];
		for(int i=0;i<9;i++) {	// 스도쿠 저장
			StringTokenizer st=new StringTokenizer(br.readLine());
			for(int j=0;st.hasMoreTokens();j++) {
				s[i][j]=Integer.parseInt(st.nextToken());
			}
		}
		
		dfs(0,0);
	}
}
