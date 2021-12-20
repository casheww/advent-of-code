
# not performant, but it only took 5 mins to run so lol

raw <- readLines("20-trench-map/input.txt")
filter <- raw[1]
lit <- matrix(unlist(strsplit(raw[3:length(raw)], "")), ncol=nchar(raw[3]), byrow=TRUE)
fill <- "."


addBorder <- function(m, borderSize, fillChar) {
    new <- matrix(fillChar, ncol=ncol(m) + borderSize*2, nrow=nrow(m) + borderSize*2)
    for (j in 1:nrow(m)) {
        for (i in 1:ncol(m)) {
            new[j+borderSize, i+borderSize] <- m[j, i]
        }
    }
    return (new)
}

trimBorder <- function(m, trimSize) {
    new <- matrix("", ncol=ncol(m) - trimSize*2, nrow=nrow(m) - trimSize*2)
    for (j in 1:nrow(new)) {
        for (i in 1:ncol(new)) {
            new[j, i] <- m[j+trimSize, i+trimSize]
        }
    }
    return (new)
}


getFilterChar <- function(sample) {
    index <- 1
    for (i in 0:(nchar(sample) - 1)) {
        n <- nchar(sample) - i
        index <- index + ifelse(substring(sample, n, n) == "#", 2^i, 0)
    }
    return (substring(filter, index, index))
}


enhancePixel <- function(m, j, i) {
    sample <- ""
    for (y in (j-1):(j+1)) {
        for (x in (i-1):(i+1)) {
            sample <- paste(sample, m[y, x], sep="")
        }
    }
    return (getFilterChar(sample))
}


steps <- 50
for (s in 1:steps) {
    new <- lit <- addBorder(lit, 3, fill)
    
    for (j in 2:(nrow(lit)-1)) {
        for (i in 2:(ncol(lit)-1)) {
            new[j, i] <- enhancePixel(lit, j, i)
        }
    }

    new <- trimBorder(new, 2)
    lit <- new

    fillIndex <- ifelse(fill == ".", 2^0, 2^9)
    fill <- substring(filter, fillIndex, fillIndex)
}

length(lit[lit=="#"])
