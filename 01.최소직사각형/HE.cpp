#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int w = 0;
    int h = 0;
    
    for(int i = 0; i < sizes.size(); i++){
        if(sizes[i][0] < sizes[i][1]) //명함 크기 비교
            swap(sizes[i][1], sizes[i][0]); //명함 회전
        
        w = max(w, sizes[i][0]);
        h = max(h, sizes[i][1]); //명함 가로 세로 길이 최댓값 찾아서 계산
    }
    answer = w * h;
    return answer;
}
