package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Comparator;
import java.util.PriorityQueue;

class newCompare implements Comparator<Integer> {

	@Override
	public int compare(Integer o1, Integer o2) {
		// TODO Auto-generated method stub
		return o2.intValue() - o1.intValue();
	}
	
}

public class BJ11279_√÷¥Î»¸ {
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new newCompare());
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
