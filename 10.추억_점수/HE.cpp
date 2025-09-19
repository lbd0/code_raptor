#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    map<string, int> miss; //이름, 그리움 점수 저장

    for (int i = 0; i < name.size(); i++) {
        miss[name[i]] = yearning[i];
    }

    for (auto p : photo) {
        int sum = 0; //추억 점수
        for (auto person : p) {
            if (miss.find(person) != miss.end()) { //map에 있는 사람만 점수 계산
                sum += miss[person];
            }
        }
        answer.push_back(sum);
    }

    return answer;
}
