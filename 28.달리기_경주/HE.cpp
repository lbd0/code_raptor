#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    map<string, int> rank; // 시간 초과 떠서 map 사용
    
   for (int i = 0; i < players.size(); i++)
        rank[players[i]] = i; // 순위 저장

    for (auto c : callings) {
        int i = rank[c];

        string p = players[i - 1];
        players[i - 1] = players[i];
        players[i] = p;

        rank[c] = i - 1;
        rank[p] = i;
    }

    return players;
}
