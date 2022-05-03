package programmers.level3;

import java.util.Stack;

public class PG81303_표편집2 {

    public static void main(String[] args) {

        int n=8;
        int k=2;
        String[] cmd = {"D 2","C","U 3","C","D 4","C","U 2","Z","Z"};

        Solution solution = new Solution();

        String answer = solution.solution(n,k,cmd);
        System.out.println("answer = " + answer);

    }

    static class Node {
        int pre;
        int idx;
        int next;
        public Node() {}
        public Node(int pre, int idx, int next) {
            this.pre = pre;
            this.idx = idx;
            this.next = next;
        }
    }

    static class Solution {

        int selectedIdx;
        Node[] nodeList;
        Stack<Node> stack = new Stack<>();

        public String solution(int n, int k, String[] cmds) {
            
            // 초기 선택 위치
            selectedIdx = k;

            // 노드 생성 및 연결
            nodeList = new Node[n];
            for(int i=0; i<n; i++) {
                nodeList[i] = new Node(i-1, i, i+1);
            }

            for (String cmd : cmds) {

                char operation = cmd.charAt(0);
                if(operation == 'U') {
                    int distance = Integer.parseInt(cmd.substring(2));
                    changeSelectedIdx(-1, distance);
                }
                else if(operation == 'D') {
                    int distance = Integer.parseInt(cmd.substring(2));
                    changeSelectedIdx(1, distance);
                }
                else if(operation == 'C') {

                    // 연결리스트 삭제 연산
                    int cur = selectedIdx;

                    // 맨 처음인 경우
                    if(nodeList[cur].pre == -1) {
                        int next = nodeList[cur].next;
                        nodeList[next].pre = -1;
                        selectedIdx = next;
                    }
                    else if(nodeList[cur].next == n) {
                        int pre = nodeList[cur].pre;
                        nodeList[pre].next = n;
                        selectedIdx = pre;
                    }
                    else {
                        int pre = nodeList[cur].pre;
                        int next = nodeList[cur].next;

                        nodeList[pre].next = nodeList[cur].next;
                        nodeList[next].pre = nodeList[cur].pre;
                        selectedIdx = next;
                    }

                    stack.add(nodeList[cur]);
                }
                else {
                    Node top = stack.pop();

                    int pre = top.pre;
                    int next = top.next;

                    if(pre != -1)
                       nodeList[pre].next = top.idx;
                    if(next != n)
                        nodeList[next].pre = top.idx;
                }
            }

            // 스택에 있는 것들을 꺼내서 지우기
            char[] arr = new char[n];
            for(int i=0; i<n; i++)
                arr[i] = 'O';

            while(!stack.empty()) {
                Node top = stack.pop();
                arr[top.idx] = 'X';
            }

            String answer = new String(arr);
            return answer;
        }

        public void changeSelectedIdx(int direction, int distance) {
            while(distance>0) {
                if(direction == -1)
                    selectedIdx = nodeList[selectedIdx].pre;
                else
                    selectedIdx = nodeList[selectedIdx].next;
                distance--;
            }

        }
    }

}
