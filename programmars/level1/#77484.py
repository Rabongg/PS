def solution(lottos, win_nums):
    # 맞춘 갯수별 rank
    rank = [6, 6, 5, 4, 3, 2, 1]
    zero_cnt = lottos.count(0)
    match_num = 0
    for num in lottos:
        if num in win_nums:
            match_num+=1
    
    return rank[zero_cnt + match_num], rank[match_num]