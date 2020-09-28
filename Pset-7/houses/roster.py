# TODO
from sys import argv, exit
from cs50 import SQL
import csv

if len(argv) != 2:
    print("Usage: python roster.py house_name")
    exit(1)

db = SQL("sqlite:///students.db")

name = db.execute("SELECT * FROM students WHERE house = (?) ORDER BY last, first",argv[1])

for row in name:
    if row["middle"] != None:
        print(row["first"] + " " + row["middle"] + " " + row["last"] + ", born " + str(row["birth"]))
    else:
        print(row["first"] + " " + row["last"] + ", born " + str(row["birth"]))
    
