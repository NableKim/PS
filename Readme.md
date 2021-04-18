# PS 지식

## 나머지(모듈러) 연산 성질
- (A+B)%M = ((A%M)+(B%M))%M
- (A*B)%M = ((A%M)*(B%M))%M
- (A-B)%M = ((A%M)-(B%M)+M)%M


## 이분탐색
### value 값 이상인 지점 찾기

```C++
// while 끝났을때 right로 정답을 뽑는다
while(left<right) {
	mid;
	if(value<=A[mid])
		right = mid;
	else
		left = mid+1;
}
// right번째 index가 정답
```

### value 값 미만인 지점 찾기
- value 값 이상인 지점 찾고 right-1하면 됨

### value 값 초과인 지점 찾기
```C+++
// while 끝났을때 right로 정답을 뽑는다
while(left<right) {
	mid;
	if(value<A[mid])
		right = mid;
	else
		left = mid+1;
}
// right번째 index가 정답
```

### value 값 이하인 지점 찾기
- value 값 초과인 지점 찾고 right-1하면 됨
