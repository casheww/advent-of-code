
crabs <- unlist(read.csv("07-treachery-of-whales/input.txt", header=FALSE))

# part 1 : 1 fuel per move

avg <- round(median(crabs))
sum(abs(crabs - avg))

# part 2 : increasing fuel per move
avg <- floor(mean(crabs))
dists <- abs(crabs - avg)
sum(dists * (dists + 1) / 2)
