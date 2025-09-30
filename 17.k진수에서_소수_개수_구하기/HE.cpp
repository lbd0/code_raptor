#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

string toBase(int n, int k) { //k진수로 변환
    string s;
    do {
        s += (n % k) + '0';
        n /= k;
    } while (n > 0);
    reverse(s.begin(), s.end());
    return s;
}

bool isPrime(long long num) { // 소수 체크 //int 범위 넘어가서 long long 사용 (정보 출처: 바다리)
    if (num < 2) return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    string s = toBase(n, k);
    int answer = 0;

    for (long long num = 0, i = 0; i <= s.size(); i++) {
        if (i == s.size() || s[i] == '0') { // 0이거나 문자열 끝일 때까지
            if (num && isPrime(num)) answer++; // 숫자가 소수일 때 answer++
            num = 0;
        } else {
            num = num * 10 + (s[i] - '0'); //정수로 변환해서 숫자 누적
        }
    }

    return answer;
}
