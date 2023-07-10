class Solution {
public:
    int lengthOfLastWord(string s) {
        int n=s.length();
        int i=n-1;
        int count=0;
        //ignoring last spaces
        if(n==1 && s[i] !=' ') return 1;
        if(n==1 && s[i] ==' ') return 0;
        while(i>=0 &&s[i]==' '){
            i--;
        }
        while(i>=0 && s[i]!=' '){
            count=count+1;
            i--;
        }
        return count;

        
    }
};