class Solution {
public:
    
    bool canSortWithBlockSize(vector<int>& nums, int blockSize) {
        int n = nums.size();
        int prevBlockMax = INT_MIN;

        for (int blockStart = 0; blockStart < n; blockStart += blockSize) {
            int blockEnd = blockStart + blockSize - 1;
            int dropCount = 0;
            int dropIndex = -1;

            for (int i = blockStart + 1; i <= blockEnd; i++) {
                if (nums[i] < nums[i - 1]) {
                    dropCount++;
                    dropIndex = i;
                }
            }

            if (dropCount > 1) return false;            

            int blockMin, blockMax;
            if (dropCount == 0) {                        
                blockMin = nums[blockStart];
                blockMax = nums[blockEnd];
            } else {                                      
                if (nums[blockEnd] > nums[blockStart]) return false;
                blockMin = nums[dropIndex];              
                blockMax = nums[dropIndex - 1];          
            }

            if (blockMin < prevBlockMax) return false; 
            prevBlockMax = blockMax;
        }
        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int totalValidSizes = 0;

        for (int blockSize = 1; blockSize <= n; blockSize++) {
            if (n % blockSize == 0 && canSortWithBlockSize(nums, blockSize)) {
                totalValidSizes += blockSize;
            }
        }
        return totalValidSizes;
    }
};