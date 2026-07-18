class Solution:
    def convertDateToBinary(self, date: str) -> str:
        ans = ""
        p = date.split("-")
        for i in p:
            res = bin(int(i))
            ans += res[2:] + "-"
        return ans[0:-1]
