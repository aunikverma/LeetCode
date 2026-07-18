class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        if not nums:
            return 0
        nums = sorted(set(nums))
        longest_consecutive_count = 0
        prev = nums.pop(0)
        consecutive_count = 1
    
        for num in nums:
            if num-prev == 1:
                consecutive_count += 1
            else:
                longest_consecutive_count = max([longest_consecutive_count, consecutive_count])
                consecutive_count = 1
            prev = num

        longest_consecutive_count = max([longest_consecutive_count, consecutive_count])
        
        return longest_consecutive_count

        