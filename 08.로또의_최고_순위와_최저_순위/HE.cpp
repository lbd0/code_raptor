#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int getRank(int match) {
    if (match >= 2)
        return 7 - match;
    else
        return 6; // 0~1개 맞으면 6등
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    int ct = 0; // 맞춘 번호 개수
    int emp = 0; // 0 개수

    for (int x : lottos) {
        if (x == 0)
            emp++;
        for (int y : win_nums) {
            if (x == y)
                ct++;
        }
    }

    int best = getRank(ct + emp); // 최고 순위: 0을 모두 맞췄을 때
    int worst = getRank(ct); // 최저 순위: 0이 모두 안 맞을 때

    return {best, worst};
}
