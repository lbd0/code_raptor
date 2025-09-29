#include <string>
#include <vector>
#include <cctype>
#include <algorithm>

using namespace std;

// 문장 파싱을 위한 함수
tuple<string, int, string> parse(const string& file)
{
    string h, n;
    int i = 0;
        
    // 숫자가 나오기 전은 head, 숫자(최대 5개)는 number에 저장
    while (i < file.size() && !isdigit(file[i])) h += file[i++];
    while (i < file.size() && isdigit(file[i]) && n.size() < 5) n += file[i++];
    
    return {h, stoi(n), file};
}

void sorting(vector<tuple<string, int, string>>& parsed)
{
    // 동일한 값의 순서 보장을 위한 stable_sort 사용
    stable_sort(parsed.begin(), parsed.end(), [](const auto& a, const auto& b) {
        if (get<0>(a) != get<0>(b)) return  get<0>(a) < get<0>(b);  // head
        return  get<1>(a) < get<1>(b);  // number
    });
}

vector<string> solution(vector<string> files) {
    vector<string> answer;
    // head, number, 원본 저장을 위한 vector
    vector<tuple<string, int, string>> parsed;
    
    for (const string& f : files)
    {
        // parse 결과를 저장
        auto [head, num, file] = parse(f);
        
        // 소문자 변환
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        
        // parsed에 추가
        parsed.emplace_back(head, num, file);
    }
    
    sorting(parsed);
    
    // 정렬된 파일명을 answer에 저장
    for (const auto& p : parsed) answer.push_back(get<2>(p));

    return answer;
}
