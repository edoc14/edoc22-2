import java.util.*;

class Solution {
    public int[] solution(int n, int s) {
        int[] answer = new int[n];
        
        if(s/n==0)
            return new int[]{-1};
        
        Arrays.fill(answer, s/n);
        
        int sum = s/n*n;
        int idx=n-1;
        
        while(sum<s) {
        	answer[idx--]++;
        	sum++;
        }
        return answer;
  }
}