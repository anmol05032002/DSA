class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        if(n == 0 || lower > nums[n-1]){
            return {{lower, upper}};
        }

        int j = 0;
        int i = 0;
        vector<int> v;

        while(j < n && lower <= upper){
            if((lower + i) < nums[j]){
                if((lower + i) > upper){
                    if(!v.empty()){
                        ans.push_back(v);
                        v.clear();
                    }
                    lower = upper + 1;
                    break;
                }
                v.push_back(lower + i);
                i++;
            }
            else{
                if(!v.empty()){
                    ans.push_back(v);
                    v.clear();
                }
                lower = max(lower, nums[j] + 1); 
                j++;
                i = 0;
            }
        }

        while(lower <= upper){
            v.push_back(lower);
            lower++;
        }
        if(!v.empty()){
            ans.push_back(v);
        }

        vector<vector<int>> res;
        int size = ans.size();

        for(int i = 0; i < size; i++){
            vector<int> v;
            int c = ans[i].size();
            int a = ans[i][0];
            int b = ans[i][c-1];
            v.push_back(a);
            v.push_back(b);
            res.push_back(v);
        }
        return res;
    }
};