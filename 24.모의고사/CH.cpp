#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<vector<int>> supo = { {1, 2, 3, 4, 5}, 
                                 {2, 1, 2, 3, 2, 4, 2, 5}, 
                                 {3, 3, 1, 1, 2, 2, 4, 4, 5, 5} };
    vector<int> score (3, 0);
    vector<int> answer;
    
    for (int i = 0; i < answers.size(); ++i) {
        if (answers[i] == supo[0][i % supo[0].size()]) ++score[0];
        if (answers[i] == supo[1][i % supo[1].size()]) ++score[1];
        if (answers[i] == supo[2][i % supo[2].size()]) ++score[2];
    }
    
    int maxScore = max(score[0], max(score[1], score[2]));
    
    for (int i = 0; i < score.size(); ++i) if (maxScore == score[i]) answer.push_back(i + 1);
    
    return answer;
}
