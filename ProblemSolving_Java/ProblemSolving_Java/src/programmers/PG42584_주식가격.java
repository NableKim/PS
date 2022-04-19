package programmers;

/*
완탐 방식(통과)
 */

public class PG42584_주식가격 {

    public static void main(String[] args) {
       // int[] prices={1, 2, 3, 2, 3};
        int[] prices={1, 2, 3, 2, 1};

        Solution solution = new Solution();
        int[] answer = solution.solution(prices);
        for (int i : answer) {
            System.out.println("i = " + i);
        }
    }

    static class Solution {

        public int[] solution(int[] prices) {
            int[] answer = new int[prices.length];

            for(int i=0; i<prices.length; i++) {
                int cnt = 0;
                for(int j=i+1; j< prices.length; j++) {
                    cnt++;
                    if(prices[i] > prices[j])   break;
                }
                answer[i] = cnt;
            }

            return answer;
        }
    }

}
