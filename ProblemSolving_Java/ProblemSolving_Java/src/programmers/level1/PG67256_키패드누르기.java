package programmers.level1;

import java.util.HashMap;
import java.util.Map;

public class PG67256_키패드누르기 {

    public static void main(String[] args) {

        int[] numbers = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
        String hand = "right";

        Solution solution = new Solution();
        String solution1 = solution.solution(numbers, hand);
        System.out.println("solution1 = " + solution1);
    }

    static class Solution {

        static class Point {
            int y;
            int x;

            public Point(int y, int x) {
                this.y = y;
                this.x = x;
            }
        }

        Map<Integer, Point> map = new HashMap<>();

        public void init() {
            map.put(1, new Point(0, 0));
            map.put(2, new Point(0, 1));
            map.put(3, new Point(0, 2));
            map.put(4, new Point(1, 0));
            map.put(5, new Point(1, 1));
            map.put(6, new Point(1, 2));
            map.put(7, new Point(2, 0));
            map.put(8, new Point(2, 1));
            map.put(9, new Point(2, 2));
            map.put(0, new Point(3, 1));
        }

        public String solution(int[] numbers, String hand) {
            String answer = "";

            init();

            // 왼쪽의 위치, 오른손의 위치를 메모해두기
            Point left = new Point(3, 0);
            Point right = new Point(3, 2);

            String defaultString = "L";
            if(hand.equals(right))
                defaultString = "R";


            for (int number : numbers) {
                if(number == 1 || number == 4 || number == 7) {
                    left = map.get(number);
                    answer += "L";
                }
                else if(number == 3 || number == 6 || number == 9) {
                    right = map.get(number);
                    answer += "R";
                }
                else {
                    int leftDistance = Math.abs(map.get(number).y - left.y) + Math.abs(map.get(number).x - left.x);
                    int rightDistance = Math.abs(map.get(number).y - right.y) + Math.abs(map.get(number).x - right.x);

                    if(leftDistance < rightDistance) {
                        left = map.get(number);
                        answer += "L";
                    }
                    else if(leftDistance > rightDistance) {
                        right = map.get(number);
                        answer += "R";
                    }
                    else if(hand.charAt(0) == 'l'){
                        left = map.get(number);
                        answer += "L";
                    }
                    else {
                        right = map.get(number);
                        answer += "R";
                    }
                }
            }

            return answer;
        }
    }

}
