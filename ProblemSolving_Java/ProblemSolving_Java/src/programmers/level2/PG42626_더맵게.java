package programmers.level2;

import java.util.PriorityQueue;

public class PG42626_더맵게 {

    public static void main(String[] args) {

        int[] scoville = {1, 2, 3, 9, 10, 12};
        int K = 7;

        Solution solution = new Solution();
        int answer = solution.solution(scoville, K);
        System.out.println("answer = " + answer);
    }

    static class Solution {

        PriorityQueue<Integer> pq = new PriorityQueue<>();


        public int solution(int[] scoville, int K) {
            int answer = 0;

            for(int n : scoville) {
                pq.add(n);
            }

            while(pq.peek() < K && pq.size() >= 2) {
                int n1 = pq.poll();
                int n2 = pq.poll();

                if(n2==0)
                    return -1;

                int newNumber = n1+(n2*2);

                pq.add(newNumber);
                answer++;
            }

            if(pq.peek() < K)
                answer = -1;

            return answer;
        }
    }
}
