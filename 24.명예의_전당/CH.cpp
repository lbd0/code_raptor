#include <algorithm>
#include <vector>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> rank;
    vector<int> answer;
    
    for (int i = 0; i < score.size(); ++i) {
        if (rank.size() < k) rank.push_back(score[i]);
        else if (rank[0] < score[i]) rank[0] = score[i];
        
        sort(rank.begin(), rank.end());
        answer.push_back(rank[0]);
    }
    
    return answer;
}
