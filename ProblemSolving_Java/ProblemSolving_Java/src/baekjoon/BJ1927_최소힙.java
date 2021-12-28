package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.PriorityQueue;

public class BJ1927_√÷º“»¸ {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		for(int i=0; i<N; i++) {
			int number = Integer.parseInt(br.readLine());
			if(number == 0) {
				if(pq.isEmpty()) bw.write("0\n");
				else {
					bw.write(pq.peek()+"\n");
					pq.remove();
				}
				continue;
			}
			pq.add(number);
		}
		
		br.close();
		bw.flush();
		bw.close();
	}
}
