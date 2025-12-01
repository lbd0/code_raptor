#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
순서를 유지해야 하므로 큐 사용.
앞에서부터 꺼내서 중복되지 않는 수만 answer에 저장.
*/

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    queue<int> queue;
    
    for(auto a:arr)
    {
        queue.push(a);
    }

    while(!queue.empty())
    {
        int temp = queue.front();
        queue.pop();
        
        if(!answer.empty())
        {
            if(temp == answer[answer.size()-1]) continue;
        }
        
        answer.push_back(temp);
    }
    
    return answer;
}
