#include <string>
#include <cmath>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 문자열로 다중집합 만드는 함수.
unordered_map<string, int> makeSet(const string& str)
{
    unordered_map<string, int> res;
    
    for(int i=0; i<str.length()-1; ++i)
    {
        // 대소문자 구분 안 하므로 모두 대문자로 저장.
        char c1 = (str[i] < 'A' || str[i] > 'Z') ? str[i]-32:str[i];
        char c2 = (str[i+1] < 'A' || str[i+1] > 'Z') ? str[i+1]-32:str[i+1];
        
        // 문자가 아닌 것이 포함되어 있으면 패스.
        if(c1 < 'A' || c2 < 'A' || c1 > 'Z' || c2 > 'Z') continue;
        
        string temp = "";
        temp += c1;
        temp += c2;
        
        res[temp]++;
    }
    
    return res;
}

int solution(string str1, string str2) {
    int answer = 0;
    // 마지막에 곱해야 하는 상수.
    const int CON = 65536;
    
    // 교집합 개수.
    int intersection = 0;
    
    // 합집합 개수.
    int uni = 0;
    
    // 자카드 유사도.
    double jaccard;
    
    // 각 문자열의 다중집합.
    unordered_map<string, int> str1_set = makeSet(str1);
    unordered_map<string, int> str2_set = makeSet(str2);
    
    // 둘 다 공집합이면, 자카드 유사도 = 1;
    if(str1_set.size() == 0 && str2_set.size() == 0) return CON;
   
    for(const auto& s1:str1_set)
    {
        // 합집합 개수 구하기.
        uni += s1.second;
        
        auto it = str2_set.find(s1.first);
        
        // 교집합 개수 구하기.
        if(it != str2_set.end())
            intersection += min(s1.second, it->second);
            
    }
    
    // 합집합 개수 구하기.
    for(const auto& s2:str2_set)
    {
        uni += s2.second;
    }
    
    // 자카드 유사도 계산.
    jaccard = intersection/(double)(uni-intersection);
    
    answer = jaccard * CON;
    
    return answer;
}
