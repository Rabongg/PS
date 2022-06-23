def solve():
  lectures = [0] * 1000001
  answer = 0
  num = int(input())
  for l in list(map(int, input().split())):
    lectures[l] +=1
  for l in list(map(int, input().split())):
    if lectures[l] >= 1:
      lectures[l] -=1
  for i in lectures:
    answer += i
  print(answer)
if __name__ == '__main__':
  solve()