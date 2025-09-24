#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    
    // 사전.
    unordered_map<string, int> dic;
    
    // 사전을 초기화하기 위한 준비.
    int alpha = 65;
    int idx = 1;
    
    // 사전에서 현재 입력과 일치하는 가장 긴 문자열 저장할 변수.
    string w;
    
    // 사전 초기화 (길이가 1인 모든 단어).
    for(int i=0; i<26; ++i)
    {
        string str = "";
        str = char(alpha);
        dic[str] = idx++;
        alpha++;
    }
    
    // LZW 압축 2~5 과정.
    while(!msg.empty())
    {
        string temp = "";
        
        // 사전에서 현재 입력과 일치하는 가장 긴 문자열 찾음.
        for(auto& m:msg)
        {
            temp += m;
        
            if(dic.find(temp) != dic.end())
            {
                w = temp;
            } 
            else break;
        }
        // w에 해당하는 색인 번호 출력.
        answer.push_back(dic[w]);
        // w 제거.
        msg.erase(0, w.length());
        
        // 다음 글자가 남아 있다면, w+c에 해당하는 단어 사전에 등록.
        if(!msg.empty())
        {
            string c = msg.substr(0, 1);
            dic[w+c] = idx++;
        }
   }
    
    return answer;
}
