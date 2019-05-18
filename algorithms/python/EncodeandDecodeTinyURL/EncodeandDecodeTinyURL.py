# Source : https://leetcode.com/problems/encode-and-decode-tinyurl/
# Author : Mading
# Date   : 2019-05-17

# ********************************************************************************* 
#  535. Encode and Decode TinyURL [Medium]
#  Note: This is a companion problem to the System Design problem: Design TinyURL.
# TinyURL is a URL shortening service where you enter a URL such as 
# https://leetcode.com/problems/design-tinyurl and it returns a short URL such as http://tinyurl.com/4e9iAk.

# Design the encode and decode methods for the TinyURL service. There is no restriction on 
# how your encode/decode algorithm should work. You just need to ensure that a URL can be 
# encoded to a tiny URL and the tiny URL can be decoded to the original URL.
#           
# **********************************************************************************

# 20 ms, faster than 98.24% of Python, 11.7 MB, less than 75.00% of Python
class Codec:

    def __init__(self):
        self.urls = []

    def encode(self, longUrl):
        self.urls.append(longUrl)
        return 'http://tinyurl.com/' + str(len(self.urls) - 1)

    def decode(self, shortUrl):
        return self.urls[int(shortUrl.split('/')[-1])]

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.decode(codec.encode(url))