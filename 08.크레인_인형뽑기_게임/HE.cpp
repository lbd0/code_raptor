#include <string>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> choice; //뽑은 인형들

    for (int i = 0; i < moves.size(); i++) {
        int move = moves[i] - 1;

        for (int row = 0; row < board.size(); row++) {
            if (board[row][move] != 0) { // 인형이 있으면 뽑은 인형 저장
                int doll = board[row][move];
                board[row][move] = 0; // 뽑은 곳 비우기

                choice.push_back(doll);

                if (choice.size() >= 2 && choice[choice.size() - 2] == choice.back()) { // 이전 인형과 같으면 폭발
                    choice.pop_back(); // 현재 인형 제거
                    choice.pop_back(); // 이전 인형 제거
                    answer += 2;
                }
                break;
            }
        }
    }

    return answer;
}
