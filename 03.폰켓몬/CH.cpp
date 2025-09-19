#include <vector>
#include <unordered_map>

int solution(std::vector<int> nums)
{
    // 포켓몬을 저장할 맵
    std::unordered_map<int, int> pokemons;

    // 포켓몬 수 체크
    for (const int &n : nums) ++pokemons[n];

    // 비교하여 반환
    return pokemons.size() > (nums.size() / 2) ? nums.size() / 2 : pokemons.size();
}
