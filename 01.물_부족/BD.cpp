#include <string>
#include <vector>

using namespace std;

int solution(int storage, int usage, vector<int> change) {
    int total_usage = 0;
    for(int i=0; i<change.size(); i++){
        usage += usage * change[i] / 100;    // total_usage -> usage 변경, += 추가 
      // 근데 이거 왜 usage += usage * (change[i] / 100); 이렇게하면 틀리는지 아는 사람??
        total_usage += usage;
        if(total_usage > storage){
            return i;
        }
    }
    return -1;
}
