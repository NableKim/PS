package programmers.level4;

import java.util.Comparator;
import java.util.PriorityQueue;

public class PG81304_미로탈출 {

    public static void main(String[] args) {

        int n=4;
        int start=1;
        int end=4;
        //int[][] roads={{1,2,2},{3,2,3}};
        int[][] roads={{1, 2, 1}, {3, 2, 1}, {2, 4, 1}};
        //int[] traps = {2};
        int[] traps = {2, 3};

        Solution solution = new Solution();
        int answer = solution.solution(n, start, end, roads, traps);
        System.out.println("answer = " + answer);
    }

    static class Solution {

        final int INF = 1000000000;
        int[][][] edges;
        boolean[] isTrap;
        int[][] minCost;

        public int solution(int n, int start, int end, int[][] roads, int[] traps) {

            // 간선정보 -> 짝수 방문, 홀수 방문
            edges = new int[2][n+1][n+1];
            

            // 간선 정보 메모
            for(int i=0; i<roads.length; i++) {
                int from = roads[i][0];
                int to = roads[i][1];
                int cost = roads[i][2];

                edges[0][from][to] = cost;
                edges[1][to][from] = cost;
            }
            
            // 트랩 여부를 체크할 배열
            isTrap = new boolean[n+1];

            // 트랩 여부 체크
            for(int i=0; i<traps.length; i++) {
                isTrap[traps[i]] = true;
            }
            
            // 각 노드까지 최단 거리 메모
            minCost = new int[2][n+1];
            for(int i=0; i<=n; i++) {
                minCost[0][i] = INF;
                minCost[1][i] = INF;
            }

            int answer = bfs(start, end, n);

            return answer;
        }

        public int bfs(int start, int end, int n) {

            minCost[0][start] = 0;
            minCost[1][start] = 0;

            // 몇번 노드이고, 각 노드별 몇번째 방문인지 체크헤둔 배열, 지금까지 비용
            PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
                @Override
                public int compare(Info o1, Info o2) {
                    return o1.cost - o2.cost;
                }
            });

            pq.add(new Info(start, 0, createVisitArray(n, start, new int[n+1])));

            while(!pq.isEmpty()) {
                Info front = pq.poll();

                if(front.node == end)
                    return front.cost;

                int eIdx = 0;
                if(isTrap[front.node]) {
                    eIdx = (front.visit[front.node]) % 2;
                }

                for(int nextNode=1; nextNode<=n; nextNode++) {
                    int cost =edges[eIdx][front.node][nextNode];
                    if(cost>0 && minCost[eIdx][nextNode] > front.cost+cost) {
                        minCost[eIdx][nextNode] = front.cost+cost;
                        pq.add(new Info(nextNode, front.cost+cost, createVisitArray(n, nextNode, front.visit)));
                    }
                }
            }

            return -1;
        }

        public int[] createVisitArray(int n, int curNode, int[] visit) {
            int[] newVisit= new int[n+1];

            for(int i=1; i<=n; i++)
                newVisit[i] = visit[i];
            visit[curNode] = (visit[curNode]+1)%2;
            return visit;
        }

        static class Info {
            int node;
            int cost;
            int[] visit;

            public Info(int node, int cost, int[] visit) {
                this.node = node;
                this.cost = cost;
                this.visit = visit;
            }
        }
    }

}
