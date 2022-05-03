package programmers.level3;

import java.util.ArrayList;
import java.util.List;

public class PG49191_순위 {

    public static void main(String[] args) {
        int n = 5;
        int[][] results = {{4, 3}, {4, 2}, {3, 2}, {1, 2}, {2, 5}};

        Solution solution = new Solution();
        int answer = solution.solution(n, results);

        System.out.println("answer = " + answer);
    }



    static class Solution {

        int[] win;  // 각 노드별 이긴 횟수
        int[] lose; // 각 노드별 진 횟수
        List<Integer>[] edges;

        public int solution(int n, int[][] results) {

            // 초기화
            init(n);

            // 간선 정보 저장
            setEdges(results);

            // 이기고 진 횟수 카운팅
            calculateMatchResults(n);

            return getAnswer(n);
        }

        private void calculateMatchResults(int n) {
            for(int i = 1; i<= n; i++) {
                boolean[] v = new boolean[n+1];
                DFS(i, i, v);
            }
        }

        private void setEdges(int[][] results) {
            for(int i = 0; i< results.length; i++) {
                edges[results[i][0]].add(results[i][1]);
            }
        }

        private int getAnswer(int n) {
            int answer = 0;
            for(int i = 1; i<= n; i++){
                if(win[i]+lose[i]== n-1) answer++;
            }
            return answer;
        }

        private void DFS(int baseNode, int curNode, boolean[] v) {

            v[curNode] = true;

            for(int i=0; i<edges[curNode].size(); i++) {
                int nextNode = edges[curNode].get(i);

                if(v[nextNode]) continue;

                win[baseNode]++;
                lose[nextNode]++;
                DFS(baseNode, nextNode, v);
            }

        }

        private void init(int n) {
            win = new int[n +1];
            lose = new int[n +1];
            edges = new ArrayList[n +1];
            for(int i = 0; i<= n; i++)
                edges[i] = new ArrayList<>();
        }
    }


}
