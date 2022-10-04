import java.util.*;

public class Programmers_92343 {
	public static int dfs(int currIdx, int wolf, int sheep, ArrayList<Integer> nextNode, int[] info, ArrayList<Integer>[] adjList, int answer) {
		// ���� ��ġ���� ��/���� ������ ����
		if(info[currIdx]==0) {
			sheep++;
		}
		else {
			wolf++;
		}
		
		// ���� ��ġ���� �� �������� �ִ� ���Ͽ� ����
		answer=Math.max(answer,sheep);
		
		// ���밡 �纸�� �� ���ų� ������ return
		if(wolf>=sheep) {
			return answer;
		}
		
		// �湮 ������ ��� ���������� �湮
		for(int i=0;i<nextNode.size();i++) {
			ArrayList<Integer> next=new ArrayList<>();	// ���� ��忡�� �湮 ������ ����Ʈ
			
			for(int j=0;j<nextNode.size();j++) {
				next.add(nextNode.get(j));	// ���� �ִ� �湮 ����Ʈ next�� �ű��
			}
			next.remove(i); // �������� �湮�� ���� ����Ʈ���� ���� �� �Ű������� ����
			
			for(int j=0;j<adjList[nextNode.get(i)].size();j++) { // �������� �湮�� ���� ������ ���� next ����Ʈ�� ����
				next.add(adjList[nextNode.get(i)].get(j));
			}
			
			// ���� ��� �湮
			answer=dfs(nextNode.get(i),wolf,sheep,next,info,adjList,answer);
		}
		
		return answer;
	}
	
	public static int solution(int[] info, int[][] edges) {
		int answer = 1;	// ��Ʈ ��忡 ���� �����Ƿ� 1�� �ʱ�ȭ
		ArrayList<Integer>[] adjList=new ArrayList[info.length];	// ���� ����Ʈ
		
		for(int i=0;i<info.length;i++) {	// ���� ����Ʈ ����
			adjList[i]=new ArrayList<>();
		}
		
		for(int i=0;i<edges.length;i++) {	// ���� ����Ʈ�� ������ ��� �� �����ϱ�
			adjList[edges[i][0]].add(edges[i][1]);
		}
		
		ArrayList<Integer> nextNode=new ArrayList<>();	// ������ �湮 ������ ��� ������ ����Ʈ
		for(int i=0;i<adjList[0].size();i++) {			// ��Ʈ ��忡�� �湮 ������ ��� ���ʷ� �����ϱ�
			nextNode.add(adjList[0].get(i));
		}
		
		// (���� ��ġ, ���� ���� ���� ��, ���� �� ���� ��, ������ �湮 ������ ��� ����Ʈ, ��� ����, ���� ��� ����, �����)
		answer=dfs(0, 0, 0, nextNode, info, adjList, answer);
		
		return answer;
	}
}
