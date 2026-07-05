class Solution {
public:
    bool found(string &haystack, string &needle, int index) {
        int i = 0;
        while(index < haystack.length() && i < needle.length() && haystack[index] == needle[i]) {
            index++;
            i++;
        }
        if(i == needle.length()) return true;
        else return false;
    }
    int strStr(string haystack, string needle) {
        for(int i = 0; i < haystack.length(); i++) {
            if(haystack[i] == needle[0]) {
                if(found(haystack, needle, i))
                    return i;
            }
        }
        return -1;
    }
};