import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;

public class Main {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		String input = null;
		
		while((input=br.readLine()) != (null)) {
			long n = Long.parseLong(input);
      
			//0부터 9까지의 숫자가 담겨있는 해시셋 선언
			HashSet<Character> hs = new HashSet<Character>();
			for(int i=0; i<10; i++) hs.add((char)(i+'0'));
			
      //초기값이 0인 k 선언
			long k = 0;
			while(true) {
				k++;  //k를 1 증가시킴
				String str = Long.toString(k*n);  //곱셈
				for(int i=0; i<str.length(); i++) hs.remove(str.charAt(i)); //곱셈 결과값에 등장하는 모든 숫자를 해시셋에서 제거
				if(hs.isEmpty()) break; //해시셋이 텅 비게 되었다면 정답이 도출된 것이므로 break
			}
			
			System.out.println(k);
		}
		
	}

}
