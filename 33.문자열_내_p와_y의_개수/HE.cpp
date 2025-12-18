#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0;
    int y = 0;
    bool answer = true;

    for (char c : s) {
        if (c == 'p' || c == 'P') p++;
        else if (c == 'y' || c == 'Y') y++;
    }

    if(p != y) answer = false;

    return answer;
}
