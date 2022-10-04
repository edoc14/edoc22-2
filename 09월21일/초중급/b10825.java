import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class b10825 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc= new Scanner(System.in);
		int n= sc.nextInt();
		String[] student= new String[12];
		
		int [][] score= new int[12][4];//[i][0] 은 인덱스 번호 나중에 이름이랑 매치
		
		for(int i=0; i<n; i++) {//데이터 입력 받기
			student[i]=sc.next();				
			score[i][0]=i;
			for(int j=1; j<4; j++) {
				score[i][j]=sc.nextInt();
			}
		}
		
		Arrays.sort(score, new Comparator<int[]>() {
		    @Override
			public int compare(int[] o1, int[] o2) {
		    	 if(o1[1] == o2[1]) {
	                	 return o1[1] - o2[1];
		    	 }else {
		    		 return -o1[1] + o2[1]; 
		    	 }
	           }
	        });
		
		
		if(n==1) {
			System.out.println(student[0]);
		}
		else {
		for(int i=0; i<n-1; i++) {//비교의 기준점
			
				
				for(int j=i+1; j<n; j++) {//뒷 사람들이랑 비교 시작
					
					if(score[i][1]==score[j][1]) {//만약 국어 점수가 다음 사람이랑 같다면 뒤에 사람 인덱스는 j
						if(score[i][2]>score[j][2]) {//국어 점수가 같고 영어 점수가 더 작은 사람이 있으면 자리 바꾸기
						int tmp[]= new int[4];
						tmp=score[j];
						score[j]=score[i];
						score[i]=tmp;
					}
					
					if(score[i][1]==score[j][1] && score[i][2]==score[j][2]) {
							if(score[i][3]<score[j][3]) {
								int tmp[]= new int[4];
								tmp=score[j];
								score[j]=score[i];
								score[i]=tmp;
							
						}
						if(score[i][1]==score[j][1] && score[i][2]==score[j][2] && score[i][3]==score[j][3]) {
							if(student[score[i][0]].compareTo(student[score[j][0]])>0) {
								int tmp[]= new int[4];
								tmp=score[j];
								score[j]=score[i];
								score[i]=tmp;
							}
						}
					}
					
				}
				
			}
		}
		for(int i=0; i<n; i++) {
			System.out.println(student[score[i][0]]);
		}
	}
		/*
		//2차원 배열 잘 정렬되었는지 확인하는 코드
				for(int i=0; i<n; i++) {
					for(int j=0; j<4; j++) {
						System.out.print(score[i][j]+" ");
					}
					System.out.println();
				}
				*/
		
		
	}

}
