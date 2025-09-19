#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int answer = 0;
    int n = board.size();
    int count = 0;
    vector <int> dh = {0, 1, -1, 0}; // 방향 값
    vector <int> dw = {1, 0, 0, -1};
    
    for(int i = 0; i < 4; i++){
        int h_check = h + dh[i]; // 이동 좌표
        int w_check = w + dw[i];
        if(h_check >= 0 && h_check < n && w_check >= 0 && w_check < n){
            if(board[h][w] == board[h_check][w_check])
                count++;
        }
    }
    answer = count;
    return answer;
}
