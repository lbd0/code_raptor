using System;
using System.Collections.Generic;
using System.Linq;

public class Solution
{
    public int solution(int k, int[] tangerine)
    {
        // 1. 크기별 개수 세기
        Dictionary<int, int> countMap = new Dictionary<int, int>();

        foreach (int t in tangerine)
        {
            if (countMap.ContainsKey(t))
                countMap[t]++;
            else
                countMap[t] = 1;
        }

        // 2. 개수만 뽑아서 내림차순 정렬
        List<int> counts = countMap.Values
                                   .OrderByDescending(x => x)
                                   .ToList();

        // 3. 많이 있는 크기부터 k개 채우기
        int sum = 0;
        int kinds = 0;

        foreach (int c in counts)
        {
            sum += c;
            kinds++;

            if (sum >= k)
                break;
        }

        return kinds;
    }
}
