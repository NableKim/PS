package programmers.level4;

import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Queue;

public class PG81304_미로탈출2 {

    public static void main(String[] args) {

//        int n=3;
//        int start=1;
//        int end=3;
//        int[][] roads={{1,2,2}, {3,2,3}};
//        int[] traps = {2};

        int n=4;
        int start=1;
        int end=4;
        int[][] roads={{1,2,1}, {3,2,1}, {2,4,1}};
        int[] traps = {2,3};

        Solution solution = new Solution();
        int answer = solution.solution(n, start, end, roads, traps);
        System.out.println("answer = " + answer);
    }

    static class Solution {


        boolean[] isTrap;

        static class Info {
            int curNode;
            int cost;
            int[][] edges;

            public Info(int curNode, int cost, int[][] edges) {
                this.curNode = curNode;
                this.cost = cost;
                this.edges = edges;
            }
        }

        public int bfs(int startNode, int endNode, int n, int[][] edges) {

            PriorityQueue<Info> pq = new PriorityQueue<Info>(new Comparator<Info>() {
                @Override
                public int compare(Info o1, Info o2) {
                    return o1.cost - o2.cost;
                }
            });
            pq.add(new Info(startNode, 0, edges));

            while(!pq.isEmpty()) {

                Info front = pq.poll();

                if(front.curNode == endNode)
                    return front.cost;

                // 현재 노드가 트랩 노드가 아니라면
                // 현재 노드를 기준으로
                for(int nextNode=1; nextNode<=n; nextNode++) {
                    int[][] curNodeEdges = front.edges;
                    if(curNodeEdges[front.curNode][nextNode]!=0) {
                        if(isTrap[nextNode]) {
                            pq.add(new Info(nextNode, front.cost+curNodeEdges[front.curNode][nextNode], copyFlipEdges(n, nextNode, curNodeEdges)));
                        }
                        else {
                            pq.add(new Info(nextNode, front.cost+curNodeEdges[front.curNode][nextNode], copyEqualEdges(n, curNodeEdges)));
                        }
                    }
                }
            }

            return -1;
        }

        public int[][] copyFlipEdges(int n, int nextNode, int[][] curNodeEdges) {
            int[][] newEdges = new int[n+1][n+1];

            for(int y=0; y<n+1; y++) {
                if(y==nextNode) continue;
                for(int x=0; x<n+1; x++) {
                    if(x==nextNode) continue;
                    newEdges[y][x] = curNodeEdges[y][x];
                }
            }

            // nextNode를 시작점으로 하는 간선에 대해서
            for(int x=0; x<n+1; x++) {
                if(curNodeEdges[nextNode][x] != 0)
                    newEdges[x][nextNode] = curNodeEdges[nextNode][x];
            }

            // nextNode를 끝점으로 하는 간선에 대해서
            for(int y=0; y<n+1; y++) {
                if(curNodeEdges[y][nextNode] != 0)
                    newEdges[nextNode][y] = curNodeEdges[y][nextNode];
            }

            return newEdges;
        }

        public int[][] copyEqualEdges(int n, int[][] curNodeEdges) {
            int[][] newEdges = new int[n+1][n+1];

            for(int y=0; y<n+1; y++) {
                for(int x=0; x<n+1; x++) {
                    newEdges[y][x] = curNodeEdges[y][x];
                }
            }

            return newEdges;
        }

        public int solution(int n, int start, int end, int[][] roads, int[] traps) {
            int answer = 0;

            // 인접 행렬 크기 할당
            int[][] edges = new int[n+1][n+1];

            // 간선 정보로 인접 행렬 갱신
            for(int i=0; i< roads.length; i++) {
                int from = roads[i][0];
                int to = roads[i][1];
                int cost = roads[i][2];

                if(edges[from][to] == 0) {
                    edges[from][to] = cost;
                }
                else if(edges[from][to] > cost)
                    edges[from][to] = cost;
            }

            // 트랩 행렬 크기 할당
            isTrap = new boolean[n+1];

            // 트랩 여부 체크
            for(int i=0; i<traps.length; i++)
                isTrap[traps[i]] = true;

            return bfs(start, end, n, edges);
        }
    }
}
