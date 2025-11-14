#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    int n;
    
    sort(citations.begin(), citations.end()); // 오름차순 정렬
    
    for (int i = 0; i < citations.size(); i++) {
        n = citations.size() - i;
        if (citations[i] >= n) {
            answer = n;
            break;
        }
    }
    
    return answer;
}
