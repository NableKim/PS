package programmers;

public class PG43238_입국심사 {

    public static void main(String[] args) {

        int n = 6;
        int[] times = {7, 10};

        Solution solution = new Solution();
        long answer = solution.solution(n, times);
        System.out.println("answer = " + answer);
    }

    static class Solution {

        public long solution(int n, int[] times) {
            return upperbound(0L, 1000000000000000000L, (long)n, times);
        }

        private long upperbound(long left, long right, long n, int[] times) {

            while(left<=right) {
                long mid = (left+right)/2;

                long sum = 0;
                for(int i=0; i<times.length; i++) {
                    long q = mid / (long)times[i];
                    sum += q;
                }

                if(n <= sum) right = mid-1;
                else left = mid+1;
            }

            return right+1;
        }
    }
}
