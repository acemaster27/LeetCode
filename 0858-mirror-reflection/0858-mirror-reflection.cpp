class Solution {
public:
    int mirrorReflection(int p, int q) {
        int l = lcm(p, q);
        int a = l / p;
        int b = l / q;
        if(a % 2 == 0 && b % 2 != 0) return 0;
        if(a % 2 != 0 && b % 2 != 0) return 1;
        if(a % 2 != 0 && b % 2 == 0) return 2;
        return -1;
    }
};