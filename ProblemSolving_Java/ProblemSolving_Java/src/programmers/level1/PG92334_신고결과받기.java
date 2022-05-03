package programmers.level1;

import java.util.HashMap;
import java.util.Map;

public class PG92334_신고결과받기 {
	
    boolean[][] R = new boolean[1000][1000];
    int[] C = new int[1000];
    
	public int[] solution(String[] id_list, String[] report, int k) {
        int[] answer = new int[id_list.length];
        
        // id�� index�� �ο�
        Map<String, Integer> idIndexMap = new HashMap<>();
        for(int i=0; i<id_list.length; i++) {
        	idIndexMap.put(id_list[i], i);
        }
        
        for(int i=0; i<report.length; i++) {
        	String[] username = report[i].split(" ");
        	int who = idIndexMap.get(username[0]);
        	int obj = idIndexMap.get(username[1]);
        	
        	if(R[who][obj]) continue;
        	R[who][obj] = true;
        	C[obj]++;
        }
        
        for(int i=0; i<id_list.length; i++) {
        	if(C[i]>=k) {
        		for(int j=0; j<id_list.length; j++) {
        			if(R[j][i]) answer[j]++;
        		}
        	}
        }
        
        return answer;
    }
}