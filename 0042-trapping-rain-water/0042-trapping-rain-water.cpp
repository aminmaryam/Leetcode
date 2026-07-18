class Solution {
public:
/*
=> solve this using 2 pointer approach, to trace the boundries of the pillars
=> left = 0, right = n-1
=> we increment left and decrement right until left > right

*/
    int trap(vector<int>& ht) {
        int n=ht.size();
        int ans = 0;
        int l = 0, r=n-1;
        int rmax = 0, lmax = 0;

        while(l < r){
            lmax = max(lmax, ht[l]);
            rmax = max(rmax, ht[r]);

            if(lmax < rmax){
                ans += lmax - ht[l];
                l++;
            }
            else{
                ans += rmax - ht[r];
                r--;
            }
        }
        return ans;
    }
};