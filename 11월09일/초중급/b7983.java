package edoc1109;

import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;



public class b7983 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc= new Scanner(System.in);
		
		
		int n=sc.nextByte();//해야할 과제 종류
		
		
		
		int arr[][]= new int[n][2];
		
		for(int i=0; i<n; i++) {
			arr[i][0]=sc.nextInt();
			arr[i][1]=sc.nextInt();
		}
		
		
		for(int i=0; i<n; i++) {//maxti찾기
			
		}
		
		Arrays.sort(arr, new Comparator<int[]>() {
		    @Override
		    public int compare(int[] o1, int[] o2) {

		        return o2[1]-o1[1]; // 두번째 숫자 기준 내림차순 {3,50}{5,40}{1,30}{4,20}{2,10}
		    }
		});
		
		
		
		int day=arr[0][1];
		
		
		for(int i=0; i<n; i++) {
			
			if(arr[i][1]<day) {
				day=arr[i][1];
				day=day-arr[i][0];
			}
			else {
			day=day-arr[i][0];
			}
		}
		
		
		System.out.println(day);
		
		sc.close();
		
	}
}
