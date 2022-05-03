package programmers.level3;

import java.util.*;

public class PG42579_베스트앨범 {

    public static void main(String[] args) {

        String[] genres = {"classic", "pop", "classic", "classic", "pop"};
        int[] plays = {500, 600, 150, 800, 2500};

        Solution solution = new Solution();
        int[] solution1 = solution.solution(genres, plays);
        for (int i : solution1) {
            System.out.println("i = " + i);
        }
    }

    static class Song {
        int idx;    // 몇 번째 노래가
        int cnt;    // 몇 번 재생되었는가

        Song(int idx, int cnt) {
            this.idx = idx;
            this.cnt = cnt;
        }
    }

    static class Solution {

        Map<String, Integer> playCntHashMap = new HashMap<>();      // 장르별 노래 재생 횟수
        Map<String, List<Song>> songListHashMap = new HashMap<>();  // 어느 장르에 속하는 노래 리스트

        public int[] solution(String[] genres, int[] plays) {
            List<Integer> ansList = new ArrayList<>();

            for(int i=0; i<genres.length; i++) {
                String name = genres[i];
                int cnt = plays[i];
                
                // 장르별 재생 횟수를 누적
                playCntHashMap.put(name, playCntHashMap.getOrDefault(name, 0)+cnt);

                // 장르별 노래 리스트에 추가
                List<Song> songList = songListHashMap.getOrDefault(name, new ArrayList<Song>());
                songList.add(new Song(i, cnt));
                songListHashMap.put(name, songList);
            }

            // 누적 재생 횟수별로 장르명 정렬하기
            List<Map.Entry<String, Integer>> list = new ArrayList<>(playCntHashMap.entrySet());
            Collections.sort(list, new Comparator<Map.Entry<String, Integer>>() {
                @Override
                public int compare(Map.Entry<String, Integer> o1, Map.Entry<String, Integer> o2) {
                    return o2.getValue()-o1.getValue();
                }
            });

            Iterator<Map.Entry<String, Integer>> iterator = list.iterator();
            while(iterator.hasNext()) {

                Map.Entry<String, Integer> next = iterator.next();

                List<Song> songs = songListHashMap.get(next.getKey());

                Collections.sort(songs, new Comparator<Song>() {
                    @Override
                    public int compare(Song o1, Song o2) {
                        if(o1.cnt == o2.cnt) {
                            return o1.idx - o2.idx;
                        }
                        return o2.cnt - o1.cnt;
                    }
                });

                ansList.add(songs.get(0).idx);
                if(songs.size() >= 2)
                    ansList.add(songs.get(1).idx);
            }

            Integer[] answer = new Integer[ansList.size()];
            ansList.toArray(answer);

            return Arrays.stream(answer).mapToInt(Integer::intValue).toArray();
        }
    }
}
