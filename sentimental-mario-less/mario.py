from cs50 import get_int


def main():
    height = get_int("Height: ")
    while height > 8 or height < 1:
        height = get_int("Height: ")

    print_bricks(height)


def print_bricks(height):

    for row in range(height):
        blanks = height - row - 1
        bricks = height - blanks

        for _ in range(blanks):
            print(" ", end="")
        for _ in range(bricks):
            print("#", end="")
        print()


main()
