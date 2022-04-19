package programmers;

import java.util.LinkedList;
import java.util.Queue;

public class PG42583_다리를지나는트럭 {

    public static void main(String[] args) {
        int bridge_length=100;
        int weight=100;
        int[] truck_weights={10,10,10,10,10,10,10,10,10,10};

        Solution solution = new Solution();
        int answer = solution.solution(bridge_length, weight, truck_weights);
        System.out.println("answer = " + answer);
    }

    static class Info {
        int t;
        int w;

        public Info(int t, int w) {
            this.t = t;
            this.w = w;
        }

    }

    static class Solution {

        Queue<Info> q = new LinkedList<>();

        public int solution(int bridge_length, int weight, int[] truck_weights) {
            int answer = 0;
            int bw = 0; // 다리 위에 올라가있는 트럭의 총 무게
            int index = 0;

            // 매초마다
            while(true) {

                // 대기중인 트럭, 다리위에 있는 트럭 모두 없는 경우 끝내기
                if(q.isEmpty() && index == truck_weights.length)
                    break;

                // 다리에 있는 트럭이 빠져나올 시간이 되었다면
                // 다리의 무게를 감소시킴
                if(!q.isEmpty() && q.peek().t<=answer) {
                    bw-=q.peek().w;
                    q.poll();
                }

                // 대기줄에 있는 트럭이 다리에 올라올 수 있는지 확인(다리에 가해지는 현재 무게+들어갈 트럭의 무게 <=weight)
                // 가능하다면, 다리 위에 있는 큐에 트럭의 무게와 트럭이 언제 빠져나갈 수 있는지 기록
                if(index != truck_weights.length
                    && q.size() < bridge_length
                    && bw+truck_weights[index]<=weight) {

                    q.add(new Info(answer+bridge_length, truck_weights[index]));
                    bw+=truck_weights[index];
                    index++;
                }

                answer++;

            }

            return answer;
        }
    }

}
