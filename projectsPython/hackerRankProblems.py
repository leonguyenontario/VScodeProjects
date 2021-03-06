def workbook(n, k, arr):
    curPage = 1
    count = 0
    if n == 1 and k == 1:
        return arr[0]
    else:
        for i in arr:
            for curProb in range(1, i+1):
                if curProb > k and curProb % k == 1:
                    curPage += 1
                if curProb == curPage:
                    count += 1
            curPage += 1

        return count


def flatlandSpaceStations(n, c):

    if len(c) == n:
        return 0
    else:
        result = 0
        min = 0
        c.sort()
        l = abs(c[0]-0)
        r = abs(c[len(c)-1] - (n-1))
        for i in range(len(c)-1):
            left = c[i]
            right = c[i+1]
            temp = (right-left)//2
            if min < temp:
                min = temp
        result = max(min, l, r)
        return result


def fairRations(B):
    count = 0
    if sum(B) % 2 != 0:
        return "NO"
    else:
        for i in range(len(B)-1):
            if B[i] % 2 != 0:
                B[i] += 1
                B[i+1] += 1
                count += 2
        if sum(B) % 2 != 0:
            return "NO"
        else:
            return count


def introTutorial(V, arr):
    for i in arr:
        if i == V:
            return arr.index(i)


def insertionSort1(n, arr):
    temp = arr[len(arr)-1]
    for i in range(len(arr)-1, -1, -1):
        if arr[i-1] > temp:
            arr[i] = arr[i-1]
        elif arr[i-1] < temp:
            arr[i] = temp
            for k in arr:
                print(k, end=' ')
            print()
            break
        for j in arr:
            print(j, end=' ')
        print()
        if i == 1:
            arr[0] = temp
            for k in arr:
                print(k, end=' ')
            print()
            break


def happyLadybugs(b):
    flag = True
    if len(b) == 1 and b[0] != '_':
        flag = False
    elif '_' not in b:
        for i in range(len(b)):
            if i == 0:
                if b[i+1] != b[i]:
                    flag = False
            elif i == len(b)-1:
                if b[i-1] != b[i]:
                    flag = False
            else:
                if b[i-1] != b[i] and b[i+1] != b[i]:
                    flag = False
    else:
        bnew = sorted(b)
        for i in range(len(bnew)):
            if i == 0:
                if bnew[i] == '_':
                    continue
                if bnew[i+1] != bnew[i]:
                    flag = False
            elif i == len(bnew)-1:
                if bnew[i] == '_':
                    continue
                if bnew[i-1] != bnew[i]:
                    flag = False
            else:
                if bnew[i-1] != bnew[i] and bnew[i+1] != bnew[i]:
                    flag = False

    return "YES" if flag else 'NO'


def strangeCounter(t):
    rem = 3
    while t > rem:
        t = t-rem
        rem *= 2
    return rem-t+1


def minimumNumber(n, password):
    count = 0    
    if any(i.isdigit() for i in password)==False:
        count+=1
    if any(i.islower() for i in password)==False:
        count+=1
    if any(i.isupper() for i in password)==False:
        count+=1
    if any(i in '!@#$%^&*()-+' for i in password)==False:
        count+=1
    return max(count,6-n)

def alternate(s):
    if len(s)==2:
        return 2 if s[0]!=s[1] else 0
    else:        
        i=0
        while len(s)>=3:
            i +=1
            if i==len(s)-1: break
            if s[i]== s[i-1] or s[i]== s[i+1]:
                s = s.replace(s[i],'')
                i=0
        sets = set(s)
        if len(sets)<2:
            return 0
        elif len(sets)==2:
            return len(s)
        else:
            result1 = max(s.count(i) for i in sets)
            for i in sets:
                if result1==s.count(i):
                    sets.remove(i)
                    break
            result2 = max(s.count(i) for i in sets)
            return result1+result2

def main():
    # p= open('input.txt','rt')
    # a = p.read().split()
    # for i in range(0, len(a)):
    #     a[i] = int(a[i])

    # print(workbook(5,3,[4,2,6,1,10]))
    # print(flatlandSpaceStations(100, [93, 41, 91, 61, 30, 6, 25, 90, 97]))
    # print(fairRations(a))
    # print(introTutorial(4,[1,2,3,4]))
    # insertionSort1(5, [2 ,3 ,4 ,5, 6 ,7 ,8, 9 ,10, 1])
    # print(happyLadybugs('AABBC'))
    # print(strangeCounter(4))
    print(minimumNumber(11,'#HackerRank'))
    # print(alternate('asdcbsdcagfsdbgdfanfghbsfdab')) #uncomplete

if __name__ == "__main__":
    main()
