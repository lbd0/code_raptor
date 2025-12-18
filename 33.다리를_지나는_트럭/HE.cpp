#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0; // 다리 위 트럭 무게
    int idx = 0;
    queue<int> bridge; 

    for (int i = 0; i < bridge_length; i++) {
        bridge.push(0);
    }

    while (idx < truck_weights.size()) {
        answer++;
        sum -= bridge.front(); // 다리 빠짐
        bridge.pop();

        if (sum + truck_weights[idx] <= weight) { // 새 트럭 올리기
            bridge.push(truck_weights[idx]);
            sum += truck_weights[idx];
            idx++;
        } else {
            bridge.push(0);
        }
    }

    answer += bridge_length;

    return answer;
}
