#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(int i = 0; i < babbling.size(); i++) {
        bool count = true; // 말할 수 있을 경우 true 처리
        for(int j = 0; j < babbling[i].size(); j++) {
            if(babbling[i].substr(j,3)=="aya") //j부터 3글자 == aya
                j += 2; //글자수에 맞게 j증가, 그 다음 글자부터 다시 탐색 
            else if(babbling[i].substr(j,2) == "ye")
                j += 1;
            else if(babbling[i].substr(j,3) == "woo")
                j += 2;
            else if(babbling[i].substr(j,2) == "ma")
                j += 1;
            else {
                count = false; //말할 수 없는 경우
                break;
            }
        }
        if(count) //count가 true일 때마다 답 증가
            answer++;
    }
    return answer;
}
