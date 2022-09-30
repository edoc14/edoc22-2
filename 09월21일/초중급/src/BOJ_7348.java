import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class BOJ_7348 {
	public static class Room implements Comparable<Room> {
		int s,t,l;

		public Room(int s, int t) { //�� ū ���� t�� �����ϱ�
			if (s < t) {
				this.s = s;
				this.t = t;
			} else {
				this.s = t;
				this.t = s;
			}
			this.l = Math.abs(s - t); //���� ���� ����
		}

		@Override
		public int compareTo(Room o) {
			if (s == o.s) //������ ���� ���
				return Integer.compare(l, o.l); //���̷� ��
			return Integer.compare(s, o.s); //�������� ��
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
			list.add(new Room(s, t)); //����Ʈ�� �� �����ϱ�
		
			int time = 0;
			Collections.sort(list); //�������������� ����. ���������� ������ ������ ������������
			while(!list.isEmpty()) {
				t = Integer.MIN_VALUE;
				time += 10; //���� ��ġ�Ƿ� �ð��� �÷��ش�.
				ArrayList<Room> temp = new ArrayList<>();
				for(int k=0;k<list.size();k++) {  //�� ����Ʈ�� �ϳ��� ���캸��
					if(list.get(k).s>t) { //����Ʈ�� ���� ���� t���� ũ��
						t = list.get(i).t; //t�� �����ϱ�
					}
					else {
						temp.add(list.get(k)); //k��° ���� temp�迭�� �־��ش�
					}
				}
				list = temp;
			}
			sb.append(time+"\n");
		}
		System.out.println(sb.toString());
	}

}
