package programmers.level1;

import java.util.ArrayList;
import java.util.List;

public class PG42840_모의고사2 {

    public static void main(String[] args) {

        int[] answers = {1,3,2,4,2};

        Solution solution = new Solution();
        int[] answer = solution.solution(answers);
        for (int i : answer) {
            System.out.println("i = " + i);
        }
    }

    static class Solution {

        public int getMaxValue(int a, int b) {
            return a>b? a: b;
        }

        final int[][] patterns = {
                {1, 2, 3, 4, 5},
                {2,1,2,3,2,4,2,5},
                {3,3,1,1,2,2,4,4,5,5}
        };

        int[] hits = new int[3];

        public int[] solution(int[] answers) {

            // 각 문제에 대하여
            for(int i=0; i< answers.length; i++) {
                // 각 사람에 대하여
                for(int k=0; k<3; k++) {
                    if(answers[i] == patterns[k][i%patterns[k].length])
                        hits[k]++;
                }
            }

            int maxVal = Math.max(hits[0], Math.max(hits[1], hits[2]));

            List<Integer> ansList = new ArrayList<>();
            for(int i=0; i<3; i++) {
                if(maxVal == hits[i]) ansList.add(i+1);
            }

            return ansList.stream().mapToInt(i->i).toArray();
        }
    }
}
