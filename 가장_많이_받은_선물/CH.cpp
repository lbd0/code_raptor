#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 주고받은 선물 기록
    map<string, map<string, int>> table;
    // 선물 지수
    map<string, int> count;
    // 다음 달 받을 선물
    map<string, int> next;
    
    // 맵 초기화
    for (auto &f : friends) 
    {
        count[f] = 0;   // 선물 지수 0으로 초기화
        next[f] = 0;    // 받을 선물 수 0으로 초기화
        
        for (auto &g : friends) 
        {
            if (f == g) continue;
            table[f][g] = 0;  // f → g 선물 횟수
        }
    }
    
    // 주고받은 선물 정리 + 선물 지수 계산
    for (string &str : gifts) 
    {
        stringstream ss(str);
        string giver, receiver;
        ss >> giver >> receiver;
        
        ++table[giver][receiver]; // giver → receiver 선물
        ++count[giver];           // 선물 준 사람 +1
        --count[receiver];        // 선물 받은 사람 -1
    }
    
    // 다음 달 선물 계산
    for (int i = 0; i < friends.size(); ++i) {
        // 중복은 보지 않음
        for (int j = i + 1; j < friends.size(); ++j) {
            string A = friends[i];
            string B = friends[j];
            
            // 선물을 주고받은 기록이 없거나 같을 때
            if ((table[A][B] == 0 && table[B][A] == 0) ||
                table[A][B] == table[B][A]) 
            {
                // 지수도 같으면 패스
                if (count[A] == count[B]) continue; 
                
                (count[A] > count[B]) ? ++next[A] : ++next[B];
            }
            // 기록이 다를 때
            else 
            {
                (table[A][B] > table[B][A]) ? ++next[A] : ++next[B];
            }
        }
    }
    
    // 가장 많이 받을 선물 수
    for (const auto &m : next) 
    {
        answer = max(answer, m.second);
    }
    
    return answer;
}
