//설명 보면서 풀었어요

#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

int solution(string dartResult) {
    vector<int> scores;
    int n = 0;
    for (int i = 0; i < dartResult.size(); i++) {
        char c = dartResult[i];
        if (isdigit(c)) { //숫자일 경우
            if (c == '1' && i+1 < dartResult.size() && dartResult[i+1] == '0') { //10일 때 처리
                n = 10;
                i++; // 다음 값인 0 건너뜀
            } else {
                n = c - '0'; // int로 변환
            }
        } else if (c == 'S') {
            scores.push_back(pow(n, 1)); //pow함수: 제곱
        } else if (c == 'D') {
            scores.push_back(pow(n, 2));
        } else if (c == 'T') {
            scores.push_back(pow(n, 3));
        } else if (c == '*') {
            int size = scores.size();
            if (size >= 2)scores[size-2] *= 2;
            scores[size-1] *= 2;
        } else if (c == '#') {
            scores.back() *= -1;
        }
    }

    int answer = 0;
    for (int s : scores) answer += s;
    return answer;
}
