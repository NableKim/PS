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
- Primitive Data Type이나 정적 크기의 배열을 사용할 땐 Arrays.sort() 사용, [참고글](https://coding-factory.tistory.com/549)
- ArrayList, LinkedList 등의 가변 크기의 자료형은 Collections.sort() 사용, [참고글](https://gmlwjd9405.github.io/2018/09/06/java-comparable-and-comparator.html)

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

### 우선순위큐
- C++과 다르게 여기는 디폴트가 최소힙임
- pq에 넣는 자료형이 사용자 정의 타입이라면 비교함수를 재정의해줘야함
- offer()가 넣는거, peek()이 꼭대기값 확인, poll() 꼭대기값 반환 후 pop연산, remove()가 pop 연산


### 비교함수 재정의 방법
1. Comparable<T> 인터페이스 상속 후 compareTo(Object O) 재정의
2. Comparator<T> 인터페이스 상속 후 compare(Object A, Object B) 재정의
- [예시 코드 참고](https://gmlwjd9405.github.io/2018/09/06/java-comparable-and-comparator.html)
- 비교함수 재정의 할 때, 비교함수의 리턴값이 1이어야 자리를 바꾼다는 점이 특이점
