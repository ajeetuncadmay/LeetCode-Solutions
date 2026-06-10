class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        result = []

        while columnNumber > 0:
            columnNumber -= 1  # important step (0-based adjust)
            result.append(chr(columnNumber % 26 + ord('A')))
            columnNumber //= 26

        return "".join(result[::-1])