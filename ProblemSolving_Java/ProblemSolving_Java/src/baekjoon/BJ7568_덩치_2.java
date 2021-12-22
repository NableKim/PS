package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class BJ7568_µ¢Ä¡_2 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		int[][] person = new int[N][2];
		
		for(int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			person[i][0] = Integer.parseInt(st.nextToken());
			person[i][1] = Integer.parseInt(st.nextToken());			
		}
		
		for(int i=0; i<N; i++) {			
			int cnt = 1;
			for(int j=0; j<N; j++) {
				if(i==j) continue;
				if(person[i][0] < person[j][0] && person[i][1] < person[j][1])
					cnt++;
			}
			System.out.print(cnt + " ");
		}
	}
}
