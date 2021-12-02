
with open("01-sonar-sweep/input.txt") as f:
    depths = f.read().split()

prev = -1
inc_counter = 0

for d in depths:
    if prev != -1 and int(d) > prev:
        inc_counter += 1

    prev = int(d)

print(inc_counter)
