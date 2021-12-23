package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;

public class BJ2750_수정렬하기 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[N];
		for(int i=0; i<N; i++) {
			int a = Integer.parseInt(br.readLine());
			arr[i] = a;
		}
		
		Arrays.sort(arr); // 오름차순 정렬
		
		for(int i : arr)
			System.out.println(i);
		
		
	}

}
