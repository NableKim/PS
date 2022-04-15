package baekjoon;

import java.util.Scanner;

public class BJ7568_덩치 {
	
	static int[][] arr = new int[50][2];
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int N = sc.nextInt();
		
		for(int i=0; i<N; i++) {
			int w = sc.nextInt();
			int h = sc.nextInt();
			
			arr[i][0] = w;
			arr[i][1] = h;			
		}
		
		for(int i=0; i<N; i++) {
			int cnt = 0;
			for(int j=0; j<N; j++) {
				if(i==j) continue;
				if(arr[i][0] < arr[j][0] 
						&&arr[i][1] < arr[j][1])
					cnt++;
			}			
			System.out.print(cnt+1 + " ");
		}
		
		sc.close();
	}
}
