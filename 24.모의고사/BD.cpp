#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 각 수포자들이 찍는 방식, 맞힌 문제 수 저장할 변수.
    int one[5] = { 1, 2, 3, 4, 5 }, ocnt = 0;
    int two[8] = { 2, 1, 2, 3, 2, 4, 2, 5 }, tcnt = 0;
    int three[10] = { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 }, thcnt = 0;
    
    // 각 수포자들 맞힌 문제 수 저장.
    for(int i=0; i<answers.size(); ++i)
    {
        if(answers[i] == one[i%5]) ocnt++;
        if(answers[i] == two[i%8]) tcnt++;
        if(answers[i] == three[i%10]) thcnt++;
    }
    
    // 가장 많이 맞힌 개수 저장.
    int max = (ocnt >= tcnt) ? ocnt : tcnt;
    max = max <= thcnt ? thcnt : max;
    
    // 가장 많이 맞힌 사람 저장.
    if(ocnt == max) answer.push_back(1);
    if(tcnt == max) answer.push_back(2);
    if(thcnt == max) answer.push_back(3);
    
    return answer;
}
