#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int a = 0; a < commands.size(); a++){
        int i = commands[a][0] - 1;
        int j = commands[a][1];
        int k = commands[a][2] - 1;
        vector<int> x;
        for (int b = i; b < j; b++)
            x.push_back(array[b]);
        sort(x.begin(), x.end()); //정렬
        answer.push_back(x.at(k));
    }
    return answer;
}
