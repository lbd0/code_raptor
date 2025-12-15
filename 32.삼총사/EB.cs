using System;

public class Solution
{
    public int solution(int[] number)
    {
        int count = 0;
        int n = number.Length;

        // 서로 다른 3명 뽑기: i < j < k
        for (int i = 0; i < n - 2; i++)
        {
            for (int j = i + 1; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (number[i] + number[j] + number[k] == 0)
                        count++;
                }
            }
        }

        return count;
    }
}
