#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 1;
    
    queue<int> bridge;
    int bridge_weight = 0, idx = 0;
    vector<int> out;
    
    while(out.size() != truck_weights.size())
    {
        ++answer;
        int truck = truck_weights[idx];
        
        if(truck + bridge_weight <= weight)
        {
            bridge.push(truck);
            bridge_weight += truck;
            ++idx;
        }
        else {
            bridge.push(0);
        }
        
        if(bridge.size() == bridge_length)
        {
            int out_truck = bridge.front();
            
            if(out_truck != 0)
            {
                out.emplace_back(out_truck);
                bridge_weight -= out_truck;
            }
            
            bridge.pop();
        }
    }
    
    return answer;
}
