
with open("12-passage-pathing/input.txt") as f:
    lines = f.read().splitlines()

connections = {}


def add_connection(c0, c1):
    global connections
    if c0 in connections:
        connections[c0].append(c1)
    else:
        connections[c0] = [c1]


for l in lines:
    c = l.split("-")
    add_connection(c[0], c[1])
    add_connection(c[1], c[0])


# part 2
def many_lower_dupes(path):
    small = list(filter(lambda x: x.lower() == x and x not in ["start", "end"], path))
    counts = {i : small.count(i) for i in small}
    print(counts)
    one_dupe = False
    for s in counts:
        if counts[s] == 2:
            if not one_dupe:
                one_dupe = True
            else:
                return True
        elif counts[s] > 2:
            return True


def explore(path):
    # part 1
    current = path[-1]
    if current == "end":
        return [path]
    
    # part 2
    if many_lower_dupes(path):
        return []

    paths = []
    for conn in connections[current]:
        if conn != "start":                 # for part 1 also check if cave is lowercase (small) and if it's already in the path
            paths += explore(path + [conn])

    return paths

paths = explore(["start"])
print(len(paths))


