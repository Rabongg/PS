import math

def solution(brown, yellow):
    a, b, c = 1, (brown + 4) / 2, brown + yellow
    answer = [((b + math.sqrt(b * b - 4 * a * c))/(2*a)), ((b - math.sqrt(b * b - 4 * a * c))/(2*a))]
    return answer