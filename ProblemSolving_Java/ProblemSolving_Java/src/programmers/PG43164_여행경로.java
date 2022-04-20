package programmers;

import java.util.*;

public class PG43164_여행경로 {

    public static void main(String[] args) {
        //String[][] tickets = {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}};
        String[][] tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}};
        Solution solution = new Solution();
        String[] answer = solution.solution(tickets);
        for (String s : answer) {
            System.out.println("s = " + s);
        }
    }

    static class Solution {
        
        public boolean flag = false;    // 정답을 발견하였는가
        
        public void dfs(String curLocation, String[][] tickets, List<String> History, boolean[] visited, String[] answer) {

            if(flag)
                return;

            if(History.size()-1 == tickets.length) {
                flag = true;
                for(int i=0; i<History.size(); i++)
                    answer[i] = History.get(i);
                return;
            }

            for(int i=0; i< tickets.length; i++) {
                if(curLocation.equals(tickets[i][0]) && !visited[i]) {
                    visited[i] = true;
                    History.add(tickets[i][1]);
                    dfs(tickets[i][1], tickets, History, visited, answer);
                    History.remove(History.size()-1);
                    visited[i] = false;
                }
            }
        }

        public String[] solution(String[][] tickets) {

            boolean[] visited = new boolean[tickets.length];    // 티켓 사용 유무
            List<String> History = new ArrayList<>();           // 방문한 도시 순서
            History.add("ICN");

            Arrays.sort(tickets, new Comparator<String[]>() {
                @Override
                public int compare(String[] o1, String[] o2) {
                    if(o1[0].equals(o2[0]))
                        return o1[1].compareTo(o2[1]);
                    return o1[0].compareTo(o2[0]);
                }
            });

            String[] answer=new String[tickets.length+1];
            dfs("ICN", tickets, History, visited, answer);

            return answer;
        }
    }

}
