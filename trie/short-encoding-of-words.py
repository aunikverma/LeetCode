class Solution:
    def minimumLengthEncoding(self, words: List[str]) -> int:
        good = set(words)
        # remove all suffixes (except the word itself)
        print(good)
        for w in words:
            for k in range(1, len(w)):
                good.discard(w[k:])
        # sum lengths + 1 for '#'
        return sum(len(w) + 1 for w in good)
