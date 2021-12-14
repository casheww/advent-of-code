
with open("13-transparent-origami/input.txt") as f:
    lines = f.read().splitlines()
coords = [l for l in lines if l != "" and not l.startswith("fold")]
folds = [l[11:].split("=") for l in lines if l.startswith("fold")]

coords = [(int(c.split(",")[0]), int(c.split(",")[1])) for c in coords]


def prettyprint(c):
    xs = [p[0] for p in c]
    ys = [p[1] for p in c]
    out = ""
    for y in range(min(ys)-1, max(ys)+2):
        s = ""
        for x in range(min(xs)-1, max(xs)+2):
            s += "#" if (x, y) in c else "."
        out += s + "\n"
    print(out)


part1done = False
for i in range(len(folds)):
    axis = folds[i][0]
    val = int(folds[i][1])

    if axis == "y":
        coords = [(c[0], 2*val-c[1] if c[1] > val else c[1]) for c in coords]
    elif axis == "x":
        coords = [(2*val-c[0] if c[0] > val else c[0], c[1]) for c in coords]

    unique = []
    for c in coords:
        if c not in unique:
            unique.append(c)
    coords = unique

    if not part1done:
        print(f"part 1 : {len(coords)}")
        part1done = True

    if i == len(folds) - 1:
        prettyprint(coords)
