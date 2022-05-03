package programmers.level2;

import java.util.ArrayList;
import java.util.List;

public class PG42586_기능개발2 {

    public static void main(String[] args) {

        int[] progresses = {95, 90, 99, 99, 80, 99};
        //int[] progresses = {99, 99, 99};
        int[] speeds = {1, 1, 1, 1, 1, 1};
        //int[] speeds = {1, 1, 1};

        Solution solution = new Solution();
        int[] solution1 = solution.solution(progresses, speeds);
        for (int i : solution1) {
            System.out.println("i = " + i);
        }
    }

    static class Solution {
        public int[] solution(int[] progresses, int[] speeds) {
            List<Integer> answer = new ArrayList<>();

            // Queue 구조를 사용해서
            // 맨 처음에 위치한 작업이 100을 달성하기 위해서 몇초가 흘러야하는가 -> t초
            // t초가 흘렀을때 같이 배포될 수 있는 작업들을 함께 배포시킴

            int index = 0;

            while(index != progresses.length) {

                int t = (100-progresses[index])/speeds[index];
                if((100-progresses[index])%speeds[index]!=0)
                    t++;

                int cnt =0;
                while(index != progresses.length &&
                        progresses[index]+(speeds[index]*t)>=100) {
                    index++;
                    cnt++;
                }

                answer.add(cnt);
            }

            return answer.stream().mapToInt(Integer::intValue).toArray();
        }
    }
}
