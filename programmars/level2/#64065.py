from collections import Counter
import re


def solution(s):
    numbers = re.findall(r'\d+', s)
    count = Counter(numbers)

    return [int(num) for num, _ in count.most_common()]