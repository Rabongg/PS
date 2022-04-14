import math

def calculate(time_in, time_out):
    hour_diff = (int(time_out.split(":")[0]) - int(time_in.split(":")[0])) * 60
    min_diff = int(time_out.split(":")[1]) - int(time_in.split(":")[1])
    return hour_diff + min_diff    


def solution(fees, records):
    answer = []
    car_time = {}
    tmp_time = {}
    for record in records:
        if record.split()[2] == 'IN':
            tmp_time[record.split()[1]] = record.split()[0]
        else:
            if record.split()[1] in car_time:
                car_time[record.split()[1]] += calculate(tmp_time[record.split()[1]], record.split()[0])
            else:
                car_time[record.split()[1]] = calculate(tmp_time[record.split()[1]], record.split()[0])
            del tmp_time[record.split()[1]]

    
    for car in tmp_time:
        if car in car_time:
            car_time[car] += calculate(tmp_time[car], "23:59")
        else:
            car_time[car] = calculate(tmp_time[car], "23:59")
            
    car_time = sorted(car_time.items())
    for car in car_time:
        if car[1] > fees[0]:
            cost = fees[1] + math.ceil((car[1] - fees[0]) / fees[2] ) * fees[3]
        else:
            cost = fees[1]
        answer.append(cost)
    
    return answer