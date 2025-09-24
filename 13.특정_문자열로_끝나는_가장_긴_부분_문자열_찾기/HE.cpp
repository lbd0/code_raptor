#include <string>
#include <vector>

using namespace std;

string solution(string myString, string pat) {
    string answer = "";

    for (int i = myString.size() - pat.size(); i >= 0; i--) { //뒤에서부터 문자열 비교
        if (myString.substr(i, pat.size()) == pat) {
            answer = myString.substr(0, i + pat.size()); //pat과 같은 문자열일 경우 pat과 함께 answer에 저장
            break; // 비교하자마자 빠져나가기
        }
    }

    return answer;
}
