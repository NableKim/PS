package programmers.level2;

import java.util.Stack;

/*
스택 사용(오답)
 */

public class PG42584_주식가격2 {

    public static void main(String[] args) {
        int[] prices={1, 2, 3, 2, 3};
        //int[] prices={1, 2, 3, 2, 1};

        Solution solution = new Solution();
        int[] answer = solution.solution(prices);
        for (int i : answer) {
            System.out.println("i = " + i);
        }
    }

    static class Info {
        int idx;
        int val;
        boolean flag;
        public Info(int idx, int val, boolean flag) {
            this.idx = idx;
            this.val= val;
            this.flag = flag;
        }
    }

    static class Solution {

        Stack<Info> stack = new Stack<>();
        public int[] solution(int[] prices) {
            int[] answer = new int[prices.length];

            for(int i=0; i<prices.length; i++) {
                // 스택이 비어있는 경우
                if(stack.isEmpty()) {
                    stack.add(new Info(i, prices[i], false));
                    continue;
                }

                // 스택에 데이터가 존재하는 경우
                int top = stack.peek().val;
                if(top > prices[i]) {
                    stack.peek().flag = true;
                }

                stack.add(new Info(i, prices[i], false));
            }

            int cnt = 0;
            while(!stack.empty()) {
                Info front = stack.pop();

                if(front.flag == true) {
                    answer[front.idx] = 1;
                } else {
                    answer[front.idx] = cnt;
                }
                cnt++;
            }

            return answer;
        }
    }

}
