package programmers.level3;

import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class PG42627_디스크컨트롤러 {

    public static void main(String[] args) {
        int[][] jobs = {{0, 3}, {2, 6}, {1, 9}};
        Solution solution = new Solution();
        int answer = solution.solution(jobs);
        System.out.println("answer = " + answer);
    }

    static class Solution {

        PriorityQueue<int[]> pq = new PriorityQueue<>(new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                if (o1[1] == o2[1]) {
                    return o1[0] - o2[0];
                }
                return o1[1] - o2[1];
            }
        });

        public int solution(int[][] jobs) {


            // 요청 시간, 작업 시간을 기준으로 오름차순 정렬하기
            Arrays.sort(jobs, new Comparator<int[]>() {
                @Override
                public int compare(int[] o1, int[] o2) {
                    if (o1[0] == o2[0]) {
                        return o1[1] - o2[1];
                    }
                    return o1[0] - o2[0];
                }
            });

            int t = 0;      // 현재시간
            int index = 0;  // jobs index
            int sum = 0;    // 요청~종료 누적시간
            while (true) {
                // 현재 시간을 기준으로 실행시킬 수 있는 작업들을 힙에 넣기
                for (; index < jobs.length; index++) {
                    if (jobs[index][0] <= t)
                        pq.add(jobs[index]);
                    else
                        break;
                }

                // 만약 pq가 비어있다면, 현재 시간을 가장 먼저 온 요청 시간으로 세팅
                if (pq.isEmpty()) {

                    // 힙에 넣을 작업이 더 이상 존재하지 않는 경우
                    if (index == jobs.length) break;

                    pq.add(jobs[index]);
                    t = jobs[index][0];
                    index++;
                }

                // pq에서 top을 하나 꺼냄
                // 힙은 작업시간을 기준으로 제일 짧은 작업을 선택
                int[] top = pq.poll();

                sum += (t + top[1] - top[0]);   // 대기시간 누적
                t = t + top[1];               // 현재시간 변경
            }

            return sum / jobs.length;
        }

    }
}
