package programmers.level2;

import java.util.*;

public class PG17679_프렌즈4블록 {

    public static void main(String[] args) {

        int m=4;
        int n=5;
        String[] board= {"CCBDE", "AAADE", "AAABF", "CCBBF"};

        Solution solution = new Solution();

        int answer = solution.solution(m, n, board);

        System.out.println("answer = " + answer);

    }

    static class Solution {

        static class Point {
            int y;
            int x;

            public Point(int y, int x) {
                this.y = y;
                this.x = x;
            }

            @Override
            public boolean equals(Object o) {
                if (this == o) return true;
                if (o == null || getClass() != o.getClass()) return false;
                Point point = (Point) o;
                return y == point.y && x == point.x;
            }

            @Override
            public int hashCode() {
                return Objects.hash(y, x);
            }
        }

        public char[][] map;
        public int[] dy = {0, 1, 1};
        public int[] dx = {1, 0, 1};

        public int solution(int m, int n, String[] board) {
            int answer = 0;

            // 주어진 map을 char[][]로 변환
            map = new char[m][n];

            for(int i=0; i<board.length; i++) {
                map[i] = board[i].toCharArray();
            }

            while(true) {

                boolean flag = false;
                Set<Point> erasePointSet = new HashSet<>();

                for(int y=0; y<m-1; y++) {
                    for(int x=0; x<n-1; x++) {
                        if(map[y][x] == ' ') continue;

                        if(canBeErased(y, x, map)) {
                            erasePointSet.add(new Point(y, x));
                            for(int k=0; k<3; k++) {
                                erasePointSet.add(new Point(y+dy[k], x+dx[k]));
                            }
                            flag = true;
                        }
                    }
                }

                if(!flag) break;
                answer += erasePointSet.size();

                // 수집한 좌표 정보를 기반으로 지우기
                Iterator<Point> iter = erasePointSet.iterator();
                while(iter.hasNext()) {
                    Point point = iter.next();
                    map[point.y][point.x] = ' ';
                }

                for(int x=0; x<n; x++) {
                    List<Character> letterList = new ArrayList<>();

                    for(int y=m-1; y>=0; y--) {
                        if(map[y][x] != ' ') {
                            letterList.add(map[y][x]);
                            map[y][x] = ' ';
                        }
                    }

                    int yIdx = m-1;
                    for (Character character : letterList) {
                        map[yIdx--][x] = character;
                    }
                }
            }

            return answer;
        }

        private boolean canBeErased(int y, int x, char[][] map) {
            char baseLetter = map[y][x];
            for(int k=0; k<3; k++) {
                if(map[y+dy[k]][x+dx[k]] != baseLetter)
                    return false;
            }
            return true;
        }
    }

}
