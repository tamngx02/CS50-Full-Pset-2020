from math import pow

def main():
    #get the input
    card_number = get_long()

    if check_valid(card_number):
        print_brand(card_number)
    else:
        print("INVALID")
    
def get_long():
    while True:
        try:
            number = int(input("Number: "))
            if number > 0:
                break
        except Exception as e:
            print(e)
    return number

def check_valid(n):
    return check_sum(n)   

def check_sum(n):
    sum = 0
    num_digits = len(str(n))
    #if the num of digits is an odd number(13 or 15) 
    #we will need to *2 the even digits and add sum with the odd digits
    if num_digits == 16:
        for i in range(num_digits):
            if (i % 2 == 0):
                digit = 2 * (n % 10)
                sum += digit // 10 + digit % 10
            else:
                sum += n % 10
            n //= 10

    #for the even number (16) digits, we *2 the odd digits and add sum the even digits            
    elif num_digits == 13 or num_digits == 15:
        for i in range(num_digits):
            if (i % 2 == 0):
                sum += n % 10
            else:
                digit = 2 * (n % 10)
                sum += digit // 10 + digit % 10
            n //= 10
    return sum % 10 == 0

def print_brand(n):
    if (n >= 34e13 and n < 35e13) or (n >= 37e13 and n < 38e13):
        print("AMEX")
    elif n >= 51e14 and n <= 56e14:
        print("MASTERCARD")
    elif (n >= 4e12 and n < 5e12) or (n >= 4e15 and n < 5e15):
        print("VISA")
    else:
        print("INVALID")


if __name__ == "__main__":
    main()
