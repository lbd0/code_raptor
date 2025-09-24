#include <string>
#include <cctype>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void counting(const string &str, unordered_map<string, int> &m)
{
    for (int i = 0; i < str.size() - 1; ++i)
    {
        // 글자 쌍이 알파벳이라면 대문자로 바꿔 맵에 넣기
        if (isalpha(str[i]) && isalpha(str[i + 1]))
        {
            char a = toupper(str[i]);
            char b = toupper(str[i + 1]);
            // string 생성자를 통해 문자열로 저장
            string temp = string() + a + b;
            ++m[temp];
        }
        else if (!isalpha(str[i + 1])) ++i;
    }
}

int solution(string str1, string str2) {
    int answer = 0;
    unordered_map<string, int> m1;
    unordered_map<string, int> m2;
    
    counting(str1, m1);
    counting(str2, m2);
    
    // 전체 키를 넣을 set 생성
    unordered_set<string> keywords;
    
    // m1과 m2의 key 값만 keywords에 넣기
    for (const auto& [k, _] : m1) keywords.insert(k);
    for (const auto& [k, _] : m2) keywords.insert(k);
    
    // 교집합, 합집합
    int inter = 0, uni = 0;
    
    for (const auto& k : keywords)
    {
        // min은 교집합, max는 합집합
        inter += min(m1[k], m2[k]);
        uni += max(m1[k], m2[k]);
    }

    // uni가 0일 경우 나눌 때 오류 생김
    answer = (uni == 0) ? 65536 : static_cast<int>((double)inter / uni * 65536); ;
    
    return answer;
}
