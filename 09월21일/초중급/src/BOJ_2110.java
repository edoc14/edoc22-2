import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BOJ_2110 {
	
	public static int counterRounter(int dist, int home[]) { //가장 인접한 두 공유기 사이의 거리가 dist이도록 공유기를 설치했을 때, 설치된 공유기의 개수
		int cnt = 1; //첫번째 집에 무조건 설치
		int now = home[0]; //현재 공유기를 설치한 집의 위치
		for(int i=1; i<home.length;i++) {
			if(home[i]-now >= dist) {  //현재 집-마지막으로 공유기 설치한 집 의 거리가 dist보다 이상일 때 설치해야 함
				cnt++;
				now= home[i];
			}
		}
		return cnt; //설치된 공유기의 개수 return하기
	}
	
	public static int getUpperbound(int left, int right, int target, int home[]) { //설치 가능한 공유기의 개수가 c를 초과하는 순간을 구한다
		while(left<=right) {
			int mid = (left + right)/2;
			int count = counterRounter(mid, home); //가장 인접한 두 공유기 사이의 거리가 mid이도록 공유기를 설치했을 때, 설치된 공유기의 총 개수
			
			if(count >= target)  //설치해야되는 개수보다 더 설치된 경우 -> 거리를 늘리기
				left = mid+1;
			else //설치해야되는 개수보다 적게 설치된 경우 -> 거리를 좁히기
				right = mid - 1;
			
		}
		return left;		
	}
	
	public static int solution(int n, int c, int home[]) {
		int answer = 0;
		//이분탐색은 정렬된 상태에서 진행됨
		Arrays.sort(home);
		answer = getUpperbound(1, home[n-1]-home[0], c, home)-1;  //공유기 사이의 최단 거리(left) = 1, 공유기 사이의 최장거리(right) = 가장 멀리있는 두 집 사이의 거리 = home[n-1] - home[0]
		//upperbound는 초과한 순간을 return 하므로 그 값에서 -1을 해줘야 최장거리가 나온다.
		return answer;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int N = Integer.parseInt(st.nextToken()); //집의 개수
		int C = Integer.parseInt(st.nextToken()); //공유기 개수
		
		int home[] = new int [N];
		
		for(int i=0;i<N;i++) {
			home[i] = Integer.parseInt(br.readLine()); 
		}
		
		System.out.println(solution(N, C, home));
		

	}

}
