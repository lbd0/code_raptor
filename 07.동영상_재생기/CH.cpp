#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 초 형태로 바꿔줌
int toSeconds(const string &s)
{
    return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}

// 분 : 초 형태로 바꿔줌
string toMinutes(const int &i)
{
    return ((i < 600) ? "0" : "") + to_string(i / 60) + ":" + ((i % 60 < 10) ? "0" : "") + to_string(i % 60);
}

// 영상 길이, 오프닝 구간을 참고하여 초의 범위를 조정
void CheckSeconds(const int &vs, int &ps, const int &ss, const int &es)
{
    ps = clamp(ps, 0, vs);
    if (ss <= ps && ps <= es) ps = es;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    int vs = toSeconds(video_len);
    int ps = toSeconds(pos);
    int ss = toSeconds(op_start);
    int es = toSeconds(op_end);
    
    for (const string &c : commands)
    {
        CheckSeconds(vs, ps, ss, es);
        ps += (c == "prev") ? -10 : 10;
    }
    
    CheckSeconds(vs, ps, ss, es);
    return toMinutes(ps);
}
