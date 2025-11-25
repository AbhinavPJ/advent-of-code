ans=0
for _ in range(1000):
    numbers= list(map(int, input().split()))
    dec=True
    inc=True
    bad=False
    for i in range(1, len(numbers)):
        if numbers[i] > numbers[i-1]:
            dec=False
        elif numbers[i] < numbers[i-1]:
            inc=False
        if not abs(numbers[i]-numbers[i-1]) in [1,2,3]:
            bad=True
    if (inc or dec) and not bad:
        ans+=1
print(ans)