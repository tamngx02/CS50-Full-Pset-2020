def main():
    height = get_int()
    for i in range(height):
        for j in range(height + i + 3):
            if j < (height - i - 1):
               print(" ", end="")
            else:
                if (height % 10) == 1:
                    if j == height + 1 or j == height + 2:
                        print(" ", end="")
                        continue
                else:
                    if j == height or j == height + 1:
                        print(" ", end="")
                        continue
                print("#", end="")
        print()

def get_int():
    while True:
        n = int(input("Height: "))
        if n > 0 and n < 9:
            break
    return n

main()
