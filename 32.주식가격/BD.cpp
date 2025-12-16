#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    
    stack<int> s;
    
    for(int i=0; i<prices.size(); ++i)
    {
        if(!s.empty()) 
        {
            while(true)
            {
                if(s.empty()) break;
                
                int top = s.top();
                
                if(prices[top] <= prices[i]) break;
                
                answer[top] = i - top;
                s.pop();
            }
        }
        s.push(i);
    }
    
    while(!s.empty())
    {
        int top = s.top();
        answer[top] = prices.size() - top - 1;
        s.pop();
    }
    
    return answer;
}
