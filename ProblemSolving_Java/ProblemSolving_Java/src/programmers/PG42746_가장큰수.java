package programmers;

import java.util.*;

public class PG42746_가장큰수 {

    public static void main(String[] args) {
        int[] numbers = {0};
        //int[] numbers = {978, 97};
        //int[] numbers = {1, 10, 100, 1000};
        Solution solution = new Solution();
        String answer = solution.solution(numbers);
        System.out.println("answer = " + answer);
    }

    static class Solution {

        List<String> numberStrList = new ArrayList<>();

        public String solution(int[] numbers) {
            String answer = "";

            for(int n : numbers) {
                numberStrList.add(Integer.toString(n));
            }

            Collections.sort(numberStrList, new Comparator<String>() {
                @Override
                public int compare(String o1, String o2) {
                    String s1 = o1 + o2;
                    String s2 = o2 + o1;

                    return Integer.parseInt(s2) - Integer.parseInt(s1);
                }
            });


            for(String s : numberStrList) {
                answer += s;
            }

            if(!answer.isBlank() && answer.charAt(0) == '0')
                answer = "0";

            return answer;
        }
    }
}
