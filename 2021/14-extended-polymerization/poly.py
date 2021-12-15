
# this one gave me lanternfish flashbacks
# I will never learn

with open("14-extended-polymerization/input.txt") as f:
    lines = f.read().splitlines()
polymer_str = lines[0]
subs = dict(s.split(" -> ") for s in lines[2:])


def add_char_pairs(_pairs, chars, repeats):
    for i in range(len(chars) - 1):
        p = chars[i:i+2]
        if p in _pairs:
            _pairs[p] += repeats
        else:
            _pairs[p] = repeats
    return _pairs


pairs = add_char_pairs({}, polymer_str, 1)

steps = 40      # 10 for part 1
for s in range(steps):
    new_pairs = {}

    for p in pairs:
        new_pairs = add_char_pairs(new_pairs, p[0] + subs[p] + p[1], pairs[p])

    pairs = new_pairs
    

quantities = {}
most_common = ""
least_common = ""

for p in pairs:
    n = pairs[p]
    if p[0] in quantities:
        quantities[p[0]] += n
    else:
        quantities[p[0]] = n

    if most_common == "" or n > quantities[most_common]:
        most_common = p[0]
    if least_common == "" or n < quantities[least_common]:
        least_common = p[0]

quantities[polymer_str[-1]] += 1        # last char is always the same

print(quantities[most_common] - quantities[least_common])
