#include <string>
#include <vector>
using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int maxHealth = health;
    int t = 0;
    int suc = 0;
    int idx = 0;
    int attack = attacks.back()[0];

    for (t = 0; t <= attack; t++) {
        if (idx < attacks.size() && attacks[idx][0] == t) {
            health -= attacks[idx][1]; // 공격 받음
            
            if (health <= 0) return -1; // 죽음
            
            suc = 0;
            idx++; // 다음 공격
        } else {
            health += bandage[1]; // 회복
            suc++;

            if (suc == bandage[0]) { // 연속 성공 추가 회복
                health += bandage[2];
                suc = 0;
            }

            if (health > maxHealth) health = maxHealth;
        }
    }

    return health;
}
