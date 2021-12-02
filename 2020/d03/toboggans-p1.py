
# https://adventofcode.com/2020/day/3


with open("./d03/03.txt") as f:
    slope_rows = f.read().split("\n")

x = 0
trees = 0

for r in slope_rows[1:]:
    x += 3
    if x >= len(r):
        x -= len(r)

    if r[x] == "#":
        trees += 1; print("ow")

print(trees)
