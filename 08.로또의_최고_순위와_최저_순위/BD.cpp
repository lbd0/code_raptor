#include <string>
#include <vector>

using namespace std;

// 현재 가지고 있는 번호에서 일치하는 번호 개수를 세고, +0의 개수하면 최고 순위, 그대로 순위가 최저 순위.

// 순위 정하는 함수.
int prize(int num)
{
    switch(num)
    {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    // 같은 숫자 개수.
    int same_num = 0;
    // 0 개수.
    int zero_num = 0;
    
    for(const auto& l:lottos)
    {
        // 0 개수 세기.
        if(l==0) 
        {
            zero_num++;
            continue;
        }
        
        for(const auto& w:win_nums)
        {
            // 같은 숫자 개수 세기.
            if(l==w) 
            {
                same_num++;
                break;
            }
        }
    }
    
    // 최고 순위.
    answer.push_back(prize(same_num + zero_num));
    // 최저 순위.
    answer.push_back(prize(same_num));
    
    return answer;
}
