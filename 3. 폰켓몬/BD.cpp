#include <vector>
#include <map>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    // 폰켓몬의 종류와 개수를 저장할 map. key = 종류, value = 개수.
    map<int, int> types;
    
    // 폰켓몬의 종류와 개수 map에 저장.
    for(auto& n:nums)
    {
        types[n]++;
    }
    
    // 폰켓몬의 종류가 선택할 수 (N/2) 보다 많으면 선택할 수가 최대, 폰켓몬 종류가 더 적으면 폰켓몬 종류가 최대.
    answer = types.size() > nums.size()/2 ? nums.size()/2:types.size();
    
    return answer;
}
