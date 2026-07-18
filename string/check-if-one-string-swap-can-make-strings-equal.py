class Solution:
    def areAlmostEqual(self, s1: str, s2: str) -> bool:
        # If already equal, return True
        if s1 == s2:
            return True
        
        # Find indices where characters differ
        diff = [(a, b) for a, b in zip(s1, s2) if a != b]
        print(diff)

        # There should be exactly **two** differing characters that can be swapped
        return len(diff) == 2 and diff[0] == diff[1][::-1]
