class Solution:
    def countDigitOne(self, n: int) -> int:
        if n <= 0:
            return 0

        count = 0  #count initialize to one
        p = 1  # Start at the 1's place

        while p <= n:
            c = (n // p) % 10  # Current digit at the current place
            lower = n % p  # Numbers to the right of the current place
            higher = n // (p * 10)  # Numbers to the left of the current place

            # Count 1's contributed by this place
            if c == 0:
                count += higher * p
            elif c == 1:
                count += higher * p + lower + 1
            else:
                count += (higher + 1) * p

            p *= 10  # Move to the next place value

        return count