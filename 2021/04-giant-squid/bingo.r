
# unfinished - see python solution












callouts <- read.csv("04-giant-squid/input.txt", nrows=1, header=FALSE)

boards <- read.table("04-giant-squid/input.txt", skip=2, header=FALSE)
boards <- split(boards, rep(seq(1, nrow(boards) / 5), each=5))          # what the fuck, R

marked <- list()

mark <- function(b, x, y) {
    for (l in marked) {
        if (l$name == b) {
            l$name
        }
    }
}

checkBoardWin <- function(board) {
    for (c in 1:ncol(board)) {
        if (all(unlist(lapply(board[, c], function(x) {
            return (x == -1)
        }))))
            return (TRUE)
    }

    for (r in 1:nrow(board)) {
        if (all(unlist(lapply(board[r, ], function(x) {
            return (x == -1)
        }))))
            return (TRUE)
    }

    return (FALSE)

    #a <- unlist(lapply(board, function(col) {
    #    unlist(lapply(col, function(i) {
    #        i == -1
    #    }))
    #}))
    #print(a)
    #return (any(a))
}

checkForWinner <- function() {
    for (i in 1:length(boards)) {
        print(boards[i][[1]])
        boardDone <- checkBoardWin(boards[i][[1]])
        if (boardDone) return (i)
    }
    return (-1)
}

for (i in callouts) {
    for (i in 1:length(boards)) {
        b <- boards[i][[1]]
        for (x in 1:length(b)) {
            for (y in 1:length(b[x])) {
                if (b[x, y] == i)
                    marked[[i]] <- 
            }
        }
    }

    print(i)
    winner <- checkForWinner()
    if (winner != -1) {
        print("winner")
        print(winner)
        break
    }
}
