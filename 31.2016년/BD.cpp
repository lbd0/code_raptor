#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    
    vector<string> days = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    
    int cnt = 0;
    
    for(int i=1; i<a; ++i)
    {
        if(i < 8)
        {
            if(i%2 != 0) cnt += 31;
            else if(i == 2) cnt += 29;
            else cnt += 30;
        }
        else
        {
            if(i%2 == 0) cnt += 31;
            else cnt += 30;
        }
    }
    
    cnt += b-1;
    
    return days[cnt%days.size()];
}
