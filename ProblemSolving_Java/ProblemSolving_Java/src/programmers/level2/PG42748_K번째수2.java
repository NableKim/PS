package programmers.level2;

import java.util.Arrays;

public class PG42748_K번째수2 {

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

                int[] list = Arrays.copyOfRange(array, startIdx, endIdx+1);
                Arrays.sort(list);

                answer[i] = list[k];
            }

            return answer;
        }
    }

}
