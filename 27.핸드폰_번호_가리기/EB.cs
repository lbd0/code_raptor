public class Solution {
    public string solution(string phone_number) {
        char[] arr = phone_number.ToCharArray();
        
        for (int i = 0; i < phone_number.Length - 4; i++) {
            arr[i] = '*';
        }
        
        return new string(arr);
    }
}
