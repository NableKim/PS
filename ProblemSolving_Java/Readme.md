* Scanner vs BufferedReader
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