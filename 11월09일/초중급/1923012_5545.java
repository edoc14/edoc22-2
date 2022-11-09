//성공한 코드임
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		/*
		 * 입력값 받아오기
		 */
		
		//토핑의 종류 수
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer (br.readLine());
		
		//도우 가격, 토핑 하나당 가격
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		
		//도우의 열량
		int c = Integer.parseInt(br.readLine());
		
		//토핑별 열량
		int[] toppings = new int[n];	
		for(int i=0; i<n; i++) toppings[i] = Integer.parseInt(br.readLine());
		
		//토핑별 열량 오름차순 정렬
		Arrays.sort(toppings);
		
		/*
		 * 최고의 피자 찾기
		 */
		//각 경우에 대하여 계산한 1원당 열량을 모두 집어넣을 TreeSet
		TreeSet<Integer> ts = new TreeSet<Integer>();
		
		//가장 열량이 높은 토핑부터 하나씩 누적하여 추가하면서 계산
		int sum = c;	//현재까지 쌓인 열량
		int price = a;	//현재까지 쌓인 가격
		
		//아무 토핑도 올리지 않았을 때의 경우도 TreeSet에 넣어두기
		ts.add((int)Math.floor(sum/price));
		
		for(int i= n-1; i>=0; i--) {	//가장 열량이 큰 토핑부터
			sum += toppings[i];	//열량 추가
			price += b;			//가격 추가
			
			//1원당 열량을 TreeSet에 넣기
			ts.add((int)Math.floor(sum/price));
		}
		
		//정답 출력
		System.out.print(ts.last());

	}

}
