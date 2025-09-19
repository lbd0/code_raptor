#include <vector>
#include <algorithm>

using namespace std;

// 등수 체크
int checkLottos(const int &cnt)
{
        switch (cnt)
    {
        case 6:
            return 1;
        case 5:
            return 2;
        case 4:
            return 3;
        case 3:
            return 4;
        case 2:
            return 5;
        default:
            return 6;
    }
}

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    
    // 정렬
    sort(lottos.begin(), lottos.end());
    sort(win_nums.begin(), win_nums.end());
    
    // 0의 개수 카운트
    int zeroCnt = count(lottos.begin(), lottos.end(), 0);
    // 맞은 개수 카운트
    int jackpot = 0;
    
    // 0 건너뛰고 시작
    for (int i = zeroCnt; i < lottos.size(); ++i)
    {
        for (const int &w : win_nums)
        {
            // 정렬했기 때문에 w가 크면 그만하기
            if (lottos[i] < w) break;
            else if (lottos[i] == w)
            {
                ++jackpot;
                break;
            }
        }
    }
    
    answer.push_back(checkLottos(jackpot + zeroCnt));
    answer.push_back(checkLottos(jackpot));
    
    return answer;
}
