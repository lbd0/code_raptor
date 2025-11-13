using System;

public class Solution {
    public string solution(string[] cards1, string[] cards2, string[] goal) {
        int cnt_1 = 0; // cards1에서 다음에 쓸 카드 인덱스
        int cnt_2 = 0; // cards2에서 다음에 쓸 카드 인덱스

        for (int i = 0; i < goal.Length; i++)
        {
            string target = goal[i];
            
            // cards1에서 사용 가능한 카드인지 확인
            if (cnt_1 < cards1.Length && cards1[cnt_1] == target)
            {
                cnt_1++;   // cards1에서 한 장 사용
            }
            // 아니면 cards2에서 확인
            else if (cnt_2 < cards2.Length && cards2[cnt_2] == target)
            {
                cnt_2++;   // cards2에서 한 장 사용
            }
            // 둘 다 아니면 규칙 어긴 거 → 바로 실패
            else
            {
                return "No";
            }
        }

        // 끝까지 잘 만들었으면
        return "Yes";
    }
}
