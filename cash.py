from cs50 import get_float

while True:
    a = get_float("enter the amount:(in dollars)")
    if a > 0:
        break

x = a*100
b = 0
c = 0
d = 0
r = 0
s = 0
t = 0

if x >= 25 :
    b = x//25
    r = x%25

    if r >= 10 :
        c = r//10
        s = r%10

    elif r >= 5 and r < 10 :
        c = r//5
        s = r%5

    else :
        c = r
        s = 0
        d = 0
        t = 0



    if s >= 5 :
        d = s//5
        t = s%5

    else :
        d = s


elif x >=10 and x < 25 :
    b = x//10
    r = x%10

    if r >= 5 :
        c = r//5
        s = r%5

    else :
        c = r
        s = 0
        d = 0
        t = 0



    if s > 0 :
        d = s
        t = 0



elif x >=5 and x < 10 :
    b = x//5
    r = x%5

    if r >0 :
        c = r
        s = 0
        d = 0
        t = 0



else :

    b = x
    c = 0
    d = 0
    t = 0




print()


coins = b+c+d+t
print(coins)
print()










