#include <string>

using namespace std;

string solution(string phone_number) {
    for (int i = 0; i < phone_number.size() - 4; ++i) phone_number.replace(i, 1, "*");
    
    return phone_number;
}
