#include <string>
#include <vector>
#include <map>
using namespace std;

int toDays(string date) { //날짜를 day(일)로 변환하는 함수
    int year = stoi(date.substr(0, 4)); // 연도
    int month = stoi(date.substr(5, 2)); // 월
    int day = stoi(date.substr(8, 2)); // 일
    return (year * 12 * 28) + (month * 28) + day; //변환
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<string, int> m1; // 약관이랑 기간 저장

    for (int i = 0; i < terms.size(); i++) {
        string cur = terms[i];
        int pos = cur.find(' '); // 공백 기준으로 약관이랑 기간 분리해서 저장
        string type = cur.substr(0, pos);
        int months = stoi(cur.substr(pos + 1));
        m1[type] = months;
    }

    int todayDays = toDays(today); // 오늘 날짜 변환

    for (int i = 0; i < privacies.size(); i++) { // 날짜랑 약관 분리해서 저장
        string cur = privacies[i];
        string date = cur.substr(0, 10); // 날짜
        string type = cur.substr(11); // 약관

        int day = toDays(date); // 수집 날짜 변환
        int expire = day + (m1[type] * 28) - 1; // 만료일

        if (expire < todayDays) {
            answer.push_back(i + 1);
        }
    }

    return answer;
}
