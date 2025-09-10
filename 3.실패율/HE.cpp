#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    sort(stages.begin(), stages.end()); //정렬

    int player = stages.size(); // 플레이어 수
    vector<pair<double,int>> result; // 실패율이랑 스테이지 저장

    int i = 0;
    for(int j=1; j<=N; j++){
        int count = 0;
        while(i < stages.size() && stages[i] == j){
            count++; //해당 스테이지에 머무는 사람 수
            i++;
        }
        double rate = 0; //실패율
        if(player > 0) rate = (double)count / player; 
        result.push_back({-rate, j}); //실패율 내림차순으로 저장하기 위함

        player -= count; //남은 플레이어 수
    }
    sort(result.begin(), result.end()); //정렬

    for(auto &p : result) answer.push_back(p.second);
    return answer;
}
