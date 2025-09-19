#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    // 뽑은 인형 넣은 스택.
    stack<int> item_stack;
    // 뽑은 인형.
    int item = 0;
    
    // 인형 뽑기.
    for(const auto& m:moves)
    {
        for(int i=0; i<board.size(); ++i)
        {
            if(board[i][m-1] == 0) continue;
            
            // 뽑은 인형 item에 저장.
            item = board[i][m-1];
            // 인형 뽑은 자리 0으로 저장.
            board[i][m-1] = 0;
            
            // 뽑은 인형 스택에 인형이 있으면,
            if(!item_stack.empty())
            {
                // 뽑은 인형과 스택 맨 위에 있는 인형이 같은 인형인지 검사.
                if(item == item_stack.top())
                {
                    // 같은 인형이면 둘 다 없어지므로 없어지는 인형 +2.
                    item_stack.pop();
                    answer += 2;
                    break;
                }
            }
            // 뽑은 인형 스택에 넣기.
            item_stack.push(item);
            break;
        }
    }
    
    return answer;
}
