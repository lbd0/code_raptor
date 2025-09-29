#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// code, date, maximum, remain 인덱스.
int idx = 0;

// 인덱스 찾는 함수.
int findIdx(string ext)
{
    if(ext.compare("date") == 0)
        return 1;
    else if(ext.compare("maximum") == 0)
        return 2;
    else if(ext.compare("remain") == 0)
        return 3;
    else return 0;
}

// idx 기준으로 정렬하는 함수.
bool cmp(vector<int> a, vector<int> b)
{
    return a[idx] < b[idx];
}

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    
    // 인덱스 찾아서 저장.
    idx = findIdx(ext);
    
    // 인덱스 비교해서 val_ext보다 작으면 answer에 저장.
    for(const auto& d:data)
    {
        if(d[idx] < val_ext)
            answer.push_back(d);
    }
    
    // 정렬할 기준 인덱스 찾아서 저장.
    idx = findIdx(sort_by);
    // 인덱스 기준 정렬.
    sort(answer.begin(), answer.end(), cmp);
    
    return answer;
}
