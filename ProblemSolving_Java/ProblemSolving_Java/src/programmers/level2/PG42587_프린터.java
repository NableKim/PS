package programmers.level2;

import java.util.*;

public class PG42587_프린터 {

    public static void main(String[] args) {
        int[] priorities = {2, 1, 3, 2};
        int location = 2;

        Solution solution = new Solution();
        int solution1 = solution.solution(priorities, location);
        System.out.println("solution1 = " + solution1);
    }

    static class Info {
        int idx;
        int value;

        Info(int idx, int value) {
            this.idx = idx;
            this.value = value;
        }
    }

    static class Solution {

        PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        Queue<Info> q = new LinkedList<>();

        public int solution(int[] priorities, int location) {

            for(int i=0; i<priorities.length; i++) {
                pq.add(priorities[i]);
                q.add(new Info(i, priorities[i]));
            }

            int answer = 0;
            while(!q.isEmpty()) {
                Info front = q.poll();
                if(front.value == pq.peek()) {
                    pq.poll();
                    answer++;
                    if(front.idx == location)
                        break;
                }
                else {
                    q.add(front);
                }
            }

            return answer;
        }
    }
}
