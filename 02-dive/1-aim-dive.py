
with open("02-dive/input.txt") as f:
    cmds = [l.split() for l in f.read().splitlines()]

x, y, aim = 0, 0, 0

for cmd in cmds:
    cmd = (cmd[0], int(cmd[1]))
    if cmd[0] == "forward":
        x += cmd[1]
        y += cmd[1] * aim
    aim += cmd[1] * (1 if cmd[0] == "down" else (-1 if cmd[0] == "up" else 0))

print(x * y)
