#include <cstdio>
#include <string>
#include <vector>
using namespace std;

int trans(string s, int* idx) {
    
    int num = 0;

    switch (s[*idx]) {
        case 'z':
            *idx += 4;
            num = 0;
            break;
        case 'o':
            *idx += 3;
            num = 1;
            break;
        case 't':
            if (s[*idx + 1] == 'w') {
                *idx += 3;
                num = 2;
            }
            else {
                *idx += 5;
                num = 3;
            }
            break;
        case 'f':
            if (s[*idx + 1] == 'o') {
                *idx += 4;
                num = 4;
            }
            else {
                *idx += 4;
                num = 5;
            }
            break;
        case 's':
            if (s[*idx + 1] == 'i') {
                *idx += 3;
                num = 6;
            }
            else {
                *idx += 5;
                num = 7;
            }
            break;
        case 'e':
            *idx += 5;
            num = 8;
            break;
        case 'n':
            *idx += 4;
            num = 9;
            break;
    }

    return num;
}

int solution(string s) {
    int answer = 0;

    for (int i = 0; i < s.size(); ) {
        if (s[i] >= '0' && s[i] <= '9') {
            answer = answer * 10 + (s[i] - '0');
            i++;
        }
        else {
            int num = trans(s, &i);
            answer = answer * 10 + num;
        }
    }

    return answer;
}

int main() {

    string s = "one4seveneight";
    printf("%d", solution(s));

    return 0;
}