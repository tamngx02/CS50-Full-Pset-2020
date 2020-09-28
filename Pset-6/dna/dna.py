from sys import argv, exit
import csv
import re

#1. check for the command-line argument
if len(argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    exit(1)

#2. open the files
#open the CSV file
with open(argv[1], "r") as database:
    csv_file = csv.reader(database, delimiter = ",")
    #make the first line(include the DNA sequences)
    STR = list(next(csv_file))
    #make the list out of csv_file
    STR_file = list(csv_file)

#open the sequence file
with open(argv[2], "r") as sequence:
    text_file = sequence.read()

#3. compute the longest run of consecutive repeats of the STR in the DNA sequence
#create the value list
value_list = []

#iterate through the file to compute the longest run of consecutive repeats of the STR in the DNA sequence
for i in range(1, len(STR)):
    #the STR sequence in the first row of the csv_file
    STR_sequence = STR[i]
    #iterate through the given DNA sequence txt file
    for j in range(len(text_file)):
        #find the consecutive groups of the STR sequence in the text_file
        #source: https://stackoverflow.com/questions/61131768/how-to-count-consecutive-substring-in-a-string-in-python-3
        sequences = re.findall(r'(?:'+ STR_sequence +')+', text_file)
        #find the longest consecutive groups by max()
        longest = max(sequences, key=len, default=0)
        max_num = len(str(longest)) // len(STR_sequence)
    value_list.append(max_num)
        
#4. comparing against data
#update the value_list values to the string to compare with the database
value_list = list(map(str, value_list))

#make a copy of the STR_file
STR_copy = list(STR_file)

#iterate though the STR sequences in the csv_file and check if the value_list is equal
for i in STR_copy:
    #if from the second column till last(exclude the name column and include DNA sequences) match, 
    #print the person name and break out of loop
    #in the ith element, we exclude the i[0] (which is the name column) then we compare to the value_list
    if i[1:] == value_list:
        print(i[0])
        break
    elif i == STR_copy[-1]:
        print("No match")



