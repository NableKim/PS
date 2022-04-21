package programmers;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class PG49189_가장먼노드 {

    public static void main(String[] args) {
        int n=6;
        int[][] edge = {{3, 6}, {4, 3}, {3, 2}, {1, 3}, {1, 2}, {2, 4}, {5, 2}};

        Solution solution = new Solution();
        int answer = solution.solution(n, edge);
        System.out.println("answer = " + answer);
    }

    static class Info {
        int node;   // 몇번 노드까지의 거리가
        int cost;   // 얼마이다

        public Info(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }
    }

    static class Solution {

        ArrayList<Integer>[] eList;
        boolean[] visited;  // V[] : 방문 체크
        int[] d;            // D[] : 한 정점에서 다른 정점까지의 거리
        final int INF = 987654321;
        PriorityQueue<Info> pq = new PriorityQueue<>(new Comparator<Info>() {
            @Override
            public int compare(Info o1, Info o2) {
                if(o1.cost == o2.cost) {
                    return o1.node - o2.node;
                }
                return o1.cost - o2.cost;
            }
        });

        private void init(int n) {
            eList = new ArrayList[n+1];
            for(int i=0; i<=n; i++) {
                eList[i] = new ArrayList<>();
            }

            // 방문 노드 및 노드 간 거리 데이터 초기화
            visited = new boolean[n+1];
            d = new int[n+1];
            for(int i=0; i<=n; i++)
                d[i] = INF;
        }

        private int getMaxVal(int n) {
            int maxVal = 0;
            for(int i = 1; i<= n; i++) {
                if(maxVal<d[i])
                    maxVal = d[i];
            }
            return maxVal;
        }

        private int getAnswer(int n, int maxVal) {
            int answer =0;
            for(int i = 1; i<= n; i++) {
                if(maxVal ==d[i])
                    answer++;
            }
            return answer;
        }

        private void dijkstra(int n, int[][] edge) {

            // 인접 리스트를 이용해서 간선 정보 저장
            for(int i=0; i<edge.length; i++) {
                int aNode = edge[i][0];
                int bNode = edge[i][1];

                eList[aNode].add(bNode);
                eList[bNode].add(aNode);
            }

            // 시작 노드 거리 초기화
            d[1] = 0;
            pq.add(new Info(1, 0));

            int cnt = 0;

            // 모든 노드를 방문할 때까지
            while(cnt<n) {

                int node = getMinDistanceNode(n);

                visited[node] = true;
                cnt++;

                // node와 인접한 노드에 대해서
                for(int j=0; j<eList[node].size(); j++) {
                    int k = eList[node].get(j);

                    if(d[k] > d[node] + 1) {
                        d[k] = d[node] + 1;
                        pq.add(new Info(k, d[k]));
                    }

                }
            }
        }

        // 미방문이면서 가장 거리가 가까운 노드 찾기
        private int getMinDistanceNode(int n) {
            while(!pq.isEmpty()) {
                Info top = pq.poll();
                if(!visited[top.node]) {
                    return top.node;
                }
            }
            return 0;
        }

        // 미방문이면서 가장 거리가 가까운 노드 찾기. (순차검색 버전)
//        private int getMinDistanceNode(int n) {
//
//            int minVal = INF;
//            int minNode = 0;
//
//            for(int i=1; i<=n ; i++) {
//                if(visited[i]) continue;
//                if(minVal > d[i]) {
//                    minVal = d[i];
//                    minNode = i;
//                }
//            }
//
//            return minNode;
//        }

        public int solution(int n, int[][] edge) {

            init(n);

            // 한 정점에서 다른 정점까지의 거리 구하기 >> 다익스트라 알고리즘
            dijkstra(n, edge);

            int maxVal = getMaxVal(n);  // D배열의 최대값 찾기
            int answer = getAnswer(n, maxVal);  // 최대값과 일치하는 노드는 몇개인지 카운팅

            return answer;
        }
    }


}
