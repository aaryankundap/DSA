class Solution {
public:
    bool isPalindrome(string s) {
        return check(s,0,s.size()-1);
    }
    bool check(string s,int left, int right){
        if(left>=right) return true;
        if(tolower(s[left])!=tolower(s[right])) return false;
        return check(s,left+1,right+-1);
    }
};
