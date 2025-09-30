#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

// n을 k진수로 바꾸는 함수.
string changeBase(int n, int k)
{
    if(n == 0) return 0;
    
    string res = "";
    
    while(n > 0)
    {
        res += to_string(n%k);
        n /= k;
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}

// 소수인지 검사하는 함수.
// int 범위 넘어가는 숫자도 있어서 long long 으로 계산.
bool isPrime(long long n)
{
    if(n == 1) return false;
    
    for(int i=2; i <= sqrt(n); ++i)
    {
        if(n%i == 0) return false;
    }
    
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    
    // n을 k진수로 변환.
    string new_n = changeBase(n,k);
    
    int cur = 0;
    int pos;
    
    // 0 전까지 나온 숫자가 소수인지 검사.
    while((pos = new_n.find("0", cur)) != string::npos)
    {
        int len = pos - cur;
        string temp = new_n.substr(cur, len);
        
        if((!temp.empty()) && isPrime(stoll(temp))) answer++;
        
        cur = pos + 1;
    }
    // 마지막 남은 숫자들 소수인지 검사.
    string last = new_n.substr(cur);
    
    if((!last.empty()) && isPrime(stoll(last))) answer++;
    
    return answer;
}
