#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    // 발음 할 수 있는 단어.
    vector<string> ong = {"aya", "ye", "woo", "ma"};
    
    for(auto& b:babbling)
    {
        // 연속으로 발음 불가이므로 이전 단어를 저장해야 함.
        string prev = "";
        // 발음 가능 여부 저장.
        bool can = true;
        // 왼쪽부터 확인할 인덱스.
        int idx = 0;
        
        while(idx < b.size())
        {
            // 발음할 수 있는 단어 여부 저장.
            bool match = false;
            
            for(auto& o:ong)
            {
                // 왼쪽부터 발음할 수 있는 단어가 있는지 확인.
                if(b.compare(idx, o.size(), o) == 0)
                {
                    // 이전 단어랑 같으면 발음 X.
                    if(prev == o)
                    {
                        break;
                    }
                    
                    // 이전 단어 현재 단어로 갱신.
                    prev = o;
                    // 발음할 수 있는 단어 길이만큼 인덱스 이동.
                    idx += o.size();
                    
                    // 발음할 수 있는 단어 찾음.
                    match = true;
                    break;
                }
            }
            
            // 발음할 수 있는 단어가 없으면
            if(!match) 
            {
                // 발음 불가.
                can = false;
                break;
            }
        }
        
        if(can) answer++;
    }
    return answer;
}
