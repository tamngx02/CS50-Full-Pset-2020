def main():
    height = get_int()
    for i in range(height):
        for _ in range(height - i - 1):
            print(" ", end="")
        for _ in range(i + 1):
            print("#", end="")
        print()

def get_int():
    while True:
        n = int(input("Height: "))
        if n > 0 and n < 9:
            break
    return n

main()
