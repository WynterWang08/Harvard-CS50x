def main():
    text = input('Text: ')
    letter = count_letters(text) * 100 / count_words(text)
    sentence = count_sentences(text) * 100 / count_words(text)
    grade = round(0.0588 * letter - 0.296 * sentence - 15.8)

    if grade < 1:
        print('Before Grade 1')
    elif grade > 16:
        print('Grade 16+')
    else:
        print(f'Grade {grade}')


def count_letters(text):
    cnt = 0
    for i in range(len(text)):
        if text[i].isalnum():
            cnt += 1
    return cnt


def count_sentences(text):
    cnt = 0
    for i in range(len(text)):
        if text[i] == '.' or text[i] == '!' or text[i] == '?':
            cnt += 1
    return cnt


def count_words(text):
    cnt = 0
    for i in range(len(text)):
        if text[i].isspace():
            cnt += 1
    return cnt + 1


if __name__ == '__main__':
    main()