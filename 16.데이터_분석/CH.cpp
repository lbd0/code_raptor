#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ext, sort_by에 따라 index 위치를 반환하는 함수
int trans(const string& s)
{
    if      (s == "code")       return 0;
    else if (s == "date")       return 1;
    else if (s == "maximum")    return 2;
    else                        return 3;
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    // ext, sort_by에 따라 index 위치를 저장할 변수
    int ex = trans(ext);
    int sb = trans(sort_by);
    
    // val_ext보다 작은 데이터만 vector에 저장
    for (const vector<int>& d : data)
        if (d[ex] < val_ext) answer.push_back(d);
    
    // sort_by를 기준으로 오름차순 정렬
    sort(answer.begin(), answer.end(), [sb](const vector<int>& a, const vector<int>& b) {
        return a[sb] < b[sb]; 
    });
    
    return answer;
}
