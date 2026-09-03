class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        int smallest_odd = INT_MAX;
        int smallest_even = INT_MAX;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2) {
                smallest_odd = min(smallest_odd, nums1[i]);
            }
            else {
                smallest_even = min(smallest_even, nums1[i]);
            }
        }

        // if (nums1[0] % 2) {
        //     for (int i = 1; i < n; i++) {
        //         if (nums1[i] % 2) {
        //             continue;
        //         }
        //         else {
        //             if ((nums1[i] - smallest_odd) < 1) {
        //                 return false;
        //             }
        //             else{
        //                 continue;
        //             }
        //         }
        //     }
        // }
        // else {
        //     for (int i = 1; i < n; i++) {
        //         if (nums1[i] % 2 == 0) {
        //             continue;
        //         }
        //         else {
        //             if ((nums1[i] - smallest_odd) < 1) {
        //                 return false;
        //             }
        //             else{
        //                 continue;
        //             }
        //         }
        //     }
        // }

        // pahle sabko odd bnaate hai
        // even element ko odd banane ke liye ODD j chahiye (different parity => diff odd)

        bool odd_possible = true;
        bool even_possible = true;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0 && (nums1[i] - smallest_odd) < 1) {
                odd_possible = false;
            }
        }

        // sabko even bnaana hai
        // odd element ko even banane ke liye bhi ODD j chahiye (same parity => diff even)
        // isliye yahan smallest_odd use hoga, NOT smallest_even

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 != 0 && (nums1[i] - smallest_odd) < 1) {
                even_possible = false;
            }
        }

        return odd_possible || even_possible;
    }
};