class Solution {
public:
    int reverse(int n) {
        int revNumb = 0;

        while(n != 0){
            int dig = n % 10;
            if(revNumb > INT_MAX/10 ||revNumb < INT_MIN/10) return 0;
            revNumb = (revNumb*10) + dig;
            n /= 10;
        }
        return revNumb;
    }
};