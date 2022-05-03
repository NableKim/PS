package programmers.level3;

import java.util.Collections;
import java.util.PriorityQueue;

public class PG42628_이중우선순위큐 {

    public static void main(String[] args) {

        //String[] operations = {"I 7","I 5","I -5","D -1"};
        //String[] operations = {"I 16","D 1"};
        //String[] operations = {"I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"};
        //String[] operations = {"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
        String[] operations = {"I 4", "I 3", "I 2", "I 1", "D 1", "D 1", "D -1", "D -1", "I 5", "I 6"};

        Solution solution = new Solution();
        int[] solution1 = solution.solution(operations);
        for (int i : solution1) {
            System.out.print(i + " ");
        }

    }

    static class Solution {

        PriorityQueue<Integer> max_pq = new PriorityQueue<>(Collections.reverseOrder());
        PriorityQueue<Integer> min_pq = new PriorityQueue<>();

        public int getSpaceIdx(String s) {
            for(int i=0; i<s.length(); i++) {
                if(s.charAt(i) == ' ')
                    return i;
            }
            return -1;
        }

        public int[] solution(String[] operations) {
            int[] answer = {0, 0};
            int deletedMaxCnt = 0;
            int deletedMinCnt = 0;

            for(String s : operations) {

                int spaceIdx = getSpaceIdx(s);
                String order = s.substring(0, spaceIdx);
                String numberStr = s.substring(spaceIdx+1);
                int number = Integer.parseInt(numberStr);

                if(order.equals("I")) {
                    max_pq.add(number);
                    min_pq.add(number);
                }
                else if(order.equals("D") && max_pq.size()-deletedMinCnt>0) {
                    if(number==1) {
                        max_pq.poll();
                        deletedMaxCnt++;
                    }
                    else {
                        min_pq.poll();
                        deletedMinCnt--;
                    }
                }

                if(max_pq.size()-deletedMinCnt==0 || min_pq.size()-deletedMaxCnt==0) {
                    max_pq.clear();
                    min_pq.clear();
                    deletedMaxCnt = deletedMaxCnt = 0;
                    continue;
                }

            }

            if(max_pq.size()-deletedMinCnt>0 && min_pq.size()-deletedMaxCnt>0) {
                answer[0] = max_pq.peek();
                answer[1] = min_pq.peek();
            }

            return answer;
        }
    }

}

