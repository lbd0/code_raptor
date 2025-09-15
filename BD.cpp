#include <string>
#include <vector>
#include <map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    
    // 성격 유형 저장한 벡터.
    vector<char> types = { 'R', 'T', 'C', 'F', 'J', 'M', 'A', 'N' };
    
    // 성격 유형 별 점수 저장할 맵.
    map<char, int> count;
    
    // 맵에 점수 저장.
    for(int i=0; i<survey.size(); ++i)
    {
        // survey에서 앞에 있는 문자 : 비동의.
        char key1 = survey[i][0];
        // 뒤에 있는 문자 : 동의.
        char key2 = survey[i][1];
        
        // 문제에서 주어진 점수 배치에 따라 맵에 점수 저장.
        switch(choices[i])
        {
            case 1:
                count[key1] += 3;
                break;
                
            case 2:
                count[key1] += 2;
                break;
                
            case 3:
                count[key1] += 1;
                break;
                
            case 5:
                count[key2] += 1;
                break;
                
            case 6:
                count[key2] += 2;
                break;
                
            case 7:
                count[key2] += 3;
                break;
                
            default:
                break;
        }
    }
    
    // 맵에 저장된 점수에 따라 유형 선택.
    for(int i=0; i<types.size()-1; i+=2)
    {
        if(count[types[i]] > count[types[i+1]])
        {
            answer += types[i];
        }
        // 점수가 같으면 알파벳 사전순으로 빠른 것.
        else if(count[types[i]] == count[types[i+1]])
        {
            answer += types[i]>types[i+1] ? types[i+1]:types[i];
        }
        else 
        {
            answer += types[i+1];
        }
    }
    
    return answer;
}
