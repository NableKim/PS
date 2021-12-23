### Scanner vs BufferedReader
- BufferedReader는 한줄을 통째로 입력받는 방법으로 Scanner보다 입력 속도가 비교적 빠름

```java

public class BJ7568_덩치_2 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		StringTokenizer st = new StringTokenizer(br.readLine()); // 한 줄을 읽고 공백을 기준으로 토큰화
		int a = Integer.parseInt(st.nextToken());	// 첫번째로 입력받은 정수
		int b = Integer.parseInt(st.nextToken());	// 두번째로 입력받은 정수
	}
}
```

### 정렬하기
- Arrays.sort() 함수를 사용한다
- [참고글](https://coding-factory.tistory.com/549)
``` java
public class BJ2750_수정렬하기 {
	public static void main(String[] args) throws NumberFormatException, IOException {
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine());
		
		Integer [] arr = new Integer[N];
		for(int i=0; i<N; i++) {
			int a = Integer.parseInt(br.readLine());
			arr[i] = a;
		}
		
		//Arrays.sort(arr); // 오름차순 정렬
		Arrays.sort(arr, Collections.reverseOrder()); // 내림차순 정렬
		
		for(int i : arr)
			System.out.println(i);
	}
}
```