#include <string>
#include <vector>
#include <cmath>
using namespace std;

// 2,5,8,0 과의 거리 구하는 함수.
int getDistance(int pos, int num)
{
    // 손가락 위치가 0이면 11로 저장. 아니면 원래 숫자로 저장.
    pos = (pos == 0) ? 11:pos;
    num = (num == 0) ? 11:num;
    
    // 숫자의 좌표 구해서 거리 계산.
    // 손가락 위치의 좌표 구하기.
    int pos_x = (pos-1)/3;
    int pos_y = (pos-1)%3;

    // 2,5,8,0 의 좌표 구하기.
    // 2,5,8,0 과의 거리 구할 때만 사용하므로 y는 항상 1.
    int num_x = (num-1)/3;
    int num_y = 1;    

    // x끼리 빼고, y끼리 뺀 절대값끼리 더하면 거리가 나옴.
    return abs(pos_x - num_x) + abs(pos_y - num_y);
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // 왼손 위치 ("*")
    int left_pos = 10;
    // 오른손 위치 ("#")
    int right_pos = 12;
    
    for(auto& num:numbers)
    {
        switch(num)
        {
            // 1,4,7 은 왼손.
            case 1:
            case 4:
            case 7:
                answer += 'L';
                left_pos = num;
                break;
            // 3,6,9 는 오른손
            case 3:
            case 6:
            case 9:
                answer += 'R';
                right_pos = num;
                break;
                
            // 2,5,8,0 일 때,
            default:
                // 왼손, 오른손 각각 거리 구하기.
                int left_distance = getDistance(left_pos, num);
                int right_distance = getDistance(right_pos, num);
                
                // 거리가 같으면,
                if(left_distance == right_distance)
                {
                    // hand 값에 따라 결정.
                    answer += hand.compare("left")==0 ? 'L':'R';
                    hand.compare("left")==0 ? left_pos = num:right_pos = num;
                }
                else
                {
                    // 거리가 가까운 손으로 결정.
                    answer += left_distance > right_distance ? 'R':'L';
                    left_distance > right_distance ? right_pos = num:left_pos = num;
                }
        }
    }
    
    return answer;
}
