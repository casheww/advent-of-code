
left_smallest = -1
right_smallest = -1

with open("input.txt") as f:
    lines = f.readlines()

left = []
right = []

for l in lines:
    pair = [int(v) for v in l.split()]
    left.append(pair[0])
    right.append(pair[1])

left_index_order = []
right_index_order = []

for i in range(len(left)):
    
