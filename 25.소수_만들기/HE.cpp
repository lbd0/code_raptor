#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int s) { // 소수 판별 함수
    if (s < 2) return false; 
    for (int i = 2; i * i <= s; i++) {
        if (s % i == 0) return false;
    }
    return true; 
}

int solution(vector<int> nums) {
    int answer = 0;
    
    for(int i = 0; i < nums.size(); i++){
        for(int j = i + 1; j < nums.size(); j++){
            for(int k = j + 1; k < nums.size(); k++){     
                int sum = nums[i] + nums[j] + nums[k];                
                if (isPrime(sum)) answer++;
            }
        }
    }

    cout << answer << endl;

    return answer;
}
