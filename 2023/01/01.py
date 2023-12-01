
with open("01/input.txt", "r") as f:
    lines = f.readlines()


def part_one(lines: str) -> int:
    return sum((lambda l: 10*l[0] + l[-1])([int(c) for c in l if c.isdigit()]) for l in lines)


def part_two(lines: str) -> int:
    parsed_lines = []
    for l in lines:
        l = l.replace("one", "one1one")
        l = l.replace("two", "two2two")
        l = l.replace("three", "three3three")
        l = l.replace("four", "four4four")
        l = l.replace("five", "five5five")
        l = l.replace("six", "six6six")
        l = l.replace("seven", "seven7seven")
        l = l.replace("eight", "eight8eight")
        l = l.replace("nine", "nine9nine")
        parsed_lines.append(l)

    return part_one(parsed_lines)

print(part_two(lines))
