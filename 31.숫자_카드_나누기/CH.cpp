#include <vector>
#include <algorithm>

using namespace std;

// 최대공약수 구하는 GCD 함수
int GCD(const int& a, const int& b) {
    if (b == 0) return a;
    
    return GCD(b, a % b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    // 배열 A와 B 중 모든 수를 나눌 수 있는지 검사하기 위한 변수
    bool isA = false;
    bool isB = false;
    // 각 배열의 최대공약수를 저장할 변수
    int GCD_A = arrayA[0];
    int GCD_B = arrayB[0];
    
    // 각 배열의 최대공약수 구함
    for (int i = 1; i < arrayA.size(); ++i) {
        GCD_A = GCD(arrayA[i], GCD_A);
        GCD_B = GCD(arrayB[i], GCD_B);
    }
    
    // 조건을 만족하는 a가 없을 경우 0 반환
    if (GCD_A == 1 && GCD_B == 1) return answer;
    
    // arrayA 원소 중 a로 나뉘는 수가 있는지 검사
    for (const auto& a : arrayA) {
        if (a % GCD_B == 0) {
            isB = true;
            break;
        }
    }
    
    // arrayB 원소 중 a로 나뉘는 수가 있는지 검사
    for (const auto& b : arrayB) {
        if (b % GCD_A == 0) {
            isA = true;
            break;
        }
    }
    
    // 둘 다 a로 나뉘는 수가 없는 경우
    if (!isA && !isB) return max(GCD_A, GCD_B);
    // arrayA만 a로 나뉠 때
    else if (!isA && isB) return GCD_A;
    // arrayB만 a로 나뉠 때
    else if (isA && !isB) return GCD_B;
    
    return answer;
}
