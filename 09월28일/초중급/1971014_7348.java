import java.io.*;
import java.util.*;

public class BOJ_7348 {
	public static void main(String[] args) throws IOException {
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		
		int T=Integer.parseInt(br.readLine());	// 테스트 케이스
		while(T-->0) {
			int N=Integer.parseInt(br.readLine());	// 이동 수
			int[][] movement=new int[N][2];			// 방과 방으로의 이동
			
			int[] dp=new int[201];
			
			for(int i=0;i<N;i++) {
				StringTokenizer st=new StringTokenizer(br.readLine());
				
				movement[i][0]=Integer.parseInt(st.nextToken()); // 출발지 저장
				movement[i][1]=Integer.parseInt(st.nextToken()); // 도착지 저장
				
				if(movement[i][0]>movement[i][1]) {	// 출발지의 방 번호가 도착지의 방 번호보다 작도록 저장
					int temp=movement[i][0];
					movement[i][0]=movement[i][1];
					movement[i][1]=temp;
				}
				
				for(int j=(movement[i][0]+1)/2;j<=(movement[i][1]+1)/2;j++) { // 작업하는 복도는 +1 해주기
					dp[j]+=1;
				}
			}
			
			Arrays.sort(dp);	// dp 배열 정렬
			
			System.out.println(dp[200]*10);	// 가장 큰 값*10 출력
		}
	}
}
