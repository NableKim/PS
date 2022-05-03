package programmers.level2;

import java.util.Arrays;

public class PG42747_HIndex {

    public static void main(String[] args) {
        //int[] citations = {0, 0, 1};
        int[] citations = {0, 1, 5, 6};
        //int[] citations = {3, 0, 6, 1, 5};
        //int[] citations = {0, 0, 0};
        //int[] citations = {1000, 1000, 1000};
        Solution solution = new Solution();
        int answer = solution.solution(citations);
        System.out.println("answer = " + answer);
    }

    static class Solution {
        public int solution(int[] citations) {

            Arrays.sort(citations);

            int answer = 0;
            for(int i=citations.length-1; i>=0; i--) {
                
                int cnt = citations.length - i; // 개수

                if(cnt >= citations[i]) {
                    answer = answer < citations[i]? citations[i]: answer;
                    break;
                }
                else if(citations[i] > 0){
                    answer = answer < cnt? cnt: answer;
                }
            }

            return answer;
        }
    }
}
