using System;

public class Solution {
    public int solution(int n) {
        int mod = 1234567;

        int[] fib = new int[n + 1];
        fib[0] = 0;
        fib[1] = 1;

        for (int i = 2; i <= n; i++)
        {
            fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
        }

        return fib[n];
    }
}
