package edoc1005;

import java.util.ArrayList;
import java.util.Queue;
import java.util.Scanner;

public class b13565 {
	
	static int[][] graph;
	
	static boolean[][] check;
	
	static int m=0;
	
	static int n=0;
	
	static boolean flag;
	
	static int[] xx= {-1,1,0,0};
	
	static int[] yy= {0,0,1,-1};

	public static void dfs(int x, int y) {
		if(x==m-1) {
			flag=true;
			return;
		}
		
		else {
			for(int j=0; j<4; j++) {
				int xxx=x+xx[j];
				int yyy=y+yy[j];
				
				if(xxx>=0 && xxx<m && yyy>=0 && yyy <n && !check[xxx][yyy] && graph[xxx][yyy]==0) {
					check[xxx][yyy]=true;
					dfs(xxx,yyy);
				}
				
			}

		}
	}
	
	
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		m=sc.nextInt();//행의 갯수
		n=sc.nextInt();//열의 갯수

		graph= new int[m][n];
		
		flag=false;//전류가 통하면 flag를 true로 바꾼다
		
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				graph[i][j]=sc.nextInt();
			}
		}

		check= new boolean[m][n];
				
		for(int i=0; i<m; i++) {
			for(int j=0; j<n; j++) {
				System.out.print(graph[i][j]+" ");
			}
			System.out.println();
		}
		
		for(int i=0; i<n; i++) {
			
			if(flag) {
				break;
			}
			
			if(graph[0][i]==0){
				check= new boolean[m][n];
				check[0][i]=true;
				dfs(0,i);//한 행마다 다 훑기
			}
		}
		
		if(flag) {
			System.out.println("YES");
		}
		else {
			System.out.println("NO");
		}
		
		
		sc.close();
		
	}

}
