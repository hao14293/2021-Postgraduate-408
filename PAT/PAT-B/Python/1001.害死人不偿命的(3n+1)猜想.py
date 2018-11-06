a = int(raw_input())
count=0
while(a != 1):
    count += 1
    if(a % 2 != 0):
      a = 3 * a + 1
    a /= 2
print count
