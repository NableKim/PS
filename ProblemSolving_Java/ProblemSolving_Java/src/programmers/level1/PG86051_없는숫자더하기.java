package programmers.level1;

public class PG86051_없는숫자더하기 {
    
    static class Solution {
        public int solution(int[] numbers) {
            int answer = 45;

            for(int i=0; i<numbers.length; i++)
                answer -= numbers[i];

            return answer;
        }
    }
}
