// unique: 중복제거 함수. 나머지 부분은 기존 값으로 채워짐
// erase: 원소 삭제 함수. 인덱스도 줄일 수 있음 

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) {
    arr.erase(unique(arr.begin(), arr.end()), arr.end()); // 중복 제거 후 나머지 부분 삭제
    
    return arr;
}
