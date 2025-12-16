#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string answer = "";
    vector<string> day = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
    vector<int> month = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int total = 0;

    for (int i = 0; i < a - 1; i++) { // 달 -> 일 변환
        total += month[i];
    } 

    total += b;

    answer = day[(total + 4) % 7];
    
    return answer;
}
