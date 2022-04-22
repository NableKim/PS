package programmers;

public class PG42842_카펫 {

    public static void main(String[] args) {

        Solution solution = new Solution();
        int[] answer = solution.solution(10, 2);
        for (int i : answer) {
            System.out.println("i = " + i);
        }
    }

    static class Solution {
        public int[] solution(int a, int b) {
            int[] answer = new int[2];

            double x1 = ((a+4) + Math.sqrt(Math.pow(a+4, 2) - (16*(a+b))))/4;
            double x2 = ((a+4) +-Math.sqrt(Math.pow(a+4, 2) - (16*(a+b))))/4;

            double y1 = (a +4 -(2*x1))/2;
            double y2 = (a +4 -(2*x2))/2;

            if(x1 >= y1) {
                answer[0]=(int)x1;
                answer[1]=(int)y1;
            }else {
                answer[0]=(int)x2;
                answer[1]=(int)y2;
            }

            return answer;
        }
    }

}
