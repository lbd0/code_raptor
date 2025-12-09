using System;

public class Solution
{
    public string solution(string s)
    {
        char[] arr = s.ToCharArray();
        Array.Sort(arr);
        Array.Reverse(arr);
        return new string(arr);
    }
}
