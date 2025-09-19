#include <string>
#include <vector>
#include <set>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2, 0); //크기 지정 안 하면 오류 남
    set<string> word; //중복체크 set
    word.insert(words[0]); //첫번째 단어 넣기

    char pword_f = words[0].back(); //마지막 글자

    for (int i = 1; i < words.size(); i++) {
        string c_word = words[i]; //현재 단어

        if (c_word[0] != pword_f || word.count(c_word)) { //전 단어 마지막 글자와 현단어 첫번째 글자가 다르면 or 이미 나온 단어가 나오면 answer 저장
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            return answer;
        }

        word.insert(c_word);
        pword_f = c_word.back();
    }

    return answer;
}
