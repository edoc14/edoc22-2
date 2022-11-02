import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main{

	public static void main(String[] args)  throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader (new InputStreamReader(System.in));
		StringTokenizer st;
		
		int n = Integer.parseInt(br.readLine());
		
		int curx = 500;
		int cury = 500;
		
		TreeSet<Integer> xts = new TreeSet<Integer>();
		TreeSet<Integer> yts = new TreeSet<Integer>();
		int[] pattern = new int[4];
		
		for(int i =0; i<6; i++) {
			st = new StringTokenizer (br.readLine());
			pattern[i] = Integer.parseInt(st.nextToken());
			switch(pattern[i]) {
			case 1 :
				break;
			case 2 :
				break;
			case 3 :
				break;
			case 4 :
				break;
			}
		}

	}

}
