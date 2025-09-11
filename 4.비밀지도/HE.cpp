#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string toBinary(int num, int n) { //이진수로 변환 함수
    string s = "";
    
    while(num > 0) {
        s.push_back((num % 2) + '0'); //string으로 저장하기 위함
        num /= 2;
    }

    while(s.size() < n)
        s.push_back('0');
    
    reverse(s.begin(), s.end()); //뒤집어서 이진수 완성
    return s;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i < n; i++) {
        string s1 = toBinary(arr1[i], n);
        string s2 = toBinary(arr2[i], n);
        
        string result = "";
        for(int j = 0; j < n; j++) {
            if(s1[j] == '1' || s2[j] == '1') result += "#"; // 둘 중 하나라도 1을 가지고 있으면 벽 막기
            else result += " ";
        }
        answer.push_back(result);
    }
    
    return answer;
}
