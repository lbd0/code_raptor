#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
    vector<vector<int>> answer;
    int num;
    int sb;
    
    if(ext == "code") num = 0; //ext 값 int로 변환
    else if(ext == "date") num = 1;
    else if(ext == "maximum") num = 2;
    else num = 3;
    
    if(sort_by == "code") sb = 0; //sort_by 값 int로 변환
    else if(sort_by == "date") sb = 1;
    else if(sort_by == "maximum") sb = 2;
    else sb = 3;
    
    for(int i = 0; i < data.size(); i++){
        if(data[i][num] < val_ext){
            answer.push_back(data[i]); // val_ext와 비교
        }
    }
    sort(answer.begin(), answer.end(), [sb](const vector<int>& a, const vector<int>& b) {
    return a[sb] < b[sb]; // sort_by 기준으로 오름차순 정렬
    });
    
    return answer;
}
