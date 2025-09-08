#include <string>
#include <vector>
#include <map>
#include <iostream>
#define X first
#define Y second

using namespace std;
map<string,int> mp;

pair<string,string> friendnames(string gift){
    int k =0;
    for(int i=0; i<gift.size(); i++){
        if(gift[i]==' '){
            k=i;
            break;
        } //gift에서 공백 기준으로 나누기
    }
    return {gift.substr(0,k),gift.substr(k+1,10)}; //공백 전은 주는 사람, 공백 후는 주는 사람 저장
}

int solution(vector<string> friends, vector<string> gifts) {
    int n = friends.size();
    vector<int> getGifts(n,0); //다음 달 받을 선물 수 저장

    for(int i=0; i<n; i++){
      mp[friends[i]]= i;} //friends를 인덱스로 변환

    vector<vector<int>> arr(n,vector<int>(n,0));
    vector<int> f(n,0);

    for(int i=0; i<gifts.size(); i++){
        pair<string,string> cur = friendnames(gifts[i]);
        f[mp[cur.X]]++; // 선물을 준 사람 +1
        f[mp[cur.Y]]--; // 선물을 받은 사람 -1
        arr[mp[cur.X]][mp[cur.Y]]++;
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j)continue; //자기자신에게 주는 경우 제외
            if(arr[i][j]>arr[j][i]){
              getGifts[i]++;} // i가 j에게 준 선물이 많을 경우 i가 받는 선물 +1
            else if(arr[i][j]==arr[j][i]){ // 주고 받은 선물이 똑같을 경우
                if(f[i]>f[j]){
                  getGifts[i]++;}
            }
        }
    }
    int answer =0;
    for(int i=0; i<n; i++){
        if(getGifts[i] > answer)answer = getGifts[i]; // 가장 많이 선물을 받게 되는 사람의 개수를 찾음
    }
    return answer;
}
