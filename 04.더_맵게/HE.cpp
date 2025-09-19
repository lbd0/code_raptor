//힙 설명 다시 읽으면서 풀었어요
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end()); //top()값 최소로
    int answer = 0;

    while(pq.top() < K) {
        if(pq.size() < 2) //스코빌 지수를 K 이상으로 만들 수 없는 경우 = 음식 수가 부족한 경우
            return -1;

        int first = pq.top(); // pq.top() = 가장 지수 낮은 음식
        pq.pop();
        int second = pq.top();
        pq.pop();

        int food = first + (second * 2);
        pq.push(food);
        answer++;
    }

    return answer;
}
