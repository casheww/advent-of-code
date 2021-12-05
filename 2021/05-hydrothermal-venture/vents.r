
input <- readLines("05-hydrothermal-venture/input.txt")
input <- strsplit(input, ",| -> ", fixed=FALSE)

m <- matrix(0, nrow=1000, ncol=1000)

for (i in 1:length(input)) {
    lEnds <- as.numeric(input[[i]])
    start <- c(lEnds[1], lEnds[2]); end <- c(lEnds[3], lEnds[4])

    # part 1 : vertical and horizontal
    if (start[1] == end[1]) {
        s <- seq(start[2]+1, end[2]+1)
        line <- m[start[1]+1, s]
        m[start[1]+1, s] <- line + 1
    }
    else if (start[2] == end[2]) {
        s <- seq(start[1]+1, end[1]+1)
        line <- m[s, start[2]+1]
        m[s, start[2]+1] <- line + 1
    }

    # part 2 : diagonal
    else if (abs((start[1] - end[1]) / (start[2] - end[2]))) {
        sx <- seq(start[1]+1, end[1]+1)
        sy <- seq(start[2]+1, end[2]+1)
        line <- m[cbind(sx, sy)]
        m[cbind(sx, sy)] <- line + 1
    }
}

length(which(m > 1))
