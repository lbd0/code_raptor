using System;

public class Solution {
    public int solution(int n, int m, int[] section) {
        int answer = 0;
        int paintedEnd = 0; // 지금까지 롤러로 덮은 마지막 구역 번호

        foreach (int pos in section)
        {
            // 아직 칠하지 않은 구역을 만났다면
            if (pos > paintedEnd)
            {
                answer++;                 // 롤러 한 번 더 칠하고
                paintedEnd = pos + m - 1; // 이번 롤러로 덮을 수 있는 마지막 구역
            }
            // pos <= paintedEnd 이면 이미 이전 롤러로 칠해진 구역이니까 패스
        }

        return answer;
    }
}
