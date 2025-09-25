#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    
    // 상하좌우 방향 나타내는 enum 클래스.
    enum class Direction{Right, Left, Up, Down};
    // 시작은 오른쪽으로 이동.
    Direction dir = Direction::Right;
    // 벡터에 저장할 숫자.
    int num = 1;
    // 인덱스.
    int x=0,y=0;
    
    while(true)
    {
        if(num > n*n) break;
        
        answer[x][y] = num++;
        
        switch(dir)
        {
                // 오른쪽으로 숫자 채우기.
            case Direction::Right:
                if(y < n-1 && answer[x][y+1] == 0) y++;
                else 
                {
                    x++;
                    dir = Direction::Down;
                }
                break;
            // 왼쪽으로 숫자 채우기.    
            case Direction::Left:
                if(y > 0 && answer[x][y-1] == 0) y--;
                else 
                {
                    x--;
                    dir = Direction::Up;
                }
                break;
             // 위로 숫자 채우기.
            case Direction::Up:
                if(x > 0 && answer[x-1][y] == 0) x--;
                else 
                {
                    y++;
                    dir = Direction::Right;
                }
                break;
             // 아래로 숫자 채우기.   
            case Direction::Down:
                if(x < n-1 && answer[x+1][y] == 0) x++;
                else 
                {
                    y--;
                    dir = Direction::Left;
                }
                break;
        }
        
    }
    
    return answer;
}
