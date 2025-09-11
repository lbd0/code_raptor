#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 10진수->2진수 변환 함수
vector<int> dec2bin(int n, int dec)
{
    vector<int> bin;
    
    do
    {
        bin.push_back(dec%2);
        
        dec /= 2;
        
        if(bin.size() == n) break;
    } while(true);
    
    reverse(bin.begin(), bin.end());
    return bin;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    // 지도 1
    vector<vector<int>> map1;
    // 지도 2
    vector<vector<int>> map2;
    
    // 지도 1 채우기 (10진수->2진수 변환)
    for(auto& a:arr1)
    {
        map1.push_back(dec2bin(n, a));
    }
    
    // 지도 2 채우기 (10진수->2진수 변환)
    for(auto& a:arr2)
    {
        map2.push_back(dec2bin(n, a));
    }
    
    // 비밀지도 암호 해독
    for(int i=0; i<n; ++i)
    {
        string temp = "";
        for(int j=0; j<n; ++j)
        {
            // 1개라도 참이면 참 => OR 연산
            map1[i][j] | map2[i][j] ? temp+="#":temp+=" ";
        }
        answer.push_back(temp);
    }
    
    return answer;
}
