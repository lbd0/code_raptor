#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// : 기준으로 문자열 나누는 함수.
vector<int> split(string str)
{
    vector<int> res;
    auto pos = 0;
    
    if(pos = str.find(":") != string::npos)
    {
        string temp = str.substr(0, pos+1);
        res.push_back(stoi(temp));
        str.erase(0,pos+2);
    }
    res.push_back(stoi(str));
    
    return res;
}

// 1자리수면 0 채워서 2자리수로 만드는 함수.
void makeDouble(string& str)
{
    if(str.size() < 2)
    {
        str += '0';
        sort(str.begin(), str.end());
    }
}

// 오프닝 건너뛰기 구간인지 검사하는 함수.
bool checkOpening(int pos_min, int pos_sec, int ops_min, int ops_sec, int ope_min, int ope_sec)
{
    if(pos_min > ops_min && pos_min < ope_min)
    {
        return true;
    }
    else if(pos_min == ops_min && pos_min < ope_min)
    {    
        if(pos_sec >= ops_sec)
        {
            return true;
        }
    }
    else if(pos_min > ops_min && pos_min == ope_min)
    {
        if(pos_sec <= ope_sec) return true;
    }
    else if(pos_min == ops_min && pos_min == ope_min)
    {
        if(pos_sec >= ops_sec && pos_sec <= ope_sec) return true;
    }
    
    return false;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    string answer = "";
    
    // 시간을 모두 : 기준으로 분, 초로 나눠서 정수형으로 저장.
    int vid_min = split(video_len)[0];
    int vid_sec = split(video_len)[1];
    
    int ops_min = split(op_start)[0];
    int ops_sec = split(op_start)[1];
    
    int ope_min = split(op_end)[0];
    int ope_sec = split(op_end)[1];
    
    int pos_min = split(pos)[0];
    int pos_sec = split(pos)[1];
    
    
    for(const auto& com:commands)
    {   
        // 오프닝 건너뛰기 검사 및 적용.
        if(checkOpening(pos_min, pos_sec, ops_min, ops_sec, ope_min, ope_sec))
        {
            pos_min = ope_min;
            pos_sec = ope_sec;
        }
        
        // 10초 전으로 이동.
        if(com.compare("prev") == 0)
        {
            pos_sec -= 10;
            
            if(pos_sec < 0)
            {
                pos_min -= 1;
                pos_sec = 60 + pos_sec;
            }
            // 00:00보다 전이면 00:00으로.
            if(pos_min < 0)
            {
                pos_min = 0;
                pos_sec = 0;
            }
            
            // 오프닝 건너뛰기
            if(checkOpening(pos_min, pos_sec, ops_min, ops_sec, ope_min, ope_sec))
            {
                pos_min = ope_min;
                pos_sec = ope_sec;
            }
        }
        else
        {
            // 10초 후로 이동.
            pos_sec += 10;
            
            if(pos_sec >= 60)
            {
                pos_min += 1;
                pos_sec -= 60;
            }
            
            // 동영상 길이보다 길면, 동영상 끝으로.
            if(pos_min >= vid_min && pos_sec >= vid_sec)
            {
                pos_min = vid_min;
                pos_sec = vid_sec;
            }
            
            // 오프닝 건너뛰기.
            if(checkOpening(pos_min, pos_sec, ops_min, ops_sec, ope_min, ope_sec))
            {
                pos_min = ope_min;
                pos_sec = ope_sec;
            }
        }
    }   
    
    // 한 자리수 -> 두 자리수로 변경.
    string min = to_string(pos_min);
    string sec = to_string(pos_sec);
    makeDouble(min);
    makeDouble(sec);
    
    answer += min + ":" + sec;
    
    return answer;
}
