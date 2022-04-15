package programmers;

import java.util.HashMap;
import java.util.Map;

public class PG42576_완주하지못한선수 {

    public static void main(String[] args) {

        String[] participant = {"leo", "kiki", "eden"};
        String[] completion = {"kiki", "eden"};

        Solution solution = new Solution();
        String answer = solution.solution(participant, completion);
        System.out.println("answer = " + answer);
    }

    static class Solution {

        protected Map<String, Integer> compHashMap = new HashMap<>();
        protected Map<String, Integer> partHashMap = new HashMap<>();

        public String solution(String[] participant, String[] completion) {
            String answer = "";

            // cnt for participant info using hashmap
            for (String key : completion) {
                compHashMap.put(key, compHashMap.getOrDefault(key, 0)+1);
            }

            for (String key : participant) {
                partHashMap.put(key, partHashMap.getOrDefault(key, 0)+1);

                if(compHashMap.getOrDefault(key, 0) < partHashMap.getOrDefault(key, 0)) {
                    answer = key;
                    break;
                }
            }

            return answer;
        }
    }
}
