package programmers.level2;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class PG42748_K번째수 {

    public static void main(String[] args) {

        int[] array = {1, 5, 2, 6, 3, 7, 4};
        int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};

        Solution solution = new Solution();
        int[] solution1 = solution.solution(array, commands);
        for (int i : solution1) {
            System.out.println("i = " + i);
        }

    }

    static class Solution {
        public int[] solution(int[] array, int[][] commands) {
            int[] answer = new int[commands.length];

            for(int i=0; i<commands.length; i++) {

                int startIdx = commands[i][0]-1;
                int endIdx = commands[i][1]-1;
                int k = commands[i][2]-1;

                List<Integer> list = new ArrayList<>();
                for(int s=startIdx; s<=endIdx; s++) {
                    list.add(array[s]);
                }

                Collections.sort(list);
                answer[i] = list.get(k);
            }

            return answer;
        }
    }

}
