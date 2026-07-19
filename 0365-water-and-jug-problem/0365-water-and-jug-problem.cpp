class Solution {
public:
    int extGCD(int a, int b, int& x, int& y) {
        if(b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int gcd = extGCD(b, a % b, x1, y1);
        x = y1;
        y = x1 - y1 * (a / b);
        return gcd;
    }
    bool canMeasureWater(int a, int b, int target) {
        int x, y;
        int g = extGCD(a, b, x, y);

        if(target % g != 0 || target > a + b) return false;
        else return true;
    }
};