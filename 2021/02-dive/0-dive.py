
with open("02-dive/input.txt") as f:
    cmds = [l.split() for l in f.read().splitlines()]

x, y = 0, 0

for cmd in cmds:
    cmd = (cmd[0], int(cmd[1]))
    x += cmd[1] if cmd[0] == "forward" else 0
    y += cmd[1] * (1 if cmd[0] == "down" else (-1 if cmd[0] == "up" else 0))

print(x * y)
