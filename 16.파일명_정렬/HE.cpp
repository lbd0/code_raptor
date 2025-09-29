#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

bool compareFiles(const pair<pair<string,int>, string> a, const pair<pair<string,int>, string> b) { //stable_sort()함수용 비교 함수
    string h1 = a.first.first; // a의 header
    string h2 = b.first.first; // b의 header

    transform(h1.begin(), h1.end(), h1.begin(), ::tolower); //a와 b의 header를 소문자로 변환
    transform(h2.begin(), h2.end(), h2.begin(), ::tolower);

    if (h1 == h2) //header 값이 같을 경우 number 값으로 비교
        return a.first.second < b.first.second;
    return h1 < h2;
}

vector<string> solution(vector<string> files) {
    vector<pair<pair<string,int>, string>> sep; // <<header, number>, 파일명> 저장

    for (auto file : files) {
        string head = "";
        string number = "";
        int i = 0;
        
        while (i < file.size() && !isdigit(file[i])) //숫자가 나오기 전까지 head에 저장
            head += file[i++];
        while (i < file.size() && isdigit(file[i]) && number.size() < 5) //숫자일 경우 다섯 글자까지 number에 저장
            number += file[i++];
        sep.push_back({{head, stoi(number)}, file});
    }
  
    stable_sort(sep.begin(), sep.end(),compareFiles); //stable_sort()함수는 sort()함수와 달리 같은 값을 비교할 때 기존 순서를 유지함

    vector<string> answer;
    for (auto p : sep) answer.push_back(p.second);
    return answer;
}
