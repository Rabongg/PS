from itertools import combinations
from bisect import bisect_left
from collections import defaultdict

def solution(info, query):
    answer = []
    datas = defaultdict(list)
    for i in range(len(info)):
        record = info[i].split()
        score = int(record[4])
        new_record = record[:-1]
        
        for i in range(5):
            for c in combinations(new_record, i):
                key = ''.join(c)
                datas[key].append(score)
    
    for key in datas.keys():
        datas[key].sort()
    
    
    for q in query:
        cond = q.split()
        search = ""
        for index in range(0, len(cond)-1, 2):
            if cond[index] != '-':
                search += cond[index]
        score = int(cond[7])
        if search in datas:
            data = datas[search]
            answer.append(len(data) - bisect_left(data, score))
        else:
            answer.append(0)
        
    
    return answer