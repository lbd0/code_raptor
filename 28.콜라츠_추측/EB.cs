public class Solution {
    public int solution(int num) {
        int cnt = 0;
        long n = num;
        if(n == 1) return 0;
        
        while(n>1){
        if(cnt>= 500)return -1;
          
        //짝수
        if(n%2 == 0){
            n = n/2;
            cnt++;
        }else{//홀수
            n = (n*3)+1;
            cnt++;
        }
            
            
        }
        if(cnt>=500) cnt = -1;
        return cnt;
        
    }
}
