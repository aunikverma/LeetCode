class Solution:
    def replaceWords(self, dictionary: List[str], sentence: str) -> str:
        dictionary.sort(key=len)  # ensure shortest roots first
        words = sentence.split(" ")
        used = [False] * len(words)

        for root in dictionary:
            for j in range(len(words)):
                if words[j].startswith(root) and not used[j]:
                    words[j] = root
                    used[j] = True
        return " ".join(words)
