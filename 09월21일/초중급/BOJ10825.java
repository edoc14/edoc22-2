import java.io.*;
import java.util.Arrays;
import java.util.Comparator;
import java.util.StringTokenizer;

public class BOJ10825 {	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st;
		
		int N = Integer.parseInt(br.readLine());
		Student[] stu = new Student[N];
		
		for(int i = 0; i < N; i++) {	// 과목 점수 입력
			st = new StringTokenizer(br.readLine());
			stu[i] = new Student(st.nextToken(), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		
		Comparator<Student> myCom = new Comparator<Student>() {
			@Override
			public int compare(Student o1, Student o2) {	// 1이 리턴되면 정렬 시 순서 바뀜.
				if(o1.kor < o2.kor) return 1;	// 국어 점수 비교
				else if(o1.kor == o2.kor) {
					if(o1.eng > o2.eng) return 1;	// 영어 점수 비교
					else if(o1.eng == o2.eng) {
						if(o1.math < o2.math) return 1;	// 수학 점수 비교
						else if(o1.math == o2.math) 
							return o1.name.compareTo(o2.name);	// 이름 비교
					}
				}
				return -1;
			}
		};
		
		Arrays.sort(stu, myCom);	// 선언한 Comparator로 sort.

		for(Student s : stu) System.out.println(s.name);
		
		bw.flush();
		bw.close();
		
	}
}

class Student {	// 과목 점수 저장할 클래스.
	String name;
	int kor, eng, math;
	
	Student(String name, int kor, int eng, int math) {
		this.name = name; this.kor = kor; this.eng = eng; this.math = math;
	}
}