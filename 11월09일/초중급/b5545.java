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
			
			long totalprice=doughprice;//option�� �ϳ��� �߰��� ������ optionprice �ϳ��� ���ϱ�
			
			int doughkcal= sc.nextInt();
			int optionkcal []= new int [optioncnt];
			
			for(int i=0; i<optioncnt; i++) {
				optionkcal[i]=sc.nextInt();
			}
			long totalkcal=doughkcal;
			long [] resultarray= new long[optioncnt+1];
			
			Arrays.sort(optionkcal);//�������� ����
			
			
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
