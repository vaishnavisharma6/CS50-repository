# Code for mapping people to DNA sequences using STR analysis
import sys
import csv
p = []
b = ["0"]
q = []
count = 0
value = 0
if (len(sys.argv) != 3):
    print("error")
    exit()

if(sys.argv[1] == "databases/large.csv"):
    p = ["AGATC","TTTTTTCT","AATG","TCTAG","GATA","TATC","GAAA","TCTG"]
if (sys.argv[1] == "databases/small.csv"):
    p = ["AGATC","AATG","TATC"]

f = open(sys.argv[2], "r")
Lines = f.readline()
d = len(Lines)


for i in range(0,len(p)):
    j = len(p[i])
    a = -1
    b.clear()
    for k in range(0,d):
        if (count != 0):
             a = a + j
        elif (count == 0):
             a = a+1
        m = a + j
        l = Lines[a:m]
        if(l == p[i]):
             count = count + 1
        elif(l != p[i]):
             v = count
             b.append(v)
             count = 0



    high = b[0]
    for c in b:
        if c > high:
            high = c
    q.append(high)

with open(sys.argv[1]) as csvfile1:
    reader = csv.DictReader(csvfile1)
    for row in reader:
        value = 0
        for i in range(0,len(p)):
            n = int(row[p[i]])
            if (n == q[i]):
                value = value + 1
        if (value == len(p)):
            print(row["name"])
    if(value != len(p)):
        print("No match")
