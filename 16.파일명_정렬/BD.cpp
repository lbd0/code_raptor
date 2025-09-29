#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> split(string str)
{
    vector<string> res;
    string temp = "";
    
    // HEAD 저장.
    for(int i=0; i<str.length(); ++i)
    {
        if(str[i] < '0' || str[i] > '9')
        {
            temp += str[i];
        }
        else
        {
            res.push_back(temp);
            str.erase(0, i);
            temp = "";
            break;
        }
    }
    
    // NUMBER 저장.
    for(int i=0; i<str.length(); ++i)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            temp += str[i];
        }
        else
        {
            res.push_back(temp);
            str.erase(0, i);
            break;
        }
    }
    
    // TAIL 저장.
    res.push_back(str);
    
    return res;
}

bool cmp(string a, string b)
{
    vector<string> split_a = split(a);
    vector<string> split_b = split(b);
    
    // 대소문자 구문 X 이므로 모두 소문자로 변경해서 비교함.
    transform(split_a[0].begin(), split_a[0].end(), split_a[0].begin(), ::tolower);
    transform(split_b[0].begin(), split_b[0].end(), split_b[0].begin(), ::tolower);
    
    // HEAD 같으면 NUMBER비교.
    if(split_a[0] == split_b[0])
    {
        return stoi(split_a[1]) < stoi(split_b[1]);
    }
    
    // HEAD 기준 정렬
    return split_a[0] < split_b[0];
}

vector<string> solution(vector<string> files) {
    
    // HEAD, NUMBER 동일 할 때는 입력 순서대로 정렬 => stable_sort.
    stable_sort(files.begin(), files.end(), cmp);

    return files;
}
