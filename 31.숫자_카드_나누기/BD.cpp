#include <string>
#include <vector>
#include <cmath>

using namespace std;

// 최대공약수 계산.
int gcd(int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int gcd_arr(const vector<int>& v) {
    int g = v[0];
    for(int i = 1; i < v.size(); i++) {
        g = gcd(g, v[i]);
    }
    return g;
}

// 약수 계산.
vector<int> factor(int a)
{
    vector<int> res;
    
    if(a <= 0) return res;
    for(int i=1; i <= a/2; ++i)
    {
        if(a%i == 0) res.push_back(i);
        
    }
    
    res.push_back(a);
    
    return res;
}

/*
각 벡터의 최대공약수 구함 -> 최대공약수의 약수 구함 -> 다른 벡터의 값을 모두 나눌 수 없는 약수 찾음 -> 그 중 최대 반환.
*/
int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    int gcdA = gcd_arr(arrayA);
    int gcdB = gcd_arr(arrayB);
    
    vector<int> fA = factor(gcdA);
    vector<int> fB = factor(gcdB);
    
    for(auto& fa:fA)
    {
        bool flag = false;
        for(auto& B:arrayB)
        {
            if(B%fa == 0) 
            {
                flag = true;
                break;
            }
            
        }
        
        if(!flag) answer = max(answer, fa);
        
    }
    
    for(auto& fb:fB)
    {
        bool flag = false;
        for(auto& A:arrayA)
        {
            if(A%fb == 0)
            {
                flag = true;
                break;
            }
        }
        
        if(!flag) answer = max(answer, fb);
    }
    
    return answer;
}
