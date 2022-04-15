package baekjoon;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.Collections;

public class BJ1427_소트인사이드 {

	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int N = Integer.parseInt(br.readLine());
		br.close();
		
		ArrayList<Integer> arrList = new ArrayList<>();
		
		while(N != 0) {
			arrList.add(N%10);
			N /= 10;
		}
		
		Collections.sort(arrList, Collections.reverseOrder());
		
		for(int i=0; i<arrList.size(); i++)
			bw.write(String.valueOf(arrList.get(i)));
		
		bw.flush();
		bw.close();
		
		
	}
}
