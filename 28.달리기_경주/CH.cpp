#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    unordered_map<string, int> rank;

    for (int i = 0; i < players.size(); ++i) rank[players[i]] = i;
        
    for (const auto& c : callings) {
        int idx = rank[c];
        string name = players[idx - 1];
        
        ++rank[name];
        --rank[c];
        
        players[idx] = name;
        players[idx - 1] = c;
    }
    
    return players;
}
