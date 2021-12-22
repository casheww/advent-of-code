
origPositions <- readLines("21-dirac-dice/input.txt")
origPositions <- substring(origPositions, nchar(origPositions), nchar(origPositions)) |> as.numeric()
origPositions <- ifelse(origPositions == 0, 10, origPositions)
scores <- c(0, 0)
die <- 1
rollCount <- 0
goal <- 1000


# part 1

roll <- function() {
    n <- die
    die <<- ifelse(die < 100, die + 1, 1)
    rollCount <<- rollCount + 1
    return (n)
}

positions <- origPositions
p <- 1
while (all(scores < goal)) {
    positions[p] <- (positions[p] + roll() + roll() + roll()) %% 10
    scores[p] <- scores[p] + positions[p]

    p <- ifelse(p == 1, 2, 1)
}

loser <- ifelse(which(scores >= goal) == 1, 2, 1)
scores[loser] * rollCount           # part 1 result



# part 2

goal <- 21
known <- data.frame("key"=character(0), "wins1"=integer(0), "wins2"=integer(0))

diracSplit <- function(p1, p2, s1, s2) {
    if (s1 >= 21)
        return (c(1, 0))
    if (s2 >= 21)
        return (c(0, 1))

    res <- known[known["key"]==paste(p1, p2, s1, s2),]
    if (nrow(res) > 0) {
        return (c(res["wins1"], res["wins2"])  |> as.numeric())
    }

    wins <- c(0,0)
    for (i in 1:3) {
        for (j in 1:3) {
            for (k in 1:3) {
                new.p1 <- p1 + i + j + k
                while (new.p1 > 10) new.p1 <- new.p1 - 10
                new.s1 <- s1 + new.p1
                n <- diracSplit(p2, new.p1, s2, new.s1)
                wins <- c(wins[1]+n[2], wins[2]+n[1])
            }
        }
    }

    known <<- rbind(known, c(paste(p1, p2, s1, s2), wins[1], wins[2]))
    known <<- setNames(known, c("key", "wins1", "wins2"))
    return (wins)
}

options(scipen = 999)
max(diracSplit(origPositions[1], origPositions[2], 0, 0))
