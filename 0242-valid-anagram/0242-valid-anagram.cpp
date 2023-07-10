class Solution {
public:
    bool isAnagram(string s, string t) {
        // sort(s.begin(),s.end());
        // sort(t.begin(), t.end());
        // return s==t;

        //or
        
        int n1=s.length();
        int n2=t.length();
        if(n1!=n2) return false;
        map <char, int> smap;
        for(int i=0;i<n1;i++){
            smap[s[i]]++;
        }
        for(int i=0;i<n2;i++){
            smap[t[i]]--;
        }
        for(auto it: smap){
            if(it.second!=0){
                return false;
            }
        }
        return true;

    }
};