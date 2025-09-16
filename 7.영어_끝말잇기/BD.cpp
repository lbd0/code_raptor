#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    // 게임 라운드 저장.
    int round = 1;
    // 사람 번호 저장.
    int num = 1;
    
    // 이전에 말한 단어 저장.
    vector<string> prev;
    
    for(int i=0; i<words.size(); ++i)
    {
        // 한 글자인 단어 인정 안함.
        if(words[i].size() < 1) break;
        
        // 첫 순서가 아니면,
        if(prev.size() > 0)
        {
            string p = prev[prev.size()-1];
            string w = words[i];
            
            // 앞사람 단어의 마지막 문자로 시작하는지 검사.
            if(p[p.size()-1] != w[0]) break;
        
            // 이전에 말한 단어랑 겹치는지 검사.
            if(find(prev.begin(), prev.end(), w) != prev.end())
                break;
        }
        // 다음 사람 차례
        num++;
        // 말한 단어는 이전 단어 벡터에 넣어줌.
        prev.push_back(words[i]);
        
        // 사람 순서가 n보다 크면 순서는 1로, 게임 라운드 증가.
        if(num > n)
        {
            num = 1;
            round++;
        }
        
        // 탈락자 없을 때,
        if(i == words.size()-1)
        {
            num = 0;
            round = 0;
        }
    }

    answer.push_back(num);
    answer.push_back(round);
    
    return answer;
}
