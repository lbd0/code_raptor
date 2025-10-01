#include <string>
#include <set>
using namespace std;

int solution(string dirs) {
    set<pair<pair<int,int>, pair<int,int>>> way; // 중복없이 경로 저장
    pair<int,int> cur = {0,0}; // 현재 위치
    pair<int,int> nxt = {0,0}; // 이동 위치

    for (char d : dirs) {
        nxt = cur;

        if (d == 'U') nxt.second++;
        else if (d == 'D') nxt.second--;
        else if (d == 'R') nxt.first++;
        else nxt.first--;

        if (nxt.first < -5 || nxt.first > 5 || nxt.second < -5 || nxt.second > 5)
            continue; // 범위 벗어날 경우 지나감

        if (cur < nxt) way.insert({cur, nxt});
        else way.insert({nxt, cur});

        cur = nxt;
    }

    return way.size();
}
