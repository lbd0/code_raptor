#include <vector>
#include <stack>

using namespace std;

// 바구니
int bucket(const int &n, stack<int> &st)
{
    // 스택이 비어있지 않고, 제일 위와 들어온 것이 같으면
    if (!st.empty() && st.top() == n)
    {
        // 제일 위 삭제 및 2 반환
        st.pop();
        return 2;
    }
    else
    {
        // 바구니에 인형 넣기
        st.push(n);
        return 0;
    }    
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    // 바구니
    stack<int> st;
    
    for (const int &m : moves)
    {
        for (vector<int> &b : board)
        {
            // 행별 m - 1 열의 인형 검사
            if (b[m - 1] != 0)
            {
                // 바구니에 넣기
                answer += bucket(b[m - 1], st);
                // 뽑힌 인형 자리 비우기
                b[m - 1] = 0;
                break;
            }
        }
    }
    
    return answer;
}
