package programmers;

import java.util.*;

public class PG92334_신고결과받기2 {
    public int[] solution(String[] id_list, String[] report, int k) {

        int[] answer = new int[id_list.length];

        // �Ű���ѻ��, �Ű��� ��� ���
        Map<String, Set<String>> reportInfo = new HashMap<>();

        // id�� idx �ο�
        Map<String, Integer> idIndexMap = new HashMap<>();
        for (int i = 0; i < id_list.length; i++)
            idIndexMap.put(id_list[i], i);

        for (String s : report) {
            String[] username = s.split(" ");
            String user1 = username[0]; // �Ű���
            String user2 = username[1]; // �Ű���� ���

            // �Ű��� �߰�
            Set<String> set = reportInfo.getOrDefault(user2, new HashSet<>());
            set.add(user1);
            reportInfo.put(user2, set);
        }

        for(Map.Entry<String, Set<String>> entry : reportInfo.entrySet()) {
            Set<String> userSet = entry.getValue();
            if(userSet.size()>=k) {
                for (String username : userSet)
                    answer[idIndexMap.get(username)]++;
            }
        }

        return answer;
    }
}