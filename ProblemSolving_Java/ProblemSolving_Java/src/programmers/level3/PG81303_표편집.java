package programmers.level3;

import java.util.Stack;

public class PG81303_표편집 {

    public static void main(String[] args) {

        int n=8;
        int k=2;
        String[] cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};

        Solution solution = new Solution();

        String answer = solution.solution(n,k,cmd);
        System.out.println("answer = " + answer);

    }

    static class Solution {

        boolean[] deleted;
        int selectedIdx;
        Stack<Integer> stack = new Stack<>();

        public String solution(int n, int k, String[] cmd) {
            String answer = "";

            deleted = new boolean[n];
            selectedIdx = k;

            for (String s : cmd) {
                if(s.charAt(0) == 'U') {
                    String distanceStr = s.substring(2);
                    int distance = Integer.parseInt(distanceStr);
                    changeSelectedIdx(-1, distance, n);
                }
                else if(s.charAt(0) == 'D') {
                    String distanceStr = s.substring(2);
                    int distance = Integer.parseInt(distanceStr);
                    changeSelectedIdx(1, distance, n);
                }
                else if(s.charAt(0) == 'C') {
                    deleted[selectedIdx] = true;
                    stack.add(selectedIdx);
                    changeSelectedIdx(1, 1, n);
                    if(selectedIdx==n)
                        changeSelectedIdx(-1, 1, n);
                }
                else if(s.charAt(0) == 'Z') {
                    int top = stack.pop();
                    deleted[top] = false;
                }
            }

            for(int i=0; i<n; i++) {
                if(deleted[i])
                    answer += "X";
                else
                    answer += "O";
            }

            return answer;
        }

        private void changeSelectedIdx(int direction, int distance, int n) {
            while(distance>0) {
                selectedIdx += direction;
                if(selectedIdx == n) break;
                if(deleted[selectedIdx]) continue;
                distance--;
            }
        }
    }

}
