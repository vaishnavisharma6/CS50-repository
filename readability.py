from cs50 import get_int, get_string




text = get_string("Text:")
letters = 0
words = 1
sentences = 0
for c in text:
    if ((ord(c) >= 65 and ord(c) <= 90) or (ord(c) >= 97 and ord(c) <= 122)) :
        letters = letters + 1

    if c == " ":
        words = words + 1

    if ord(c) == 46 or ord(c) == 33 or ord(c) == 63:
        sentences = sentences + 1


averagewords = (letters/words)*100
averagesentences = (sentences/words)*100

grade = round(0.0588 * averagewords - 0.296 * averagesentences - 15.8)
if grade > 16 :
    print(" Grade 16+")
if grade < 1:
    print("Before Grade 1")

else:
    print("Grade", grade)

