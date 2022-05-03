package programmers.level2;

import java.util.Stack;

/*
스택 사용(통과)
 */

public class PG42584_주식가격3 {

    public static void main(String[] args) {
        int[] prices={1, 2, 3, 2, 3};
        //int[] prices={1, 2, 3, 2, 1};

        Solution solution = new Solution();
        int[] answer = solution.solution(prices);
        for (int i : answer) {
            System.out.println("i = " + i);
        }
    }

    static class Solution {
        Stack<Integer> stack = new Stack<>();   // 시간 정보를 저장할 스택

        public int[] solution(int[] prices) {
            int[] answer = new int[prices.length];

            for(int i=0; i<prices.length; i++) {
                if(stack.isEmpty()) {
                    stack.add(i);
                    continue;
                }

                // 스택이 비어있지 않다면
                while(!stack.isEmpty()
                    && prices[stack.peek()] > prices[i]) {
                    int top = stack.pop();
                    answer[top] = i-top;    // interval 저장
                }

                stack.add(i);
            }

            while(!stack.isEmpty()) {
                int top = stack.pop();
                answer[top]=prices.length-1-top;
            }

            return answer;
        }
    }

}
