class Solution {
public:
    string addBinary(string a, string b) {
        bool carry = false;
        string ans = "";
        int one = a.length() - 1, two = b.length() - 1;
        while(one >= 0 && two >= 0) {
            if(a[one] == b[two]){
                if(carry) {
                    ans = '1' + ans;
                    carry = false;
                }
                else {
                    ans = '0' + ans;
                }
                carry = (a[one] == '1');
            }
            else {
                if(carry) {
                    ans = '0' + ans;
                    carry = true;
                }
                else {
                    ans = '1' + ans;
                }
            }
            one--;
            two--;
        }
        while(one >= 0) {
            if(carry) {
                if(a[one] == '1') ans = '0' + ans;
                else {
                    ans = '1' + ans;
                    carry = false;
                }
            }
            else {
                ans = a[one] + ans;
            }
            one--;
        }
        while(two >= 0) {
            if(carry) {
                if(b[two] == '1') ans = '0' + ans;
                else {
                    ans = '1' + ans;
                    carry = false;
                }
            }
            else {
                ans = b[two] + ans;
            }
            two--;
        }
        if(carry) ans = '1' + ans;
        return ans;
    }
};