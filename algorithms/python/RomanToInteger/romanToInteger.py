
#172 ms 13.9 MB   while C++ cost 48 ms   30.9 MB
class Solution:
    def romanToInt(self, s: str) -> int:
        d = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,
             'IV':4,'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
        n = 0
        l = len(s)
        i = 0
        while(i<l):
            if i<len(s)-1:
                if s[i:i+2] in d.keys():
                    print(s[i:i+2])
                    n += d[s[i:i+2]]
                    i += 2
                    continue
            print(s[i])        
            n += d[s[i]]
            i += 1
        return n
                    
                