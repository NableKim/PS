package programmers;

public class PG81301_숫자문자열과영단어 {

    public static void main(String[] args) {

        String s = "one4seveneight";

        Solution solution = new Solution();

        int answer = solution.solution(s);
        System.out.println("answer = " + answer);
    }

    static class Solution {
        public int solution(String s) {
            int answer = 0;

            // 숫자면 스킵
            // 단어면 숫자까지 잘라서
                // 어떤 숫자인지 확인하고 추가

            String answerStr = "";

            int sIndex = 0;
            String tmpStr = "";
            while(sIndex < s.length()) {
                char currentChar = s.charAt(sIndex);

                if(isNumber(currentChar))
                    answerStr+=currentChar;
                else {
                    tmpStr += currentChar;

                    String numberStr = getNumberStr(tmpStr);

                    if(!numberStr.equals("X")) {
                        answerStr += numberStr;
                        tmpStr = "";
                    }
                }

                sIndex++;
            }

            answer = Integer.parseInt(answerStr);

            return answer;
        }

        private String getNumberStr(String tmpStr) {
            if(tmpStr.equals("zero"))
                return "0";
            else if(tmpStr.equals("one"))
                return "1";
            else if(tmpStr.equals("two"))
                return "2";
            else if(tmpStr.equals("three"))
                return "3";
            else if(tmpStr.equals("four"))
                return "4";
            else if(tmpStr.equals("five"))
                return "5";
            else if(tmpStr.equals("six"))
                return "6";
            else if(tmpStr.equals("seven"))
                return "7";
            else if(tmpStr.equals("eight"))
                return "8";
            else if(tmpStr.equals("nine"))
                return "9";
            else
                return "X";
        }

        private boolean isNumber(char charAt) {
            if(charAt >= '0' && charAt <= '9')
                return true;
            return false;
        }
    }
}


