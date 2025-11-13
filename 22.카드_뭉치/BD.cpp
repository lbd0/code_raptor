#include <string>
#include <vector>
#include <queue>

using namespace std;

/*
stack에 저장해서 역순으로 확인했더니, 카드가 교차하는 시점에? 순서가 꼬인다더군요,, 반례는 정확하게 찾지 못했지만,, 그러하대요;;
queue이랑 인덱스 이용해서 풀 수 있다는데, 인덱스 이용하는게 살짝 더 효율적이래서 둘 다 올릴게요.
*/

// queue
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    queue<string> c1, c2;
    
    for(auto c:cards1)
    {
        c1.push(c);
    }
    
    for(auto c:cards2)
    {
        c2.push(c);
    }
    
    for(int i=0; i<goal.size(); ++i)
    {
        if(!c1.empty() && goal[i] == c1.front()) 
        {
            c1.pop();
            continue;
        }
        
        if(!c2.empty() && goal[i] == c2.front()) 
        {
            c2.pop();
            continue;
        }
        
        return "No";
    }
    
    return "Yes";
}

// index
string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    int i=0, j=0;
    
    for(auto& g:goal)
    {
        if(i<cards1.size() && cards1[i] == g) i++;
        else if(j<cards2.size() && cards2[j] == g) j++;
        else return "No";
    }
    return "Yes";
}
