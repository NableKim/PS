package programmers.level3;

public class PG1837_GPS {


    public static void main(String[] args) {

        int n=7;
        int m=10;
        int[][] edge_list = {{1, 2}, {1, 3}, {2, 3}, {2, 4}, {3, 4}, {3, 5}, {4, 6}, {5, 6}, {5, 7}, {6, 7}};
        int k = 6;
        int[] gps_log = {1, 2, 3, 3, 6, 7};

        Solution solution = new Solution();
        int answer = solution.solution(n, m, edge_list, k, gps_log);
        System.out.println("answer = " + answer);
    }

    static class Solution {

        final int INF = 1000;
        int[][] costs;
        boolean[][] edges;

        public int solution(int n, int m, int[][] edge_list, int k, int[] gps_log) {
            int answer = 0;

            edges = new boolean[n+1][n+1];
            costs = new int[k][n+1];

            // costs 무한값으로 초기화
            for(int i=0; i<k; i++) {
                for(int j=0; j<=n; j++) {
                    costs[i][j] = INF;
                }
            }

            // 간선 정보 메모
            for(int i=0; i<m; i++) {
                int aNode = edge_list[i][0];
                int bNode = edge_list[i][1];

                edges[aNode][bNode] = true;
                edges[bNode][aNode] = true;
            }

            // 시작 노드에 대한 비용 초기화
            costs[0][gps_log[0]] = 0;

            // 경로상 k개의 위치에 대하여
            for(int i=1; i<k; i++) {
                for(int curNode=1; curNode<=n; curNode++) {
                    int minVal = INF;
                    for (int preNode = 1; preNode <= n; preNode++) {
                        if (!edges[preNode][curNode]) continue;
                        if (costs[i - 1][preNode] == INF) continue;

                        minVal = minVal > costs[i - 1][preNode] ? costs[i - 1][preNode] : minVal;
                    }

                    if (curNode != gps_log[i]) minVal++;
                    costs[i][curNode] = minVal;
                }
            }

            if(costs[k-1][gps_log[k-1]] == INF)
                costs[k-1][gps_log[k-1]] = -1;
            return costs[k-1][gps_log[k-1]];
        }
    }
}
