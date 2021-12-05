
with open("04-giant-squid/input.txt") as f:
    txt = f.read()

callouts = [int(x) for x in txt.splitlines()[0].split(",")]

# parse boards
boards = [b.split("\n") for b in txt.split("\n\n")[1:-1:]]
marked = []
finished = []
for i in range(len(boards)):
    marked.append([])
    for j in range(len(boards[i])):
        marked[i].append([False, False, False, False, False])
        boards[i][j] = [int(x) for x in boards[i][j].split()]

winning_board = -1


def col_check(b, x):
    col_done = True
    for y in range(5):
        if not marked[b][x][y]:
            col_done = False
            break
    return col_done


def row_check(b, y):
    row_done = True
    for x in range(5):
        if not marked[b][x][y]:
            row_done = False
            break
    return row_done


def board_check(b):
    for x in range(5):
        if col_check(b, x):
            return True
    for y in range(5):
        if row_check(b, y):
            return True


def do_callout(val):
    # mark values
    for i in range(len(boards)):
        for j in range(len(boards[i])):
            for k in range(len(boards[i][j])):
                if boards[i][j][k] == val:
                    marked[i][j][k] = True

    # check win
    winners = []
    for b in range(len(marked)):
        if b in finished:
            continue
        if board_check(b):
            winners.append(b)
    return winners


def calc_unmarked_sum(b):
    s = 0
    for x in range(len(marked[b])):
        for y in range(len(marked[b][x])):
            if not marked[b][x][y]:
                s += boards[b][x][y]
    return s


for val in callouts:
    winners = do_callout(val)
    for b in winners:
        finished.append(b)
        print(f"{b}  finished with  {calc_unmarked_sum(b) * val}")
