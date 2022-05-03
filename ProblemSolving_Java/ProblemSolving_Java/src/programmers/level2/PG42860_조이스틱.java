package programmers.level2;

import java.util.ArrayDeque;
import java.util.Deque;

public class PG42860_조이스틱 {

    public static void main(String[] args) {

        //String name = "JEROEN";
        //String name = "ABAABB";
        String name = "JAN";

        Solution solution = new Solution();
        int answer = solution.solution(name);
        System.out.println(answer);
    }

    static class Solution {

        Deque<Integer> dq = new ArrayDeque<>();

        public int solution(String name) {
            int answer = 0;

            for(int i=0; i<name.length(); i++) {
                if(name.charAt(i)=='A') continue;
                answer += getDiffVertical(name.charAt(i));
                if(i!=0)
                    dq.addLast(i);
            }

            answer += getDiffHorizontal(name.length());

            return answer;
        }

        private int getDiffVertical(char charAt) {
            int up = charAt - 'A';
            int down = 'Z' - charAt+1;

            return up<down? up: down;
        }

        // 0~name.length()-1 까지 원소 중에서 A가 아닌 지점까지의 거리
        private int getDiffHorizontal(int n) {

            int curIdx = 0;
            int sum = 0;
            while(!dq.isEmpty()) {
                int front = dq.peek();
                int back = dq.peekLast();

                if(curIdx < front) {
                    int left = curIdx + n - back;
                    int right = front - curIdx;

                    if(left < right) {
                        dq.pollLast();
                        curIdx = back;
                        sum += left;
                    }
                    else {
                        dq.poll();
                        curIdx = front;
                        sum += right;
                    }
                }
                else { // back < curIdx
                    int left = curIdx - back;
                    int right = front + n - curIdx;

                    if(left < right) {
                        dq.pollLast();
                        curIdx = back;
                        sum += left;
                    }
                    else {
                        dq.poll();
                        curIdx = front;
                        sum += right;
                    }
                }
            }

            return sum;
        }
        
    }

}