import statistics

with open("10-syntax-scoring/input.txt") as f:
    lines = f.read().splitlines()

pairs = {
    "(": ")",
    "[": "]",
    "{": "}",
    "<": ">"
}
illegal_values = {
    ")": 3,
    "]": 57,
    "}": 1197,
    ">": 25137
}

illegal_score = 0
autocomplete_scores = []

for l in lines:
    stack = []
    for i in range(len(l)):
        char = l[i]

        # part 1 : illegal check
        if char in pairs.keys():
            stack.append(char)
        elif pairs[stack[-1]] == char:
            stack.pop(-1)
        else:
            illegal_score += illegal_values[char]
            break

        # part 2 : autocomplete
        if i == len(l) - 1:
            line_auto_score = 0
            for c in stack[::-1]:
                line_auto_score = line_auto_score * 5 + [k for k in pairs.keys()].index(c) + 1
                print(c, line_auto_score)
            autocomplete_scores.append(line_auto_score)

print(illegal_score)
print(statistics.median(autocomplete_scores))
