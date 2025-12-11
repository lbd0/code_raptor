public class Solution {
    public string solution(string s) 
    {
        string answer = "";
        int idx = 0; // 단어 내 인덱스

        foreach (char c in s)
        {
            if (c == ' ')
            {
                answer += c;
                idx = 0;               // 단어 인덱스 초기화
            }
            else
            {
                if (idx % 2 == 0)
                    answer += char.ToUpper(c);
                else
                    answer += char.ToLower(c);

                idx++;
            }
        }
        return answer;
    }
}
