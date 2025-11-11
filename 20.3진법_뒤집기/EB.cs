using System;

public class EB
{
    public int solution(int n)
    {
        string base3 = ToBase3(n);        // 10 → 3
        string reversed = ReverseString(base3); // 뒤집기
        return FromBase3(reversed);       // 3 → 10
    }

    // 10진수 → 3진수 문자열
    private string ToBase3(int n)
    {
        if (n == 0) return "0";

        string result = "";
        while (n > 0)
        {
            int remain = n % 3;
            result = remain + result; // 앞에 붙이기
            n /= 3;
        }
        return result;
    }

    // 3진수 문자열 → 10진수
    private int FromBase3(string s)
    {
        int result = 0;
        foreach (char c in s)
        {
            int digit = c - '0'; // '0','1','2'만 온다고 가정
            result = result * 3 + digit;
        }
        return result;
    }

    // 문자열 뒤집기
    private string ReverseString(string s)
    {
        char[] arr = s.ToCharArray();
        Array.Reverse(arr);
        return new string(arr);
    }
}
