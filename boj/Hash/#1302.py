def solve():
  books = {}
  N = int(input())
  for i in range(N):
    title = input()
    if title in books:
      books[title] +=1
    else:
      books[title] = 1
      
  sorted_books = {k: v for k, v in sorted(books.items())}
  sorted_dict = sorted(sorted_books.items(), key = lambda item: item[1], reverse = True)
  print(sorted_dict[0][0])
if __name__ == '__main__':
  solve()