#include <string>
#include <algorithm>

using namespace std;

// 양의 정수 n을 k 진수로 바꾸는 함수
string convert(int& n, const int& k)
{
    string str = (n == 0) ? "0" : "";
    
    while (n > 0)
    {
        str += to_string(n % k);
        n /= k;
    }
    
    // 뒤집기
    reverse(str.begin(), str.end());
    
    return str;
}

// 소수인지 검사하는 함수
bool isPrime(const long long& n)
{
    if (n < 2) return false;
    
    for (long long i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    
    return true;
}

int solution(int n, int k) {
    // k 진수로 바꾼 뒤 string으로 저장
    string str = convert(n, k);
    // 조건에 맞는 소수의 수, 0의 위치, 현재 위치
    int answer = 0, zeroIdx, curIdx = 0;
    
    // 현재 위치~끝 사이 0이 있는 경우
    while ((zeroIdx = str.find('0', curIdx)) != string::npos)
    {
        // 0뒤에 숫자가 있고 소수일 경우 answer 증가
        if (zeroIdx - curIdx > 0 && isPrime(stoll(str.substr(curIdx, zeroIdx - curIdx)))) ++answer;
        // 현재 위치를 0의 다음으로 이동
        curIdx = zeroIdx + 1;
    }
    
    // 마지막 검사하지 못한 숫자들을 검사
    if (!str.substr(curIdx).empty() && isPrime(stoll(str.substr(curIdx)))) ++answer;
    
    return answer;
}
