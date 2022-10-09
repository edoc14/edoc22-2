import java.util.Arrays;

public class Programmers_92342 {
	int[] answer;	// 결과
    int[] ryan;		// 라이언이 쏜 화살
    int maxDiff=0;  // 최대 점수 차
    
    // 점수 차이 같을 때 가장 낮은 점수 더 많이 맞혔는지 비교하기
    public boolean compare() {
        for(int i=10;i>=0;i--) {
        	// 낮은 점수 더 많이 맞혔을 경우
            if(ryan[i]>answer[i]) {
                return true;
            }
            else if(ryan[i]<answer[i]) {
                return false;
            }
        }
        
        return false;
    }
    
    // 점수 계산
    public void calcScore(int[] apeach) {
        int apeachScore=0;  // 어피치 점수
        int ryanScore=0;    // 라이언 점수
        
        for(int i=0;i<11;i++) {
        	// 라이언이 더 많이 맞힌 경우
            if(ryan[i]>apeach[i]) {
                ryanScore+=10-i;
            }
            else if(apeach[i]>0) {
                apeachScore+=10-i;
            }
        }
        
        int diff=ryanScore-apeachScore; // 점수 차
        if(diff>0 && diff>=maxDiff) {
            // 최적의 경우가 아닐 경우에는 갱신하지 않음
            if(diff==maxDiff && !compare())
                return;
            // 최적의 경우 maxDiff와 answer 갱신
            maxDiff=diff;
            for(int i=0;i<11;i++) {
                answer[i]=ryan[i];
            }
        }
        
    }
    
    // 라이언이 화살 쏘는 경우
    public void solve(int idx, int arrow, int[] apeach) {
        if(idx==11 || arrow==0) {
            ryan[10]+=arrow;
            calcScore(apeach);	// 점수 계산
            ryan[10]-=arrow;
            return;
        }
        
        // 어피치가 해당 점수에 맞힌 화살 개수보다 라이언이 현재 보유한 화살이 더 많은 경우
        if(apeach[idx]<arrow) {
            ryan[idx]+=apeach[idx]+1;
            solve(idx+1,arrow-apeach[idx]-1,apeach);
            ryan[idx]-=apeach[idx]+1;
        }
        
        // 해당 점수에 화살을 쏘지 않는 경우
        solve(idx+1,arrow,apeach);
    }
    
    public int[] solution(int n, int[] info) {
        answer = new int[11];
        Arrays.fill(answer,-1);	// -1로 초기화
        
        ryan=new int[11];
        
        solve(0,n,info);
        
        // 어피치 점수보다 낮거나 같은 경우 {-1} 반환
        if(answer[0]==-1) {
            int[] loose={-1};
            return loose;
        }
        
        return answer;
    }
}
