class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        int n= a.size();

        vector<int>v(n,0);
        int neg=1,pos=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]>0)
            {
                v[pos]=a[i];
                pos+=2;
            }
            else if(a[i]<0)
            {
                v[neg]=a[i];
                neg+=2;
            }
        }
        return v;
        
    }
};