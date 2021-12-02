
with open("01-sonar-sweep/input.txt") as f:
    depths = f.read().split()
depths = [int(d) for d in depths]

prev = -1
inc_counter = 0
window = []

for i in range(len(depths)):
    d = depths[i]
    window.append(d)

    if len(window) < 3 and i < len(depths) - 1:
        continue
    if len(window) > 3:
        window.pop(0)

    s = sum(window)
    if prev != -1 and s > prev:
        inc_counter += 1

    prev = s

print(inc_counter)
