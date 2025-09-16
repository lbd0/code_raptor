#include <string>
#include <vector>
#include <cstdio>
using namespace std;

//mm:ss 초 단위로 변환
int toSeconds(const string& time) {
    int m = stoi(time.substr(0, 2)); //stoi(): string을 int로 변환
    int s = stoi(time.substr(3, 2));
    return m * 60 + s;
}

//다시 mm:ss 형식으로 변환
string toTime(int seconds) {
    int m = seconds / 60;
    int s = seconds % 60;

    string mm = (m < 10 ? "0" : "") + to_string(m);
    string ss = (s < 10 ? "0" : "") + to_string(s);
    return mm + ":" + ss;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int video = toSeconds(video_len); //동영상 길이 초 단위
    int current   = toSeconds(pos); //현재 재생 위치 초 단위
    int op_s  = toSeconds(op_start); //오프닝 시작 시간 초 단위
    int op_e  = toSeconds(op_end); //오프닝 끝 시간 초 단위

    if (current >= op_s && current <= op_e) {
        current = op_e; // 시작 위치가 오프닝이면 바로 오프닝 끝으로 이동
    }

    for (string a : commands) {
        if (a == "next")
            current += 10;
        else
            current -= 10;
        
        if (current < 0)
            current = 0;
        
        if (current > video)
            current = video;
        
        if (current >= op_s && current <= op_e)
            current = op_e;
    }
    return toTime(current);
}
