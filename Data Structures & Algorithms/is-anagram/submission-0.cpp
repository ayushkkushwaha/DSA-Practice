class Solution {
public:
    bool isAnagram(string s, string t) {
        //sort the strings
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());

        int sLen = s.size();
        int tLen = t.size();

        if(sLen!=tLen)
        return false;

        for(int i=0;i<sLen;i++){
            if(s[i]!=t[i])
                return false;
        }

        return true;

    }
};
