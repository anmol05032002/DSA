class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        long long n = nums1.size();
        vector<long long> diff(1e5+1,0);

        for(long long i = 0; i<n; i++){
            diff[abs(nums1[i]-nums2[i])]++;
        }

        long long K = (long long)k1 + k2;

        for(long long i = 1e5; i>0 && K>0; i--){
             long long currOps = min(diff[i], K);
              diff[i]-= currOps;
              diff[i-1]+= currOps;
              K-=currOps;
        }

        long long ans = 0;

        for(int i = 1; i<=1e5; i++){
            ans+= (diff[i]*i*i);
        }
        return ans;

    }
};