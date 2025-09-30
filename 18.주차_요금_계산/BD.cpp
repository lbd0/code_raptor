#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

// 문자열 나누는 함수.
vector<string> split(string str,string de)
{
    vector<string> res;
    int cur = 0;
    int pos = 0;
    string temp = "";
    
     while((pos = str.find(de, cur)) != string::npos)
     {
         int len = pos - cur;
         temp = str.substr(cur, len);
         cur = pos + 1;
         if(!temp.empty()) res.push_back(temp);
     }
    
    temp = str.substr(cur);
    if(!temp.empty()) res.push_back(temp);
    
    return res;
}

// 시간을 분으로 변환하는 함수.
int changeMinute(string str)
{
    vector<string> time = split(str, ":");
    
    return stoi(time[0]) * 60 + stoi(time[1]);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    // 키 : 차량 번호, 값 : 입차 시간.
    unordered_map<string, int> in_time;
    
    // 키 : 차량 번호, 값 : 누적 주차 시간.
    unordered_map<string, int> parking;
    
    // 차량 번호 저장할 벡터.
    vector<string> car_nums;
    
    // 누적 주차 시간 계산.
    for(const auto& r:records)
    {
        vector<string> rec = split(r, " ");
        
        string car_num = rec[1];
        int time = changeMinute(rec[0]);
        
        // 입차 시간은 in_time 맵에 저장.
        if(rec[2].compare("IN") == 0) 
        {
            in_time[car_num] = time;
            continue;
        }
        
        // 출차면, 주차 시간 계산.
        parking[car_num] += time - in_time[car_num];
        
        in_time.erase(car_num);
    }
    
    // 출차 시간 없는 차량 계산.
    for(const auto& i:in_time)
    {
        parking[i.first] += changeMinute("23:59") - i.second;
    }
    
    // 차량 번호 순 정렬.
    for(const auto& p:parking)
    {
        car_nums.push_back(p.first);
    }
    sort(car_nums.begin(), car_nums.end());
    
    // 주차 요금 계산.
    for(const auto& c:car_nums)
    {
        int pt = parking[c];
        int charge = 0;
        
        if(pt > fees[0])
        {
            charge += ceil((double)(pt - fees[0]) / fees[2]) * fees[3];
        }
        
        charge += fees[1];
        
        answer.push_back(charge);
    }
    
    return answer;
}
