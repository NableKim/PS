package programmers.level1;

public class PG72410_신규아이디추천2 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String new_id = solution.Solution("...!@BaT#*..y.abcdefghijklm");
        System.out.println("new_id = " + new_id);
    }

    static class Solution {
        public String Solution(String new_id) {
            String answer = new_id.toLowerCase()
                    .replaceAll("[^a-z0-9-_.]","")
                    .replaceAll("[.]{2,}", ".")
                    .replaceAll("^[.]|[.]$", "");
            answer= answer.isEmpty()? "a": answer;
            answer = answer.length()>=16? answer.substring(0, 15): answer;
            answer = answer.replaceAll("^[.]|[.]$", "");
            while(answer.length()<=2)
                answer+=answer.charAt(answer.length()-1);
            return answer;
        }
    }
}