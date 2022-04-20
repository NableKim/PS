package programmers;

public class PG42862_체육복 {
    
    static class Solution {

        int[] student;

        public int solution(int n, int[] lost, int[] reserve) {

            student = new int[n+2];

            // 체육복 여분으로 가져온 사람 메모
            for(int i=0; i<reserve.length; i++)
                student[reserve[i]] = 1;

            // 체육복 잃어버린 사람들 체킹
            for(int i=0; i<lost.length; i++)
                student[lost[i]]--;

            int cnt = 0;
            for(int i=1; i<=n; i++) {
                if(student[i]<0) {
                    if(student[i-1]>0) {
                        student[i-1]--;
                        student[i]++;
                    }
                    else if(student[i+1]>0) {
                        student[i+1]--;
                        student[i]++;
                    } else
                        cnt++;
                }
            }

            return n-cnt;
        }
    }

}
