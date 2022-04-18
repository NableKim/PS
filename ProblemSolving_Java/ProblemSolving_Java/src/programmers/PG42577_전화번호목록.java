package programmers;

import java.util.*;

class Solution {

    public Map<String, Boolean> WordHashMap = new HashMap<>();
    
    public boolean solution(String[] phone_book) {

        // 길이를 기준으로 정렬
        // 가장 짧은 데이터가 먼저 오도록 정렬
        Arrays.sort(phone_book, new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length()-o2.length();
            }
        });

        // 그것부터 시작해서
        // 길이가 1~길이까지의 해시데이터가 존재하는지 확인. 존재하면 false 끝
        // 그 문자열 자체를 해시에 저장하기
        for(String s : phone_book) {
            String tmp = "";
            for(int i=0; i<s.length(); i++) {
                tmp += s.charAt(i);
                if(WordHashMap.getOrDefault(tmp, false))
                    return false;
            }
            WordHashMap.put(s, true);
        }

        return true;
    }
}

public class PG42577_전화번호목록 {

    public static void main(String[] args) {

        //String[] phone_book = { "119", "1195524421", "97674223" };
        String[] phone_book = { "123","456","789" };

        Solution solution = new Solution();
        boolean answer = solution.solution(phone_book);
        System.out.println("answer = " + answer);
    }
}
