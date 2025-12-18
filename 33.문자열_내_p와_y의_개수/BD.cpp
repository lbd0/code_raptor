#include <string>

using namespace std;

bool solution(string s)
{
    int p=0, y=0;

    for(auto s1 : s)
    {
        if(s1 == 'p' || s1 == 'P') 
        {
            ++p;
            continue;
        }
        else if(s1 == 'y' || s1 == 'Y')
        {
            ++y;
            continue;
        }
    }
    
    return (p==y) ? true:false;
}
