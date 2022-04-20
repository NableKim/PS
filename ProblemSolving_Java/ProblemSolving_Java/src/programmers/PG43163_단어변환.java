package programmers;

import java.util.LinkedList;
import java.util.Queue;

public class PG43163_단어변환 {

    public static void main(String[] args) {
        String begin="hit";
        String target="cog";
        //String[] words={"hot", "dot", "dog", "lot", "log", "cog"};
        String[] words={"hot", "dot", "dog", "lot", "log"};

        Solution solution = new Solution();
        int answer = solution.solution(begin, target, words);
        System.out.println("answer = " + answer);

    }

    static class Info {
        String str;
        int cnt;

        public Info(String str, int cnt) {
            this.str = str;
            this.cnt = cnt;
        }
    }

    static class Solution {

        boolean[] visited;

        public int bfs(String begin, String target, String[] words) {

            Queue<Info> q = new LinkedList<>();
            q.add(new Info(begin, 0));

            while(!q.isEmpty()) {

                Info front = q.poll();
                if(front.str.equals(target))
                    return front.cnt;

                for(int k=0; k<words.length; k++) {

                    if(visited[k])
                        continue;

                    int cnt = 0;
                    for(int i=0; i<begin.length(); i++) {
                        if(front.str.charAt(i) != words[k].charAt(i)) cnt++;
                    }

                    if(cnt == 1) {
                        q.add(new Info(words[k], front.cnt+1));
                        visited[k]=true;
                    }
                }
            }

            return 0;
        }

        public int solution(String begin, String target, String[] words) {
            visited = new boolean[words.length];
            return bfs(begin, target, words);
        }
    }
}
