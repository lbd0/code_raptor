#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, int w, int num) {
    int answer = 0;
    
    // 꺼내야 하는 상자의 위치를 저장할 변수들.
    int idx = 0, idy = 0;;
    
    // 상자를 쌓는 방향이 바뀌는지 확인하는 변수.
    bool change = false;
    
    // 상자를 쌓을 이중 벡터.
    vector<vector<int>> boxes;
   
    // 이중 벡터에 넣을 벡터.
    vector<int> box;
    
    // 상자 쌓기
    for(int i=1; i<=n; ++i)
    {
        // 상자를 일반 벡터에 저장.
        box.push_back(i);
        
        // 일반 벡터의 크기가 w (너비) 이면, 상자 쌓는 이중 벡터에 저장.
        if(box.size() == w)
        {
            // 방향이 바뀌면
            if(change)
            {
                // 뒤집어서 정렬.
                sort(box.rbegin(), box.rend());
            }
            // 상자 쌓는 벡터에 넣어주고, 일반 벡터 초기화 및 다음에 쌓을 땐 방향 바꾸기.
            boxes.push_back(box);
            change = !change;
            box.clear();
            box.shrink_to_fit();
        }
        
        // n까지 모두 담았는데, 일반벡터에 요소가 남아있으면, 
        if(i==n && box.size() < w && box.size() > 0)
        {
            // 빈칸은 101로 채우기 (n의 최대가 100이므로)
            while(box.size() != w)
            {
                box.push_back(101);
            }
            
            // 이중 벡터에 저장.
            if(change)
            { 
                sort(box.rbegin(), box.rend());
            }
            boxes.push_back(box);
            box.clear();
            box.shrink_to_fit();
        }
    }
    
    // 꺼낼 상자의 위치 인덱스 찾아서 저장.
    for(int i=0; i<boxes.size(); ++i)
    {
       for(int j=0; j<boxes[i].size(); ++j)
       {
           if(boxes[i][j] == num)
           {
               idx = i; 
               idy = j;
               
               break;
           }
       }
    }
    
    // 꺼낼 상자 위에 있는 상자 개수 찾기.
    for(int i=idx; i<boxes.size(); ++i)
    {
        if(boxes[i][idy] < 101) answer++;
    }
    
    return answer;
}
