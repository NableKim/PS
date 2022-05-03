package programmers.level1;

public class PG72410_신규아이디추천 {
    public static void main(String[] args) {
        Solution solution = new Solution();
        String new_id = solution.solution("...!@BaT#*..y.abcdefghijklm");
        System.out.println("new_id = " + new_id);
    }

    static class Solution {

        public String solution(String new_id) {
            String str1 = new_id.toLowerCase();
            String str2 = eliminateStr(str1);
            String str3 = doubleDots(str2);
            String str4 = edgeDots(str3);
            String str5 = str4.isEmpty()? "a": str4;
            String str6 = str5.length()>=16? str5.substring(0, 15): str5;
            String str7 = edgeDots(str6);
            String answer = str7.length()<=2? make_string(str7): str7;
            return answer;
        }

        public String make_string(String str) {
            char ch = str.charAt(str.length()-1);
            while(str.length()<3)
                str += ch;
            return str;
        }

        public String edgeDots(String str) {
            if(str.startsWith("."))
                str = str.substring(1);

            if(str.endsWith("."))
                str = str.substring(0, str.length()-1);

            return str;
        }

        public String eliminateStr(String str) {
            String new_str = "";
            for(int i=0; i<str.length(); i++) {
                char ch = str.charAt(i);
                if(('a' <=ch && ch <= 'z') ||
                        ('0'<=ch && ch <= '9') ||
                        ch == '-' || ch == '_' || ch == '.')
                    new_str += ch;
            }
            return new_str;
        }

        public String doubleDots(String str) {
            String new_str = "";
            int cnt = 0;
            for(int i=0; i<str.length(); i++) {
                char ch = str.charAt(i);
                if(ch == '.')
                    cnt++;
                else {
                    if(cnt >= 1)
                        new_str += '.';
                    new_str += ch;
                    cnt = 0;
                }
            }
            return new_str;
        }
    }
}