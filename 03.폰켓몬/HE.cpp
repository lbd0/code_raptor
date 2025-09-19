#include <vector>
#include <set>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    set<int> pokemon; //중복 불가 set
    for(int i = 0; i < nums.size(); i++){
        pokemon.insert(nums[i]); // 중복 제거
    }
    answer = pokemon.size();
    
    if(pokemon.size()>nums.size()/2) //set size가 nums의 절반보다 크다면 최대로 데려갈 수 있는 nums 절반 값으로 설정
        answer = nums.size()/2;

    return answer;
}
