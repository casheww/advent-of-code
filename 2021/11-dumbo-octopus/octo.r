
raw <- readLines("11-dumbo-octopus/input.txt")
octos <- matrix(unlist(strsplit(raw, "")) |> as.numeric(), ncol=nchar(raw[1]), byrow=TRUE)

step <- 0
flashes <- 0
step100Flashes <- 0
flashesThisStep <- 0
firstSyncStep <- -1

flash <- function(row, col) {
    flashes <<- flashes + 1
    flashesThisStep <<- flashesThisStep + 1

    octos[row, col] <<- -1

    for (y in (row-1):(row+1)) {
        for (x in (col-1):(col+1)) {
            if (x < 1 || x > ncol(octos) || y < 1 || y > nrow(octos) || octos[y, x] == -1)
                next
            octos[y, x] <<- octos[y, x] + 1
            if (octos[y, x] > 9){
                flash(y, x)
            }
        }
    }
}

while (flashesThisStep < length(octos)) {
    step <- step + 1
    flashesThisStep <- 0

    octos <- octos + 1

    done <- FALSE
    while (!done) {
        toFlash <- which(octos > 9)
        if (length(toFlash) > 0) {
            n <- toFlash[1]
            r <- n %% ncol(octos)
            flash(ifelse(r == 0, 10, r), ceiling(n / ncol(octos)))
        }
        else
            done <- TRUE
    }

    octos[octos == -1] <- 0

    if (step == 100)
        step100Flashes <- flashes
}

step100Flashes      # part 1
step                # part 2
