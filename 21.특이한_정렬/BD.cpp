#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer;
    
    // n보다 큰 숫자 저장      작은 숫자 저장.
    int plus[10001] = {0}, minus[10001] = {0};
    
    for(auto& num:numlist)
    {
        if(n == num) answer.push_back(num);
        // 거리를 인덱스로 저장.
        else if(n < num)
        {
            plus[num-n] = num;
        }
        else
        {
            minus[n-num] = num;
        }
    }
    
    for(int i=0; i<10001; ++i)
    {
        // 거리가 같을 경우 큰 수가 앞으로 오므로 plus 먼저 저장.
        if(plus[i] != 0)
            answer.push_back(plus[i]);
        
        if(minus[i] != 0)
            answer.push_back(minus[i]);
    }
    
    return answer;
}
