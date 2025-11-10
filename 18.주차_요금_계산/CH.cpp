#include <string>
#include <vector>
#include <map>

using namespace std;

// 누적 시간 계산
int calcTime(const string& inStr, const string& outStr) 
{
    int in = stoi(inStr.substr(0, 2)) * 60 + stoi(inStr.substr(3, 2));
    int out = (outStr != "0") ? stoi(outStr.substr(0, 2)) * 60 + stoi(outStr.substr(3, 2)) : 1439;
    return out - in;
}

// 요금 계산
int calcFee(int total, const vector<int>& fees) 
{
    // 기본 시간 이하일 경우
    if (total <= fees[0]) return fees[1];
    
    // 올림 계산
    int extra = (total - fees[0] + fees[2] - 1) / fees[2];
    return fees[1] + extra * fees[3];
}

vector<int> solution(vector<int> fees, vector<string> records) {
    map<string, string> in;         // 입차 시간 저장
    map<string, int> total;         // 차량별 총 주차 시간

    for (const string& r : records) {
        string time = r.substr(0, 5);
        string car = r.substr(6, 4);
        string type = r.substr(11);

        if (type == "IN") in[car] = time;
        else 
        {
            total[car] += calcTime(in[car], time);
            in.erase(car);
        }
    }

    // 출차 안 한 차량
    for (const auto& i : in) total[i.first] += calcTime(i.second, "0");

    // 차량 별 요금 계산
    vector<int> answer;
    
    for (const auto& t : total) answer.push_back(calcFee(t.second, fees));

    return answer;
}
