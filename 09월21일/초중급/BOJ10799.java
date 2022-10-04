import java.io.*;
import java.util.Stack;

public class BOJ10799 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String str = br.readLine();
		int cnt = 0;	// 총 막대기 수
		Stack<Character> st = new Stack<>();	// 스택
		
		for(int i = 0; i < str.length(); i++) {
			if(str.charAt(i) == '(') st.push('('); // '('일 경우 스택 push.
			else {	// ')'일 경우 스택 pop.
				st.pop();
				// 레이저 '()'인 경우, 스택에 쌓인 수 만큼 조각이 생긴다.
				if(str.charAt(i - 1) == '(') cnt += st.size();
				// 막대기 끝 ')'인 경우, 레이저 없이 조각수 +1
				else cnt += 1;
			}
		}
		
		System.out.println(cnt);
	}
}
