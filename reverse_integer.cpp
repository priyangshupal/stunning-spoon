class Solution {
public:
    int reverse(int x) {
        int num, rev=0;
        
        if(x>INT_MAX) return 0;
        
        while(x != 0) {
            num = x % 10;
            x /= 10;
            if(rev < INT_MIN/10 || rev > INT_MAX/10) {
                return 0;
            }
            rev = rev*10 + num;
        }
        
        return rev;
    }
};
