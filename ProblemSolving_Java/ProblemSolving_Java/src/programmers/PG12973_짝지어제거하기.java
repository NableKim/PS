package programmers;

import java.util.Stack;

public class PG12973_짝지어제거하기 {

    public static void main(String[] args) {

        String s = "cdcd";

        Solution solution = new Solution();

        int answer = solution.solution(s);
        System.out.println("answer = " + answer);

//        int[] answers = solution.solution();
//        for(int i=0; i<answers.length; i++)
//            System.out.println(answers[i] + " ");
    }

    static class Solution
    {

        Stack<Character> st = new Stack<>();

        public int solution(String s)
        {
            for(int i=0; i<s.length(); i++) {
                if(st.isEmpty()) {
                    st.add(s.charAt(i));
                    continue;
                }

                if(st.peek()==s.charAt(i)) {
                    st.pop();
                }
                else
                    st.add(s.charAt(i));
            }

            if(st.isEmpty()) return 1;
            return 0;
        }
    }
}
