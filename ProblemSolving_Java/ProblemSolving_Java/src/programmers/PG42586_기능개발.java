package programmers;

import java.util.ArrayList;
import java.util.List;

public class PG42586_기능개발 {

    public static void main(String[] args) {

        int[] progresses = {99, 99, 99};
        int[] speeds = {1, 1, 1};

        Solution solution = new Solution();
        int[] solution1 = solution.solution(progresses, speeds);
        for (int i : solution1) {
            System.out.println("i = " + i);
        }
    }

    static class Solution {
        public int[] solution(int[] progresses, int[] speeds) {
            List<Integer> answer = new ArrayList<>();

            int index = 0;
            for(int t=0; t<=100; t++) {

                int cnt = 0;
                while(index != progresses.length) {
                    if(100 <= progresses[index] + (speeds[index]*t)) {
                        cnt++;
                        index++;
                    }
                    else
                        break;
                }

                if(cnt!=0) answer.add(cnt);
            }

            return answer.stream().mapToInt(Integer::intValue).toArray();
        }
    }
}
