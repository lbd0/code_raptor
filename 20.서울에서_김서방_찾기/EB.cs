using System;

public class Solution
{
    public string solution(string[] seoul)
    {
        string result = "";
        for (int i = 0; i < seoul.Length; i++)
        {
            if (seoul[i] == "Kim")
            {
                result = $"김서방은 {i}에 있다";
            }
        }
        return result;
    }
}
