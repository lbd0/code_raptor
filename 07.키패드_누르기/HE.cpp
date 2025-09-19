#include <string>
#include <vector>

using namespace std;

int pos[13][2] = { // 키패드 위치 저장
    {0,0},
    {0,0}, {0,1}, {0,2}, // 123
    {1,0}, {1,1}, {1,2}, // 456
    {2,0}, {2,1}, {2,2}, // 789
    {3,0}, {3,1}, {3,2} // *0#
};

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10; // * 임의로 10으로 지정
    int right = 12; // # 임의로 12로 지정
    
    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num == 0)
            num = 11; // 0 임의로 11로 지정
        if (num == 1 || num == 4 || num == 7) { //147 = 왼손
            answer += "L";
            left = num;
        }
        else if (num == 3 || num == 6 || num == 9) { //369 = 오른손
            answer += "R";
            right = num;
        }
        else { //0258 = 처리
          //왼손 거리
            int leftDist  = abs(pos[left][0] - pos[num][0]) + abs(pos[left][1] - pos[num][1]);
          //오른손 거리
            int rightDist = abs(pos[right][0] - pos[num][0]) + abs(pos[right][1] - pos[num][1]);
            
            if (leftDist < rightDist) { // 왼손이 더 가까울 때
                answer += "L";
                left = num;
            } 
            else if (rightDist < leftDist) {// 오른손이 더 가까울 때
                answer += "R";
                right = num;
            } 
            
            else { // 거리 같을 때
                if (hand == "right") {
                    answer += "R";
                    right = num;
                } else {
                    answer += "L";
                    left = num;
                }
            }
        }
    }

    return answer;
}
