package programmers.level2;

import java.util.LinkedList;
import java.util.Queue;

public class PG81302_거리두기확인하기 {

    public static void main(String[] args) {

        String[][] places = {{"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};
        //String[][] places = {{"XXXXX", "XXXXX", "XXXXX", "XXXXX", "XXXXX"}, {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}};

        Solution solution = new Solution();

        int[] answers = solution.solution(places);
        for(int i=0; i<answers.length; i++)
            System.out.println(answers[i] + " ");
    }

    static class Info {
        int y;
        int x;
        int dis;
        public Info(int y, int x, int dis) {
            this.y = y;
            this.x = x;
            this.dis = dis;
        }
    }

    static class Solution {

        int[] dy = { -1, 0, 1, 0};
        int[] dx = { 0 ,-1, 0, 1};

        public int[] solution(String[][] places) {
            int[] answer = new int[5];

            for(int i=0; i<5; i++) {
                answer[i] = checkSeatIsSafe(places[i]);
            }

            return answer;
        }

        public int checkSeatIsSafe(String[] map) {
            for(int y=0; y<5; y++) {
                for(int x=0; x<5; x++) {
                    if(map[y].charAt(x) == 'P') {
                        if(!bfs(y, x, map)) return 0;
                    }
                }
            }
            return 1;
        }

        public boolean bfs(int sy, int sx, String[] map) {

            Queue<Info> q = new LinkedList<>();
            boolean[][] visited = new boolean[5][5];

            visited[sy][sx] = true;
            q.add(new Info(sy, sx, 0));

            while(!q.isEmpty()) {

                Info front = q.poll();

                // 맨허튼 거리 2이하까지만 확인
                if(front.dis >= 2)  break;

                for(int k=0; k<4; k++) {
                    int ny = front.y + dy[k];
                    int nx = front.x + dx[k];

                    // 좌표 밖을 넘어가는 경우
                    if(!isValidPointLocation(ny, nx)) continue;;

                    // 이미 방문한 경우
                    if(visited[ny][nx]) continue;

                    // 파티션을 의미하는 경우
                    if(map[ny].charAt(nx)=='X') continue;

                    // 맨허튼 거리 2이하인 곳에 사람이 있는 경우
                    if(map[ny].charAt(nx) == 'P')
                        return false;

                    visited[ny][nx] = true;
                    q.add(new Info(ny, nx, front.dis+1));
                }
            }
            return true;
        }

        public boolean isValidPointLocation(int y, int x) {
            if(y<0 || y>=5 || x<0 || x>=5)
                return false;
            return true;
        }
    }
}
