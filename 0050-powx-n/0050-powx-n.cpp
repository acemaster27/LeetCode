class Solution {
public:
    double myPow(double x, int n) {
        long temp = n;
        if(!n || x == 1) return 1;
        if(!x) return 0;
        bool isNeg = false;
        double res = 1;
        if(n < 0) isNeg = true;
        temp = abs(temp);
        while(temp != 0) {
            if(temp % 2 != 0) {
                res *= x;
                temp--;
            }
            if(temp % 2 == 0) {
                x = x * x;
                temp /= 2;
            }
        }
        if(isNeg) return 1 / res;
        else return res;
        
    }
};