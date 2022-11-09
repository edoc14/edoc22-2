import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BOJ_2477 {

	public static class Edge{
		int dir, len;
		public Edge(int dir, int len) {
			// TODO Auto-generated constructor stub
			this.dir = dir;
			this.len = len;
		}
	}
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int K = Integer.parseInt(br.readLine());  //단위 면적 당 참외 개수
		Edge map[] = new Edge[6]; //변 6개의 길이를 저장할 배열
		int width = 0, height = 0; //가장 긴 가로, 세로의 길이를 저장
		int widx = 0, hidx = 0; //가장 긴 가로, 세로 길이의 idx를 저장
		
		for(int i=0; i<6;i++) {
			st = new StringTokenizer(br.readLine());
			int dir = Integer.parseInt(st.nextToken());
			int len = Integer.parseInt(st.nextToken());
			map[i] = new Edge(dir, len);

			if (dir == 1 || dir == 2) { //세로변의 최대 길이 구하기
				if (height < len) {
					height = len;
					hidx = i; //가장 긴 세로변을 저장하고 있는 idx
				}
			}
			else { //가로변의 최대 길이 구하기
				if (width < len) {
					width = len;
					widx = i; //가장 긴 가로변을 저장하고 있는 idx
				}
			}
		}
		
		int big = width * height; //전체 큰 사각형의 넓이
		int small = map[(hidx + 3) % 6].len * map[(widx + 3) % 6].len; //작은 사각형의 넓이 구하기. (가장 긴 변 + 3) 만큼 간게 짧은 변의 길이.
		int ans = (big - small) * K;
		System.out.println(ans);
	}

}
