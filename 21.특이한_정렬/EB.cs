using System;
using System.Linq;

public class Solution {
    public int[] solution(int[] numlist, int n) {
        return numlist
            .OrderBy(x => Math.Abs(x - n))   // 거리 오름차순
            .ThenByDescending(x => x)        // 거리 같으면 값 내림차순
            .ToArray();
    }
}
