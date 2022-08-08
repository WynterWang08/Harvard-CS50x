import sys


def main():
    creditnum = input('Number: ')
    length = len(str(creditnum))

    if length != 13 and length != 15 and length != 16:
        print('INVALID')
        sys.exit()

    if length % 2 == 0:
        flag = True
    else:
        flag = False

    creditsum = 0
    for i in range(length):
        if flag:
            legitsum = int(creditnum[i]) * 2

            if legitsum >= 10:
                creditsum += legitsum - 9
            else:
                creditsum += legitsum
            flag = False
        else:
            creditsum += int(creditnum[i])
            flag = True

    credit = int(creditnum[0]) * 10 + int(creditnum[1])
    if creditsum % 10 == 0:
        if credit == 34 or credit == 37:
            print('AMEX')
        elif 51 <= credit <= 55:
            print('MASTERCARD')
        elif int(creditnum[0]) == 4:
            print('VISA')
        else:
            print('INVALID')


if __name__ == '__main__':
    main()