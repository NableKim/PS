package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;
import java.util.PriorityQueue;

class Counting implements Comparable<Counting>{
	int number;
	int cnt;
	
	public Counting(int number, int cnt) {
		this.number = number;
		this.cnt = cnt;
	}

	@Override
	public int compareTo(Counting w) {
		if(this.cnt < w.cnt)
			return 1;
		else if(this.cnt == w.cnt) {
			if(this.number > w.number)
				return 1;
		}
		return -1;
		
	}
}

public class BJ2108_≈Î∞Ë«– {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[N];
		int[] cnt = new int[8001];
		
		double sum = 0.0;
		for(int i=0; i<N; i++) {
			int num = Integer.parseInt(br.readLine());
			arr[i] = num;
			cnt[num+4000]++;
			sum += num;
		}
		
		Arrays.sort(arr);
		
		PriorityQueue<Counting> pq = new PriorityQueue<>();
		
		for(int i=0; i<8001; i++) {
			if(cnt[i]!=0) {
				pq.offer(new Counting(i-4000, cnt[i]));
			}
		}
		
		Counting maxCounting = pq.peek();
		pq.remove();
		if(!pq.isEmpty() && pq.peek().cnt == maxCounting.cnt)
			maxCounting = pq.peek();

		bw.write(Math.round(sum/N) + "\n");
		bw.write(arr[N/2] + "\n");
		bw.write(maxCounting.number + "\n");
		bw.write(arr[N-1] - arr[0] + "\n");
		
		bw.flush();
		bw.close();
		br.close();
	}
}
