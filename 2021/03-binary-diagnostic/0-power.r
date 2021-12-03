
raw <- readLines("03-binary-diagnostic/input.txt")
gamma <- ""
epsilon <- ""

oxygenPool <- raw
co2Pool <- raw

for (i in 1:nchar(raw[1])) {
    bit <- median(as.numeric(substr(raw, i, i)))
    gamma <- paste(gamma, bit, sep="")
    epsilon <- paste(epsilon, ifelse(bit=="1", "0", "1"), sep="")
    
    bit <- median(as.numeric(substr(oxygenPool, i, i)))
    bit <- ifelse(bit == 0.5, 1, bit)
    if (length(oxygenPool) > 1)
        oxygenPool <- oxygenPool[substr(oxygenPool, i, i) == bit]

    bit <- median(as.numeric(substr(co2Pool, i, i)))
    bit <- ifelse(bit == 0.5, 1, bit)
    if (length(co2Pool) > 1)
        co2Pool <- co2Pool[substr(co2Pool, i, i) != bit]
}

# part 1 : power consumption rating
base::strtoi(gamma, base=2) * base::strtoi(epsilon, base=2)

# part 2 : life support rating
base::strtoi(oxygenPool[1], base=2) * base::strtoi(co2Pool[1], base=2)
