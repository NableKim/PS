package programmers.level2;

import java.util.HashMap;
import java.util.Map;

public class PG42578_위장 {
    public static void main(String[] args) {

        String[][] clothes = {{"yellowhat", "headgear"}, {"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};

        Solution solution = new Solution();
        int solution1 = solution.solution(clothes);
        System.out.println("solution1 = " + solution1);
    }

    static class Solution {

        // 종류별 index
        Map<String, Integer> kindMap = new HashMap<>();
        int[] cnt = new int[31];
        int idx = 0;

        public int solution(String[][] clothes) {

            int answer = 1;

            for(int i=0; i<clothes.length; i++) {

                String kind = clothes[i][1];

                if(kindMap.containsKey(kind)) {
                    cnt[kindMap.get(kind)]++;
                }
                else {
                    kindMap.put(kind, idx);
                    cnt[idx]++;
                    idx++;
                }
            }

            for(int i=0; i<idx; i++)
                answer *= (cnt[i]+1);

            return answer-1;
        }
    }
}

