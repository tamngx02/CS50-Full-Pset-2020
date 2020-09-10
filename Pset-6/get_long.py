#I refered to this article to write this get_long function
#this could be useful for someone who is doing credit.py in pset6
#as the get_long in cs50 library is no longer available in pset6

def get_long():
    while True:
        try:
            number = int(input("Number: "))
            if number > 0:
                break
        except Exception as e:
            print(e)
    return number
