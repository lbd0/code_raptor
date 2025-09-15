//풀이 보면서 풀었습니다
#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, int w, int num)
{
	int answer = 0, idx = 0, pos = 0; //idx: 현재 상자의 열 위치, pos: 꺼낼 상자가 들어 있는 열 위치
	vector<stack<int>> v(w);
	bool flag = true;  // 층 쌓는 방향

	for (int i = 1; i <= n; i++)
	{
		if (i == num)
			pos = idx; // 쌓는 상자가 num이면 pos에 열 번호 저장
		if (flag)
			v[idx++].push(i);
		else
			v[idx--].push(i);
		if (i % w == 0) // 방향 전환
		{
			flag = !flag;
			if (!flag)
				idx--;
			else
				idx++;
		}
	}
	while (!v[pos].empty()) //상자 꺼내기
	{
		int n = v[pos].top();
    v[pos].pop();
		answer++;
		if (n == num) //종료
			break;
	}
	return answer;
}
