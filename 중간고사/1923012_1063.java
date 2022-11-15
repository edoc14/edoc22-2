import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class Main{
	
	static Queue<Direction> moves = new LinkedList<Direction>();	//움직임 명령을 저장할 큐
	static int kcol, krow, rcol, rrow;	//킹과 돌의 현재 위치
	
	//움직이는 함수
	public static void move() {
		Direction dir = moves.poll();
		//옮길 경우 킹의 위치 계산
		int nkcol = kcol+dir.getC();
		int nkrow = krow+dir.getR();
		
		//옮길 경우 킹이 밖으로 나가는지 판별
		if(nkcol>7
				||
				nkcol<0
				||
				nkrow>7
				||
				nkrow<0) return;	//나간다면 즉시 리턴
		
		//킹이 옮길 곳에 돌이 있는지 판별
		if(nkcol!=rcol || nkrow != rrow) {
			//그곳에 돌이 없는 경우
			//그냥 킹만 옮기고 리턴
			kcol = nkcol;
			krow = nkrow;
			return;
		}
		//그곳에 돌이 있는 경우
		//옮길 경우 돌의 위치 계산
		int nrcol = rcol+dir.getC();
		int nrrow = rrow+dir.getR();
		//옮길 경우 돌이 밖으로 나가는지 판별
		if(nrcol>7
				||
				nrcol<0
				||
				nrrow>7
				||
				nrrow<0) return;	//나간다면 즉시 리턴
		
		//나가지 않는 경우
		//킹과 돌을 모두 옮기고 리턴
		kcol = nkcol;
		krow = nkrow;
		rcol = nrcol;
		rrow = nrrow;
		return;
	}

	public static void main(String[] args)  throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		/*
		 * 입력값 받아오기
		 */
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		//초기 위치 설정
		char[] king = st.nextToken().toCharArray();
		char[] rock = st.nextToken().toCharArray();
		int n = Integer.parseInt(st.nextToken());	//움직임 횟수
		
		kcol = king[0] - 'A';
		krow = 8 - (king[1] - '0');
		rcol = rock[0] - 'A';
		rrow = 8 - (rock[1] - '0');
		
		//움직임 정보 받아오기
		for(int i=0; i<n; i++) {
			String input = br.readLine();
			
			switch(input) {
			case "R" : moves.add(new Direction(1, 0));
				break;
			case "L" : moves.add(new Direction(-1, 0));
				break;
			case "B" : moves.add(new Direction(0, 1));
				break;
			case "T" : moves.add(new Direction(0, -1));
				break;
			case "RT" : moves.add(new Direction(1, -1));
				break;
			case "LT" : moves.add(new Direction(-1, -1));
				break;
			case "RB" : moves.add(new Direction(1, 1));
				break;
			case "LB" : moves.add(new Direction(-1, 1));
				break;
			}
		}
		
		
		/*
		 * 움직이기
		 */
		while(!moves.isEmpty()) move();
		
		/*
		 * 정답 출력
		 */
		
		System.out.print((char)(kcol + 'A'));
		System.out.println(8 - krow);
		System.out.print((char)(rcol + 'A'));
		System.out.print(8 - rrow);
		
		

	}

}

class Direction {
	private int col;	//열 방향으로 움직어야 하는 방향
	private int row;	//행 방향으로 움직여야 하는 방향
	public Direction (int col, int row) {
		this.col = col;
		this.row = row;
	}
	
	public int getC() {
		return col;
	}
	public int getR() {
		return row;
	}

}
