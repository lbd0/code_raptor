#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sides) {
  
    sort(sides.begin(), sides.end(), [](int a, int b)
         {
            return a > b; 
         });
    
    return sides[0] < (sides[1]+sides[2]) ? 1 : 2;
}
