#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = health;
    int time = 0;
    int att = 0;
    int success = 0;
    
    while (true) {
        if (att >= attacks.size()) break;
        
        ++time;
        if (time == attacks[att][0]) {
            answer -= attacks[att][1];
            success = 0;
            ++att;
            
            if (answer <= 0) return -1;
        }
        else {
            if (++success >= bandage[0]) {
                success = 0;
                answer += bandage[2];
            }
        
            answer += bandage[1];
            
            if (answer > health) answer = health;
        }
    }
    
    return answer;
}
