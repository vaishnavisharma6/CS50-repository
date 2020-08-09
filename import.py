from cs50 import SQL
import sys
import csv
db = SQL("sqlite:///students.db")

if len(sys.argv) != 2:
    print("error")
    exit()



with open(sys.argv[1]) as csvfile1:
    reader = csv.DictReader(csvfile1)

    for row in reader:
        txt = row["name"]
        x = txt.split()
        if len(x) == 3:
           firstname = x[0]
           middlename = x[1]
           lastname = x[2]

           db.execute("INSERT INTO students (first,middle,last,house,birth) VALUES (?,?,?,?,?)", firstname, middlename, lastname, row["house"], row["birth"])




        else:
            value = None
            firstname = x[0]
            lastname = x[1]
            db.execute("INSERT INTO students (first,middle,last,house,birth) VALUES (?,?,?,?,?)", firstname, value, lastname, row["house"], row["birth"])



