def changeNickname(answer, people, uid, new_nickname):
    for i in range(1, len(people[uid])):
        answer[people[uid][i]] = f"{new_nickname}님이 {answer[people[uid][i]].split(' ')[1]}"


def solution(record):
    answer = []
    people = {}
    for i in record:
        temp = i.split(" ")
        if temp[0] in ["Enter", "Change"]:
            people[temp[1]]=temp[2]
    
    for i in record:
        temp = i.split(" ")
        if temp[0] == "Enter":
            answer.append(f"{people[temp[1]]}님이 들어왔습니다.")
        elif temp[0] == "Leave":
            answer.append(f"{people[temp[1]]}님이 나갔습니다.")
    
    return answer