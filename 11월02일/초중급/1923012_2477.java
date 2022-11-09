import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st;
	    
	    int N = Integer.parseInt(br.readLine());
	    int[]arr = new int[6];
		//사각형의 가로 최대길이, 세로 최대길이를 구해서 큰 전체 부분의 너비부터 구함
	    int MaxWidthI=0,MaxWidth=0,MaxHeight=0,MaxHeightI=0,d;
	    for(int i=0;i<6;i++) {
	    	st = new StringTokenizer(br.readLine());
	    	d = Integer.parseInt(st.nextToken());
	    	arr[i]=Integer.parseInt(st.nextToken());
			//가로
	    	if((d==1 || d==2)&& MaxWidth<arr[i]) {
	    		MaxWidth=arr[i];
	    		MaxWidthI=i;
	    	}
			//세로
	    	else if((d==3 || d==4)&& MaxHeight<arr[i]){
	    		MaxHeight=arr[i];
	    		MaxHeightI=i;
	    	}
	    }
	    
		
		//비어있는 작은 사각형 영역의 너비를 구함
	    int right,left,minWidth,minHeight;
	    
	    if(MaxWidthI+1==6)right=0;
	    else right=MaxWidthI+1;
	    
	    if(MaxWidthI-1==-1)left=5;
	    else left=MaxWidthI-1;
	    //세로
	    minHeight=Math.abs(arr[right]-arr[left]);

	    if(MaxHeightI+1==6)right=0;
	    else right=MaxHeightI+1;
	    
	    if(MaxHeightI-1==-1)left=5;
	    else left=MaxHeightI-1;
	    //가로
	    minWidth=Math.abs(arr[right]-arr[left]);

		//정답 출력
	    System.out.println(((MaxWidth*MaxHeight)-(minHeight*minWidth)) * N);
	}
}
