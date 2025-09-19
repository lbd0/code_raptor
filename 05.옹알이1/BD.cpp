#include <string>
#include <vector>
using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    // 옹알이 저장한 벡터.
    vector<string> ongegg = {"aya", "ye", "woo", "ma"};
    
    for(auto& b:babbling)
    {
        string temp = b;
        for(auto& ong:ongegg)
        {
            // babbling에 옹알이 있는지 확인.
            // 옹알이가 있으면 지우는데 wyeoo같은 경우는 ye를 지우면 woo가 될 수 있으므로 babbling이랑 temp 둘 다 에서 옹알이가 있는지 확인.
            if(temp.find(ong) != string::npos && b.find(ong) != string::npos)
            {
                temp.erase(temp.find(ong), ong.size());
            }
        }
        
        // temp에 다 지워졌으면 발음할 수 있는 단어임.
        if(temp.empty()) answer++;
    }
    
    return answer;
}
