#include <iostream>
#include<string>
#include<vector>

using namespace std;

int solution(string s)
{
    int answer = -1;
    vector<char> num;

    for(char n : s) { //벡터에 숫자 넣을 때마다 이전에 들어간 숫자와 비교
        if(!num.empty() && num.back() == n) { 
            num.pop_back(); //숫자 삭제
        } else {
            num.push_back(n); //숫자 삽입
        }
    }
    
    if(num.empty()) // 벡터가 비었을 경우 (다 제거된 경우) 1 
        answer = 1;
    else
        answer = 0;


    return answer;
}
