class Solution {
public:
    int addDigits(int num) {
        int temp;
        while(num > 9) {
            temp = 0;
            while(num != 0) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
        }
        return num;
    }
    // digital root
    // if(n == 0) return 0;
    // return (n - 1) % 9 + 1;
};