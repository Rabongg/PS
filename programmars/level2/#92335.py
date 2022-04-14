import re
import math

def checkPrime(num):
    
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True


def convert(n, k):
    convert_num = ""
    while n > 0:
        rest = n % k
        n = n // k
        convert_num = str(rest) + convert_num
    return convert_num

def solution(n, k):
    num = []
    answer = 0
    
    tmp = re.split('0', convert(n, k))

    for t in tmp:
        if t != "" and t != "1":
            num.append(int(t))

    for i in num:
        answer = answer + 1 if checkPrime(i) else answer 
    
    return answer