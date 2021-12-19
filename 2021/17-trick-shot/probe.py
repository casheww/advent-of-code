import math
import re

with open("17-trick-shot/input.txt") as f:
    raw = f.read()
vals = re.findall(r"[xy]=(-?[0-9]+)\.\.(-?[0-9]+)",  raw)

tx = range(int(vals[0][0]), int(vals[0][1]) + 1)
ty = range(int(vals[1][0]), int(vals[1][1]) + 1)

# part 1
# probe will reach y=0 again when the y velocity is (initial vy * -1). -1 added for each step after that
max_uy = -(min(ty) + 1)
# max y pos will be triangular number with base max_uy
print(int(max_uy * (max_uy + 1) / 2))


# part 2
# please forgive me for my sins
success_count = 0

for ux in range(max(tx) + 1):
    for uy in range(min(ty), -max(ty) * 2 + 1):
        vx, vy = ux, uy
        x, y = 0, 0
        # while probe hasn't passed bottom-right of target (which is in the lower right quadrant)
        while x <= max(tx) and y >= min(ty):
            x += vx
            y += vy

            vx += 1 if vx < 0 else (-1 if vx > 0 else 0)
            vy -= 1

            if x in tx and y in ty:
                success_count += 1
                break

print(success_count)



"""     trajectory visualisation
x, y = [0], [0]
vx, vy = 6, 9

def prettyprint():
    s = ""
    for j in range(max(y)+2, min(y)-1, -1):
        line = ""
        for i in range(min(x)-1, max(x)+2):
            found = False
            target = False

            for a in range(len(x)):
                if i == x[a] and j == y[a]:
                    found = True
                    break
            if i in tx and j in ty:
                target=True

            line += "#" if found else "." if not target else "T"

        s += line + "\n"
    print(s) 

while x[-1] not in tx or y[-1] not in ty:
    print(tx, ty)

    x.append(x[-1] + vx)
    y.append(y[-1] + vy)

    vy -= 1
    vx += 1 if vx < 0 else (-1 if vx > 0 else 0)

    print(x[-1], y[-1])
    prettyprint()

print(x, y)
print(f"max y: {max(y)}")
print(vx, vy)
"""
