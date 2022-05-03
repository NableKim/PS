package programmers.level3;

import java.util.LinkedList;
import java.util.Queue;

public class PG43162_네트워크 {

    public static void main(String[] args) {

        int n=3;
        int[][] computers= {{1,1,0}, {1,1,0}, {0,0,1}};

        Solution solution = new Solution();
        int answer = solution.solution(n, computers);
        System.out.println("answer = " + answer);
    }

    static class Solution {

        boolean[] visited;

        public int solution(int n, int[][] computers) {
            int answer = 0;

            visited = new boolean[n];

            for(int i=0; i<n; i++) {
                if(!visited[i]) {
                    bfs(i, computers);
                    answer++;
                }
            }

            return answer;
        }

        public void bfs(int startNode, int[][] computers) {
            Queue<Integer> q = new LinkedList<>();

            visited[startNode] = true;
            q.add(startNode);

            while(!q.isEmpty()) {

                Integer front = q.poll();

                for(int k=0; k<computers.length; k++) {
                    if(k==front) continue;
                    if(computers[front][k]==1 && !visited[k]) {
                        visited[k]=true;
                        q.add(k);
                    }
                }
            }
        }
    }

}
