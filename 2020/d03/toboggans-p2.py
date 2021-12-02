
# https://adventofcode.com/2020/day/3#part2


with open("./d03/03.txt") as f:
    slope_rows = f.read().split("\n")

paths = {
    "r1d1": {},
    "r3d1": {},
    "r5d1": {},
    "r7d1": {},
    "r1d2": {}
}

for path in paths:
    x, trees = 0, 0
    row_steps = int(path[3])
    for r in slope_rows[row_steps::row_steps]:

        x += int(path[1])
        if x >= len(r):
            x -= len(r)

        if r[x] == "#":
            trees += 1
    paths[path] = {"x": x, "trees": trees}

tree_counts = [val["trees"] for val in paths.values()]
p = tree_counts.pop()
for t in tree_counts:
    p *= t
print(p)
