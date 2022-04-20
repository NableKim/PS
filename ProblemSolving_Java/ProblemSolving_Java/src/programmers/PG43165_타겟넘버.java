package programmers;

public class PG43165_타겟넘버 {

    public static void main(String[] args) {

    }

    static class Solution {

        public int dfs(int[] numbers, int depth, int cur, int target) {

            if(depth == numbers.length) {
                if(cur == target) return 1;
                return 0;
            }

            return dfs(numbers, depth+1, cur+numbers[depth], target)+dfs(numbers, depth+1, cur+(numbers[depth]*-1), target);
        }

        public int solution(int[] numbers, int target) {
            return dfs(numbers, 0, 0, target);
        }

    }

}
