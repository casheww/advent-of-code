
# https://adventofcode.com/2020/day/2#part2


with open("./d02/02.txt") as f:
    pwds = f.read()

valid_count = 0
for posstr, char, pwd in [e.split(" ") for e in pwds.split("\n") if e != ""]:
    pos1, pos2 = posstr.split("-")
    pos1, pos2 = int(pos1), int(pos2)
    char = char[:-1]

    if (pwd[pos1 - 1] == char) ^ (pwd[pos2 - 1] == char):
        valid_count += 1

print(valid_count)
