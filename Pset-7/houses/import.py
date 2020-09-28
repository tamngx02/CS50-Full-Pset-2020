# TODO
from cs50 import SQL
from sys import argv, exit
import os
import csv

#check for the command-line argument and check if it is a .csv file
if not(len(argv) == 2 and os.path.isfile(argv[1]) and ".csv" in argv[1]):
    print("Usage: python import.py characters.csv")
    exit(1)

#open the database
db = SQL("sqlite:///students.db")
       
#open the csv file
with open(argv[1], "r") as file:
    
    #create the file as a Dict using DictReader
    reader = csv.DictReader(file, delimiter = ",")
    
    #iterate through each file in the 
    for row in reader:
        
        #split the name column into different parts using split
        fullname = row["name"].split()
        
        #if have first, middle, last
        if len(fullname) == 3:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES (?, ?, ?, ?, ?)",
                        fullname[0], fullname[1], fullname[2], row["house"], row["birth"])
        
        # If there is not a middle name
        elif len(fullname) == 2:
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       fullname[0], None, fullname[1], row["house"], row["birth"])
                       
        # If first/last name is missing or there is more than 3 name values
        else:
            print("INVALID")
            exit(2)
            
    #success
    exit(0)
