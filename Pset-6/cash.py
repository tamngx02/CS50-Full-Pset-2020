from math import floor


#get the number of cash from the user
while True:
    cash = float(input("Change owed: "))
    if cash >= 0:
        break 

#convert to cents
cents = round(cash * 100)

quarter = floor(cents / 25)
dimes = floor((cents % 25) / 10)
nickels = floor(((cents % 25) % 10) / 5)
pennies = floor(((cents % 25) % 10) % 5)

print(quarter + dimes + nickels + pennies)
