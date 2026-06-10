class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        if numerator == 0:
            return "0"

        result = []

        # sign handle
        if (numerator < 0) ^ (denominator < 0):
            result.append("-")

        n, d = abs(numerator), abs(denominator)

        # integer part
        result.append(str(n // d))
        rem = n % d

        if rem == 0:
            return "".join(result)

        result.append(".")

        mp = {}  # remainder -> index in result

        while rem != 0:
            if rem in mp:
                idx = mp[rem]
                result.insert(idx, "(")
                result.append(")")
                break

            mp[rem] = len(result)
            rem *= 10
            result.append(str(rem // d))
            rem %= d

        return "".join(result)