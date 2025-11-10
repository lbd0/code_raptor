#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 분으로 만들기
int toMinute(string s) {
    int hour = stoi(s.substr(0, 2));
    int min = stoi(s.substr(3, 2));
    
    return hour * 60 + min;
}

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> book;
    
    // 시작 시간, 종료 시간 + 청소 시간
    for (const auto &b : book_time)
        book.push_back({toMinute(b[0]), toMinute(b[1]) + 10});
    
    // 시작 시간 기준 정렬 
    sort(book.begin(), book.end(),
        [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first < b.first;   
        });
    
    // 현재 사용 중인 객실의 종료 시간
    priority_queue<int, vector<int>, greater<int>> bookq;
    
    for (const auto& [start, end] : book)
    {
        // 가장 빨리 끝나는 객실이 현재 예약 시작 시간보다 빠른 경우 다시 사용
        if (!bookq.empty() && bookq.top() <= start) bookq.pop();
        
        // 새로운 객실 사용
        bookq.push(end);
    }
    
    return bookq.size();
}
