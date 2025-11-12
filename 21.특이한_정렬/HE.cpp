#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numlist, int n) {
    vector<int> answer = numlist;
    
    sort(answer.begin(), answer.end(), [n](int a, int b) { // 절댓값 비교로 정렬
        int aa = (a >= n) ? (a - n) : (n - a);
        int bb = (b >= n) ? (b - n) : (n - b);
        
        if (aa != bb) return aa < bb; // 거리가 다르면 더 가까운 쪽
        
        return a > b; // 거리가 같으면 더 큰 쪽
    });
    
    return answer;
}
