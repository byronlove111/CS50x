from cs50 import get_float


def main():
    user_input = get_float("Change: ")
    while user_input < 0:
        user_input = get_float("Change: ")

    change(user_input)


def change(somme):
    somme_cents = int(somme * 100)
    counter = 0

    while somme_cents >= 25:
        somme_cents -= 25
        counter += 1

    while somme_cents >= 10:
        somme_cents -= 10
        counter += 1

    while somme_cents >= 5:
        somme_cents -= 5
        counter += 1

    while somme_cents >= 1:
        somme_cents -= 1
        counter += 1

    print(counter)


main()
