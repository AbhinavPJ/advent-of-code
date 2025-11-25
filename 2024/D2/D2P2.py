ans=0
for _ in range(1000):
    numbers= list(map(int, input().split()))
    dec=True
    inc=True
    for i in range(1, len(numbers)):
        if numbers[i] > numbers[i-1] or ( not abs(numbers[i]-numbers[i-1]) in [1,2,3]):
                #create two lists, one without this element and one without the previous element
                list1 = numbers[:i] + numbers[i+1:]
                list2 = numbers[:i-1] + numbers[i:]
                #check if either list is strictly decreasing with differences of 1,2,3
                def is_valid(lst):
                    for j in range(1, len(lst)):
                        if lst[j] >= lst[j-1] or not abs(lst[j]-lst[j-1]) in [1,2,3]:
                            return False
                    return True
                if is_valid(list1) or is_valid(list2):
                    pass
                else:
                     dec=False
                break
    for i in range(1, len(numbers)):
        if numbers[i] < numbers[i-1] or ( not abs(numbers[i]-numbers[i-1]) in [1,2,3]):
                #create two lists, one without this element and one without the previous element
                list1 = numbers[:i] + numbers[i+1:]
                list2 = numbers[:i-1] + numbers[i:]
                #check if either list is strictly increasing with differences of 1,2,3
                def is_valid(lst):
                    for j in range(1, len(lst)):
                        if lst[j] <= lst[j-1] or not abs(lst[j]-lst[j-1]) in [1,2,3]:
                            return False
                    return True
                if is_valid(list1) or is_valid(list2):
                    pass
                else:
                     inc=False
                break
    if inc or dec:
        ans+=1
print(ans)
        
    