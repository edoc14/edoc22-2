import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ_7348 {
	public static class Room implements Comparable<Room> {
		int s,t,l;

		public Room(int s, int t) { //더 큰 값을 t에 저장하기
			if (s < t) {
				this.s = s;
				this.t = t;
			} else {
				this.s = t;
				this.t = s;
			}
			this.l = Math.abs(s - t); //둘의 길이 차이
		}

		@Override
		public int compareTo(Room o) {
			if (s == o.s) //시작이 같은 경우
				return Integer.compare(l, o.l); //길이로 비교
			return Integer.compare(s, o.s); //시작으로 비교
		}
	};

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		StringTokenizer st;
		StringBuilder sb = new StringBuilder();
		int s,t, N;
		ArrayList<Room> list = new ArrayList<>();
		for(int i=0;i<T;i++) {
			N = Integer.parseInt(br.readLine());
			st = new StringTokenizer(br.readLine());
			s = Integer.parseInt(st.nextToken());
			t = Integer.parseInt(st.nextToken());
			list.add(new Room(s, t)); //리스트에 방 저장하기
		
			int time = 0;
			Collections.sort(list); //시작지점순으로 정렬. 시작지점이 같으면 길이의 오름차순으로
			while(!list.isEmpty()) {
				t = Integer.MIN_VALUE;
				time += 10; //방이 겹치므로 시간을 늘려준다.
				ArrayList<Room> temp = new ArrayList<>();
				for(int k=0;k<list.size();k++) {  //방 리스트를 하나씩 살펴보기
					if(list.get(k).s>t) { //리스트의 시작 값이 t보다 크면
						t = list.get(i).t; //t값 갱신하기
					}
					else {
						temp.add(list.get(k)); //k번째 방을 temp배열에 넣어준다
					}
				}
				list = temp;
			}
			sb.append(time+"\n");
		}
		System.out.println(sb.toString());
	}

}
