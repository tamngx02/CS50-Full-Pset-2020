s = input("Text: ")

char_count = 0
space_count = 0
letter_count = 0
other = 0
word_count = 0
sentence = 0

for i in range(len(s)):
    val = ord(s[i])
    if val != ' ': #count letters
        char_count += 1
    else:
        space_count += 1
    
    if (val > 64 and val < 94 ) or (val > 96 and val < 123):
        letter_count += 1
    elif val == 32:
        space_count += 1
    else: 
        other += 1
    
    word_count = space_count + 1 #count words

    if val == 33 or val == 46 or val == 63: #count sentences
        sentence += 1
    else:
        sentence += 0

#Coleman-Liau index
#L is the average number of letters per 100 words
L = (float(letter_count) / float(word_count)) * 100 
#S is the average number of sentences per 100 words
S = (float(sentence) / float(word_count)) * 100

index = 0.0588 * L - 0.296 * S - 15.8

#identify the grade of readability
if index < 1:
    print("Before grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {int(round(index))}")
