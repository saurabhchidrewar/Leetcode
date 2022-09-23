class Solution:
    def isPalindrome(self, s: str) -> bool:
        a = [i.upper() for i in s if i.isalnum()]
        return a == a[::-1]