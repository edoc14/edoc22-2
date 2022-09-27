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
		
		for(int i = 0; i < N; i++) {
			st = new StringTokenizer(br.readLine());
			stu[i] = new Student(st.nextToken(), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()));
		}
		
		Comparator<Student> myCom = new Comparator<Student>() {
			@Override
			public int compare(Student o1, Student o2) {
				if(o1.kor < o2.kor) return 1;
				else if(o1.kor == o2.kor) {
					if(o1.eng > o2.eng) return 1;
					else if(o1.eng == o2.eng) {
						if(o1.math < o2.math) return 1;
						else if(o1.math == o2.math) 
							return o1.name.compareTo(o2.name);
					}
				}
				return -1;
			}
		};
		
		Arrays.sort(stu, myCom);
		
		//for(int i = 0; i < N; i++) 
		//	bw.write(stu[i].name + "\n");
		
		for(Student s : stu) 
			System.out.println(s.name);
		
		bw.flush();
		bw.close();
		
	}
}

class Student {
	String name;
	int kor, eng, math;
	
	Student(String name, int kor, int eng, int math) {
		this.name = name; this.kor = kor; this.eng = eng; this.math = math;
	}
}