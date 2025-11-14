using System;

public class Solution {
    public int solution(int[] citations) {
        Array.Sort(citations);
        Array.Reverse(citations);

        int h = 0;
        for (int i = 0; i < citations.Length; i++) {
            if (citations[i] >= i + 1)
                h = i + 1;
            else
                break;
        }

        return h;
    }
}
