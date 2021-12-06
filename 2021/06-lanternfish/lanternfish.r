
raw <- unlist(read.csv("06-lanternfish/input.txt", header=FALSE))
days <- 256
reproDays <- 6
newbornReproDays <- reproDays + 2
s <- seq(0, newbornReproDays)
matrixOffset <- 1 - s[1]

fish <- matrix(0, nrow=0, ncol=2)
for (i in s) {
    fish <- rbind(fish, c(i, length(raw[raw==i])))
}

# this was a good solution until I ran it to 256 and ran out of memory fgjfjfds
#fish <- unlist(read.csv("06-lanternfish/input.txt", header=FALSE))
#for (d in 1:days) {
#    fish <- fish - 1
#    s <- rep(8, each=length(fish[fish==-1]))
#    fish <- append(fish, s)
#    fish[fish==-1] <- reproDays
#}
#print(length(fish))

for (d in 1:days) {
    copy <- fish
    
    for (i in s + matrixOffset) {
        fish[i-1, 2] <- copy[i, 2]
    }

    toRepro <- copy[0 + matrixOffset, 2]
    n <- fish[reproDays + matrixOffset, 2]      # count already at reproDays

    # reset expired counters, adding the number fish already at this index which will have been born 2 days ago
    fish[reproDays + matrixOffset, 2] <- toRepro + n        
    copy[-1 + matrixOffset, 2] <- 0

    # add newborn fish
    fish[newbornReproDays + matrixOffset, 2] <- toRepro
}

options(scipen = 999)       # disable scientific notation (e.g., 1.569108e+12) because JEEZ this number is big
sum(fish[, 2])
