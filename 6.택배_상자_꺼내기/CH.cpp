int solution(int n, int w, int num) {
    // 꺼낼 박수 수를 저장할 answer와 층수 floor
    int answer = 0;
    int floor = (num - 1) / w + 1;

    do
    {
        // 박스 하나 꺼내고 1층 올라가기
        ++answer;
        ++floor;
        
        // 박스의 위치를 구하고, 다음 박스 번호 구하기
        int idx = (num - 1) % w;
        num = w * floor - idx;
    } while (num <= n);
    
    return answer;
}
