package programmers.level2;

import java.util.ArrayList;
import java.util.List;

public class PG67257_수식최대화 {

    public static void main(String[] args) {

        String expression = "100-200*300-500+20";
        Solution solution = new Solution();
        long solution1 = solution.solution(expression);
        System.out.println("solution1 = " + solution1);
    }

    static class Solution {

        String[] pick = {"+", "-", "*"};
        List<String> parsedList = new ArrayList<>();
        Long maxVal = -1L;

        public long solution(String expression) {
            long answer = 0;

            // 연산자, 피연산자를 배열에 담고
            String pre = "";
            for(int i=0; i<expression.length(); i++) {
                char ch = expression.charAt(i);
                if(ch == '+'
                        || ch == '-'
                        || ch == '*') {
                    parsedList.add(pre);
                    parsedList.add(ch+"");
                    pre="";
                }
                else
                    pre += ch;
            }
            parsedList.add(pre);

            // 연산자 우선순위를 순열로 구해서 계산
            SetPriority(0);

            return maxVal;
        }

        private void SetPriority(int depth) {

            if(depth == 3) {

                List<String> opList = new ArrayList<>(parsedList);
                for(int k=0; k<3; k++) {
                    List<String> tmp = new ArrayList<>();

                    int idx = 0;
                    while(idx < opList.size()) {
                        if(opList.get(idx).equals(pick[k])) {
                            tmp.set(tmp.size()-1, Long.toString(calculate(tmp.get(tmp.size()-1), pick[k], opList.get(idx+1))));
                            idx+=2;
                        }
                        else {
                            tmp.add(opList.get(idx));
                            idx++;
                        }
                    }

                    opList = tmp;
                }

                Long value = Math.abs(Long.parseLong(opList.get(0)));

                if(maxVal < value)
                    maxVal = value;

                return;
            }

            for(int i=depth; i<3; i++) {
                swap(i, depth);
                SetPriority(depth+1);
                swap(i, depth);
            }
        }

        private void swap(int idx1, int idx2) {
            String tmp = pick[idx1];
            pick[idx1] = pick[idx2];
            pick[idx2] = tmp;
        }

        private Long calculate(String op1, String operator, String op2) {

            Long n1 = Long.parseLong(op1);
            Long n2 = Long.parseLong(op2);

            if(operator.equals("+"))
                return n1+n2;
            else if(operator.equals("-"))
                return n1-n2;
            else
                return n1*n2;
        }
    }

}
