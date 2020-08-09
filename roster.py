from cs50 import SQL
import sys
import csv

db = SQL("sqlite:///students.db")
if len(sys.argv) != 2:
    print("error")
    exit()

x = db.execute("SELECT * FROM students ORDER BY last,first")

def search(name):
   for c in x:
       if c["house"] == name:
          if c["middle"] == None:
             print(c["first"], c["last"]+",", "born", c["birth"])
          if c["middle"] != None:
             print(c["first"], c["middle"], c["last"]+",", "born", c["birth"])

search(sys.argv[1])
