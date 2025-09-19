#include <string>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {

    map<char, int> score; // 점수 계산 map
    string types;

    for (int i = 0; i < survey.size(); i++) {
        string s1 = survey[i]; //survey의 왼쪽 오른쪽 값 분리
        int choice = choices[i];

        int point = abs(choice - 4); //점수 계산

        if (choice < 4) // choice가 4보다 작으면 왼쪽 문자에게 점수 추가
            score[s1[0]] += point;
        else if (choice > 4)
            score[s1[1]] += point;// choice가 4보다 크면 오른쪽 문자에게 점수 추가
    }

    string result;
    vector<pair<char,char>> pairs = {{'R','T'}, {'C','F'}, {'J','M'}, {'A','N'}};

    for (auto [a, b] : pairs) {
        result.push_back(score[a] >= score[b] ? a : b); // score[a] >= score[b] 이면 왼쪽 선택
    }

    return result;
}
