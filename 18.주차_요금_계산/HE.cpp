#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

int timeToMin(string t) { //시간 분으로 변환
    int h = stoi(t.substr(0 , 2));
    int m = stoi(t.substr(3 , 2));
    return h * 60 + m;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, pair<int,int>> rcd; // 차량번호에 따른 입차시간과 누적시간 저장
    vector<int> answer;

    for (auto rec : records) {
        string time, car, status;
        stringstream ss(rec);
        ss >> time >> car >> status; // 공백 기준으로 분리

        int minutes = timeToMin(time);

        if (status == "IN") {
            rcd[car].first = minutes; //입차시간 저장
        } 
        else { // 출차일 때
            rcd[car].second += (minutes - rcd[car].first); //누적시간 저장
            rcd[car].first = -1; //빠져나간 차량은 -1 처리
        }
    }

    for (auto &p : rcd) {
        if (p.second.first != -1) { // 24시 이전까지 빠져나가지 않은 차 계산
            p.second.second += (timeToMin("23:59") - p.second.first);
            p.second.first = -1;
        }
    }

    for (auto &p : rcd) { // map은 기본적으로 key값 오름차순
        int t = p.second.second;
        int fee = fees[1];

        if (t > fees[0]) { // 기본 시간 초과할 경우 요금 정산
            fee += ((t - fees[0] + fees[2] - 1) / fees[2]) * fees[3];
        }

        answer.push_back(fee);
    }

    return answer;
}
