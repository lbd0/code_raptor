#include <string>

using namespace std;

string solution(string s, string skip, int index) {
    for (auto& c : s) {
        int cnt = 0;
        
        while (cnt < index) {
            if (++c > 'z') c -= 26;
            if (skip.find(c) != string::npos) continue;
            
            ++cnt;
        }
    }
    
    return s;
}
