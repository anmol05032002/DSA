class Solution {
public:
    int sumCounts(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        int ans = 0;

        for(int i =0; i<n; i++){
            for(int j = i; j<n; j++){
                st.insert(nums[j]);
                ans+=st.size()*st.size();
            }
            st.clear();
        }
        return ans;
    }
};