import java.util.Scanner;

public class Main 
{
    public static void main(String args[]) 
    {
        Scanner s = new Scanner(System.in);
        int A,B,C;
        A=s.nextInt();
        B=s.nextInt();
        C=s.nextInt();
        int N=0;
        if(B-C>=0)
        System.out.print("-1");
        else
        {
            while(A+(B-C)*N>=0)
        {
            ++N;
        }
        System.out.format("%d",N);
        }
    }
}