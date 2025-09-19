#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    // *과 #은 자리 위치에 따라 각각 10, 12
    int left = 10;
    int right = 12;
    
    for (int &n : numbers)
    {
        char h;
        
        // 0은 자리 위치에 따라 11
        if (n == 0) n = 11;
        
        // 왼손
        if ((n - 1) % 3 == 0) h = 'l';
        // 오른손
        else if ((n - 1) % 3 == 2) h = 'r';
        // 중간
        else
        {
            // 왼손, 오른손과 n까지의 거리 구하기
            int leftDist = abs((n - 1) / 3 - (left - 1) / 3) + abs((n - 1) % 3 - (left - 1) % 3);
            int rightDist = abs((n - 1) / 3 - (right - 1) / 3) + abs((n - 1) % 3 - (right - 1) % 3);
            
            // 비교 후 가까운 손으로
            h = (leftDist > rightDist) ? 'r' : (leftDist < rightDist) ? 'l' : hand.front();
        }
        
        // 손에 따라 결과 바꾸기
        if (h == 'l')
        {
            answer += "L";
            left = n;
        }
        else if (h == 'r')
        {
            answer += "R";
            right = n;
        }
    }
    
    return answer;
}
