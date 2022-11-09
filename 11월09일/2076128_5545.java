import java.io.*;
import java.util.*;

public class BOJ5545 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N, A, B, C;
		
		N = Integer.parseInt(br.readLine()); 	// 토핑 종류 수
		int[] D = new int[N];	
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		A = Integer.parseInt(st.nextToken()); 	// 도우 가격
		B = Integer.parseInt(st.nextToken()); 	// 토핑 가격
		
		C = Integer.parseInt(br.readLine());	// 도우 열량
		
		for(int i = 0; i < N; i++) {
			D[i] = Integer.parseInt(br.readLine());	// 각 토핑의 열량
		}
		Arrays.sort(D); // 오름차순 정렬
		
		int cost = A, kcal = C;	// 도우만 있는 상태
		double best = C / A;
		double temp = 0;
		
		for(int i = N-1; i >= 0; i--) { // 배열이 오름차순으로 정렬되어있으므로 거꾸로.
			// 열량이 높은 순서대로 토핑을 추가해본다.
			temp = (kcal + D[i]) / (cost + B);
			
			if(best > temp) {
				// 이전보다 열량이 낮아졌다면 break. 기존의 상태가 최고의 피자이다.
				// 토핑 자체의 가격은 같고 토핑 열량은 점차 줄어든다.
				// 따라서 한 번 떨어진 '1원당 열량'은 다시 증가하지않음
				break;
			}
			else { 
				// 이전보다 열량이 증가했다면 현재 상태를 저장.
				kcal += D[i];
				cost += B;
				best = temp;
			}
		}
		
		System.out.print((int)best);
	}
}
