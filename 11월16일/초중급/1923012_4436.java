//실패한 코드입니다
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
			
			HashSet<Character> hs = new HashSet<Character>();
			for(int i=0; i<10; i++) hs.add((char)(i+'0'));
			
			long k = 0;
			while(!hs.isEmpty()) {
				k++;
				char[] str = Long.toString(k*n).toCharArray();
				
				for(char c: str) {
					if(hs.contains(c))hs.remove(c);
				}
			}
			
			System.out.print(k);
		}
		
	}

}
