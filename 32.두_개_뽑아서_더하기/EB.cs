using System;
using System.Collections.Generic;

public class Solution
{
    public int[] solution(int[] numbers)
    {
        //중복을 자동으로 제거
        HashSet<int> set = new HashSet<int>();

        for (int i = 0; i < numbers.Length - 1; i++)
        {
            for (int j = i + 1; j < numbers.Length; j++)
            {
                set.Add(numbers[i] + numbers[j]);
            }
        }

        int[] answer = new int[set.Count];
        set.CopyTo(answer);
        Array.Sort(answer);
        return answer;
    }
}
