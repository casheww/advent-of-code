
# https://adventofcode.com/2020/day/2


with open("./d02/02.txt") as f:
    pwds = f.read()

valid_count = 0
for countstr, char, pwd in [e.split(" ") for e in pwds.split("\n") if e != ""]:
    c_min, c_max = countstr.split("-")
    c_min, c_max = int(c_min), int(c_max)
    char = char[:-1]

    char_count = len([c for c in pwd if c == char])

    if char_count in range(c_min, c_max + 1):
        valid_count += 1

print(valid_count)
