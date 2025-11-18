#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

// 소수 판별 함수.
bool isPrime(int x)
{
    for(int i=2; i<=sqrt(x); ++i)
    {
        if(x%i == 0) return false;
    }
    
    return true;
}

int solution(vector<int> nums) {
    int answer = 0;

    // 3개씩 더하는 경우의 수 모두 계산.
    for(int i=0; i<nums.size()-2; ++i)
    {
        for(int j=i+1; j<nums.size()-1; ++j)
        {
            for(int k=j+1; k<nums.size(); ++k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                
                if(isPrime(sum)) answer++;
            }
        }
    }

    return answer;
}
