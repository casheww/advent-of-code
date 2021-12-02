from itertools import combinations

# https://adventofcode.com/2020/day/1


def main(raw: str, sum_count: int):
    entries = [int(e) for e in raw.split("\n") if e != ""]
    combos = combinations(entries, sum_count)

    product = None
    for combo in combos:
        if sum(combo) == 2020:
            product = combo[0]
            for n in combo[1:]:
                product *= n
    
    if product:
        print(f"count used for sum: {sum_count}\nout: {product}\n")
    else:
        print("failed")

with open("./d01/01.txt") as f:
    expenses = f.read()
main(expenses, 2)
main(expenses, 3)
