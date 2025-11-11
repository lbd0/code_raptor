using System;
using System.Linq;
using System.Collections.Generic;

public class Solution {
    public long solution(int n, int[] works) {

        long total = works.Sum(x => (long)x);
        if (total <= n) return 0; // 전부 처리 가능하면 야근 피로도 0

        // key = 작업량, value = 해당 작업량의 개수
        var map = new SortedDictionary<int, int>();

        foreach (var w in works) {
            if (!map.ContainsKey(w)) map[w] = 0;
            map[w]++;
        }

        while (n-- > 0) {
            // 가장 큰 key 찾기 (Reverse 순회)
            var last = map.Last();
            int maxWork = last.Key;

            // 해당 작업량 -1 줄이기
            map[maxWork]--;
            if (map[maxWork] == 0) map.Remove(maxWork);

            int newWork = maxWork - 1;
            if (newWork > 0) {
                if (!map.ContainsKey(newWork)) map[newWork] = 0;
                map[newWork]++;
            }
        }

        long answer = 0;
        foreach (var pair in map) {
            answer += (long)pair.Key * pair.Key * pair.Value;
        }

        return answer;
    }
}
