class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        ans = set(nums)
        result = k
        while result in ans:
            result += k
        return result


        