import java.util.*;

public class Programmers_92343 {
	public static int dfs(int currIdx, int wolf, int sheep, ArrayList<Integer> nextNode, int[] info, ArrayList<Integer>[] adjList, int answer) {
		// 현재 위치에서 양/늑대 마릿수 갱신
		if(info[currIdx]==0) {
			sheep++;
		}
		else {
			wolf++;
		}
		
		// 현재 위치에서 양 마릿수와 최댓값 비교하여 갱신
		answer=Math.max(answer,sheep);
		
		// 늑대가 양보다 더 많거나 같으면 return
		if(wolf>=sheep) {
			return answer;
		}
		
		// 방문 가능한 노드 순차적으로 방문
		for(int i=0;i<nextNode.size();i++) {
			ArrayList<Integer> next=new ArrayList<>();	// 현재 노드에서 방문 가능한 리스트
			
			for(int j=0;j<nextNode.size();j++) {
				next.add(nextNode.get(j));	// 원래 있던 방문 리스트 next에 옮기기
			}
			next.remove(i); // 다음으로 방문할 노드는 리스트에서 삭제 후 매개변수로 전달
			
			for(int j=0;j<adjList[nextNode.get(i)].size();j++) { // 다음으로 방문할 노드와 인접한 노드들 next 리스트에 저장
				next.add(adjList[nextNode.get(i)].get(j));
			}
			
			// 다음 노드 방문
			answer=dfs(nextNode.get(i),wolf,sheep,next,info,adjList,answer);
		}
		
		return answer;
	}
	
	public static int solution(int[] info, int[][] edges) {
		int answer = 1;	// 루트 노드에 양이 있으므로 1로 초기화
		ArrayList<Integer>[] adjList=new ArrayList[info.length];	// 인접 리스트
		
		for(int i=0;i<info.length;i++) {	// 인접 리스트 선언
			adjList[i]=new ArrayList<>();
		}
		
		for(int i=0;i<edges.length;i++) {	// 인접 리스트에 인접한 노드 값 저장하기
			adjList[edges[i][0]].add(edges[i][1]);
		}
		
		ArrayList<Integer> nextNode=new ArrayList<>();	// 다음에 방문 가능한 노드 저장할 리스트
		for(int i=0;i<adjList[0].size();i++) {			// 루트 노드에서 방문 가능한 노드 차례로 저장하기
			nextNode.add(adjList[0].get(i));
		}
		
		// (현재 위치, 현재 늑대 마릿 수, 현재 양 마릿 수, 다음에 방문 가능한 노드 리스트, 노드 정보, 인접 노드 정보, 결과값)
		answer=dfs(0, 0, 0, nextNode, info, adjList, answer);
		
		return answer;
	}
}
