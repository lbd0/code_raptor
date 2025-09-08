#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// delimeter 기준으로 문자열 나누기
vector<string> split(string input, string delimeter)
{
    vector<string> ret;
    long long pos = 0;
    string token = "";
    
    while((pos=input.find(delimeter)) != string::npos)
    {
        token = input.substr(0, pos);
        ret.push_back(token);
        input.erase(0, pos+delimeter.length());
    }
    
    ret.push_back(input);
    
    return ret;
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    vector<vector<int>> grid(friends.size(), vector<int>(friends.size(), 0));
    
    vector<int> rate(friends.size(), 0);
    vector<int> get(friends.size(), 0);
    
    // 친구 수 x 친구 수 행렬 그리기 -> 주고받은 선물 표
    for(auto& gift:gifts)
    {
        vector<string> split_gift = split(gift, " ");
        int x = find(friends.begin(), friends.end(), split_gift[0]) - friends.begin();
        int y = find(friends.begin(), friends.end(), split_gift[1]) - friends.begin();
        grid[x][y]++;
    }
    
    // 선물 지수 vector
    for(int i=0; i<grid.size(); ++i)
    {
        int send=0, get=0;
        
        for(int j=0; j<grid.size(); ++j)
        {
            send += grid[i][j];
            get += grid[j][i];
        }
        rate[i] = send - get; 
    }
    
    // 선물 받는 수 계산
    for(int i=0; i<grid.size(); ++i)
    {
        for(int j=i+1; j<grid.size(); ++j)
        {
            if(i==j) continue;
            
            if(grid[i][j] == grid[j][i])
            {
                if(rate[i] == rate[j]) continue;
                
                (rate[i] > rate[j]) ? get[i]++:get[j]++;
                
                continue;
            }
            
            (grid[i][j] > grid[j][i]) ? get[i]++:get[j]++;
            
        }
    }
    
    sort(get.rbegin(), get.rend());
    answer = get[0];
    
    return answer;
}
