import java.util.Arrays;

public class Programmers_92342 {
	int[] answer;	// ���
    int[] ryan;		// ���̾��� �� ȭ��
    int maxDiff=0;  // �ִ� ���� ��
    
    // ���� ���� ���� �� ���� ���� ���� �� ���� �������� ���ϱ�
    public boolean compare() {
        for(int i=10;i>=0;i--) {
        	// ���� ���� �� ���� ������ ���
            if(ryan[i]>answer[i]) {
                return true;
            }
            else if(ryan[i]<answer[i]) {
                return false;
            }
        }
        
        return false;
    }
    
    // ���� ���
    public void calcScore(int[] apeach) {
        int apeachScore=0;  // ����ġ ����
        int ryanScore=0;    // ���̾� ����
        
        for(int i=0;i<11;i++) {
        	// ���̾��� �� ���� ���� ���
            if(ryan[i]>apeach[i]) {
                ryanScore+=10-i;
            }
            else if(apeach[i]>0) {
                apeachScore+=10-i;
            }
        }
        
        int diff=ryanScore-apeachScore; // ���� ��
        if(diff>0 && diff>=maxDiff) {
            // ������ ��찡 �ƴ� ��쿡�� �������� ����
            if(diff==maxDiff && !compare())
                return;
            // ������ ��� maxDiff�� answer ����
            maxDiff=diff;
            for(int i=0;i<11;i++) {
                answer[i]=ryan[i];
            }
        }
        
    }
    
    // ���̾��� ȭ�� ��� ���
    public void solve(int idx, int arrow, int[] apeach) {
        if(idx==11 || arrow==0) {
            ryan[10]+=arrow;
            calcScore(apeach);	// ���� ���
            ryan[10]-=arrow;
            return;
        }
        
        // ����ġ�� �ش� ������ ���� ȭ�� �������� ���̾��� ���� ������ ȭ���� �� ���� ���
        if(apeach[idx]<arrow) {
            ryan[idx]+=apeach[idx]+1;
            solve(idx+1,arrow-apeach[idx]-1,apeach);
            ryan[idx]-=apeach[idx]+1;
        }
        
        // �ش� ������ ȭ���� ���� �ʴ� ���
        solve(idx+1,arrow,apeach);
    }
    
    public int[] solution(int n, int[] info) {
        answer = new int[11];
        Arrays.fill(answer,-1);	// -1�� �ʱ�ȭ
        
        ryan=new int[11];
        
        solve(0,n,info);
        
        // ����ġ �������� ���ų� ���� ��� {-1} ��ȯ
        if(answer[0]==-1) {
            int[] loose={-1};
            return loose;
        }
        
        return answer;
    }
}
