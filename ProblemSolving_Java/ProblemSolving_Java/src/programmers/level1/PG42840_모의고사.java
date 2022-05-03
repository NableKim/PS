package programmers.level1;

import java.util.ArrayList;
import java.util.List;

public class PG42840_모의고사 {

    public static void main(String[] args) {

    }

    static class Solution {

        public int getMaxValue(int a, int b) {
            return a>b? a: b;
        }

        public int[] solution(int[] answers) {


            int n = answers.length;

            int[] aAnswerList = new int[n];
            int[] bAnswerList = new int[n];
            int[] cAnswerList = new int[n];

            for(int i=0; i<n; i++) {
                aAnswerList[i] = (i%5)+1;
            }

            for(int i=0; i<n; i+=2) {
                bAnswerList[i] = 2;
            }

            int sec = 1;
            for(int i=1; i<n; i+=2) {
                bAnswerList[i] = sec;
                sec++;
                if(sec==2) sec++;
                else if(sec>5) sec =1;
            }

            int[] arr = {3, 1, 2, 4, 5};
            for(int i=0; i*2+1<n; i++) {
                cAnswerList[i*2] = arr[i%5];
                cAnswerList[i*2+1] = arr[i%5];
            }

            int aCnt = 0, bCnt =0, cCnt =0;
            for(int i=0; i<n; i++) {
                if(aAnswerList[i]==answers[i]) aCnt++;
                if(bAnswerList[i]==answers[i]) bCnt++;
                if(cAnswerList[i]==answers[i]) cCnt++;
            }

            int maxVal = getMaxValue(getMaxValue(aCnt, bCnt), cCnt);

            List<Integer> answer = new ArrayList<>();
            if(aCnt == maxVal) answer.add(1);
            if(bCnt == maxVal) answer.add(2);
            if(cCnt == maxVal) answer.add(3);

            return answer.stream().mapToInt(i->i).toArray();
        }
    }
}
