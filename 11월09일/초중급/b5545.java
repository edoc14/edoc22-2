package edoc1109;

import java.util.Arrays;
import java.util.Scanner;


public class b5545 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
			Scanner sc= new Scanner(System.in);
			int optioncnt= sc.nextInt();
			int doughprice= sc.nextInt();
			int optionprice= sc.nextInt();
			
			long totalprice=doughprice;//option이 하나씩 추가될 때마다 optionprice 하나씩 더하기
			
			int doughkcal= sc.nextInt();
			int optionkcal []= new int [optioncnt];
			
			for(int i=0; i<optioncnt; i++) {
				optionkcal[i]=sc.nextInt();
			}
			long totalkcal=doughkcal;
			long [] resultarray= new long[optioncnt+1];
			
			Arrays.sort(optionkcal);//오름차순 정렬
			
			
			for(int i=0; i<optioncnt+1; i++) {
				if(i>0) {
					totalprice+=optionprice;
				}
				
				if(i>0) {
					totalkcal+=optionkcal[optioncnt-i];
				}
				
				resultarray[i]=totalkcal/totalprice;
				
			}
			
			Arrays.sort(resultarray);
			
			System.out.println(resultarray[optioncnt]);
			
	}

}
