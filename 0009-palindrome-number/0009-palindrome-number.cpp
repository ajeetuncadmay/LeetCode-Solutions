class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0){
            return false;
        }
        long long originalNum = x;
        long long reversedNum = 0;

        while(x>0){
            int lastDigit = x % 10;
            reversedNum  = (reversedNum * 10) + lastDigit;
            x=x/10;
        }
        if(originalNum == reversedNum) {
            return true;
        } else{
            return false;
        }
        
    }
};