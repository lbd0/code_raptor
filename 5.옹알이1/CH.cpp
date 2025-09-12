#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    vector<string> sounds = {"aya", "ye", "woo", "ma"};
    int answer = 0;

    for (const string &word : babbling) 
    {
        string prev = "";
        bool possible = true;

        for (int i = 0; i < word.size();)
        {
            bool matched = false;

            for (const string &s : sounds) 
            {
                if (word.substr(i, s.size()) == s && s != prev) 
                {
                    matched = true;
                    prev = s;
                    i += s.size();
                    break;
                }
            }
            
            if (!matched) 
            {
                possible = false;
                break;
            }
        }

        if (possible) ++answer;
    }
    
    return answer;
}
