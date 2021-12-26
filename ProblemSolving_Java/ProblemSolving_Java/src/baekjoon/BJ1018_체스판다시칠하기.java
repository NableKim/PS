package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class BJ1018_체스판다시칠하기 {
	
	static char[][] map;
	static int minCnt = 5000;
	
	public static void getDiff(int y, int x, char start) {
		int cnt = 0;
		for(int c=0; c<8; c++) {
			for(int r=0; r<8; r++) {
				if(map[y+r][x+c] != start)
					cnt++;
				
				if(start == 'B')
					start = 'W';
				else
					start = 'B';
			}
			if(start == 'B')
				start = 'W';
			else
				start = 'B';
		}
		
		if(minCnt > cnt)
			minCnt = cnt;
	}
	
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		StringTokenizer st = new StringTokenizer(br.readLine(), " ");
		
		int N, M;
		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		
		map = new char[N][M];
		
		for(int y=0; y<N; y++) {
			String tmp = br.readLine();
			for(int x=0; x<M; x++) {
				map[y][x] = tmp.charAt(x);
			}
		}
		
		
		int ylen = N - 8;
		int xlen = M - 8;
		for(int y=0; y<=ylen; y++) {
			for(int x=0; x<=xlen; x++) {
				getDiff(y, x, 'W');
				getDiff(y, x, 'B');
			}
		}
		
		bw.write(String.valueOf(minCnt));
		bw.flush();
		br.close();
	}
}
