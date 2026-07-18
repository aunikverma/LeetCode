class Solution:
    def addBinary(self, a: str, b: str) -> str:
        x = int(
            a, 2
        )  # to convert into decimal(first should be string and second should be base)
        y = int(b, 2)
        res = x + y
        x1 = str(bin(res))  # binary to string
        return x1[2:]  # since 0b represents binary in python so start from 2 to end
