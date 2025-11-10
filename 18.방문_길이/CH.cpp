#include <string>
#include <set>

using namespace std;

int solution(string dirs) {
    // 시작 위치
    int x = 0, y = 0;
    // 걸어본 길을 중복 없이 저장할 set
    set<pair<pair<int, int>, pair<int, int>>> visited;
    
    for (const auto& d : dirs)
    {
        // 이동할 위치
        int mx = x, my = y;
        
        // 명령에 따라 이동
        if      (d == 'U') ++mx;
        else if (d == 'D') --mx;
        else if (d == 'R') ++my;
        else               --my;
        
        // 범위를 넘어난다면 아무것도 하지 않고 다음 명령으로 이동
        if (mx > 5 || mx < -5 || my > 5 || my < -5) continue;
        
        // 현재 위치와 이동할 위치 저장
        pair<int, int> curPos = {x, y};
        pair<int, int> movePos = {mx, my};
        
        // 중복을 방지하기 위해 현재 위치가 더 크다면 바꿔주기
        if (curPos > movePos) swap(curPos, movePos);
        
        // set에 넣기
        visited.insert({curPos, movePos});
        
        // 위치 이동
        x = mx; y = my;
    }
    
    // set의 크기가 처음 걸어본 길의 길이
    int answer = visited.size();
    
    return answer;
}
