//C##없음 이슈 gpt 도움

public class Solution
{
    public int solution(int[] bandage, int health, int[,] attacks)
    {
        int t = bandage[0];  // 시전 시간
        int x = bandage[1];  // 초당 회복량
        int y = bandage[2];  // 추가 회복량

        int maxHealth = health;
        int currentHealth = health;

        int attackCount = attacks.GetLength(0);
        int attackIndex = 0;

        // 마지막 공격 시간이 끝날 때까지만 시뮬레이션
        int lastTime = attacks[attackCount - 1, 0];

        int successTime = 0; // 연속으로 붕대 감기 성공한 시간(초)

        for (int time = 1; time <= lastTime; time++)
        {
            // 이번 초에 공격이 있는지 확인
            if (attackIndex < attackCount && attacks[attackIndex, 0] == time)
            {
                // 공격 받는 순간에는 회복 없음, 스킬 취소
                int damage = attacks[attackIndex, 1];
                currentHealth -= damage;

                if (currentHealth <= 0)
                {
                    return -1; // 캐릭터 사망
                }

                // 기술 취소 → 바로 다시 사용하지만 연속 시간은 0부터
                successTime = 0;
                attackIndex++;
            }
            else
            {
                // 공격이 없는 초 → 붕대 감기 회복
                successTime++;
                currentHealth += x;

                // t초 연속 성공하면 추가 회복
                if (successTime == t)
                {
                    currentHealth += y;
                    successTime = 0; // 추가 회복 후 연속 시간 초기화 (다시 1초부터 카운트)
                }

                // 최대 체력 넘지 않게
                if (currentHealth > maxHealth)
                {
                    currentHealth = maxHealth;
                }
            }
        }

        return currentHealth;
    }
}
