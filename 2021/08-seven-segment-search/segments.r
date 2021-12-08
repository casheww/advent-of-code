
lines <- readLines("08-seven-segment-search/input.txt")
lines <- strsplit(lines, " | [|] ", fixed=FALSE)

sinput <- 1:10
soutput <- 11:14
uniqueLengths <- c(2, 4, 3, 7)

uniqueCount <- 0
outputSum <- 0

commonCharCount <- function(s1, s2) {
    return(length(intersect(strsplit(s1, "")[[1]], strsplit(s2, "")[[1]])))
}

for (l in lines) {

    # part 1
    output <- l[soutput]
    digits <- match(nchar(output), uniqueLengths)
    uniqueCount <- uniqueCount + length(which(!is.na(digits)))


    # part 2
    codeMap <- data.frame(len=c(2, 5, 5, 4, 5, 6, 3, 7, 6, 6), code="")
    input <- l[sinput]

    # populate codes for unique lengths
    for (i in uniqueLengths) {
        codeMap[codeMap$len == i, "code"] <- input[nchar(input) == i]   
    }

    one <- codeMap[1, "code"]
    four <- codeMap[4, "code"]
        
    # work out codes for non-unique lengths
    for (code in input[!input %in% codeMap$code]) {
        len <- nchar(code)

        d <- -1
        if (len == 5) {
            if (commonCharCount(code, one) == 2)
                d <- 3
            else if (commonCharCount(code, four) == 3)
                d <- 5
            else
                d <- 2
        }
        else if (len == 6) {
            if (commonCharCount(code, one) == 1)
                d <- 6
            else if (commonCharCount(code, four) == 4)
                d <- 9
            else
                d <- 10     # actually 0, but indexes...
        }

        codeMap[d, "code"] <- code
    }

    # match output codes to digit values
    n <- rep("", length(output))
    for (i in 1:length(output)) {
        c <- output[i]
        for (r in 1:nrow(codeMap)) {
            common <- commonCharCount(codeMap[r, "code"], c)
            if (common == nchar(c) && codeMap[r, "len"] == nchar(c)) {
                n[i] <- ifelse(r == 10, 0, r)
                break
            }
        }
    }

    outputSum <- outputSum + (as.numeric(paste(n, collapse="")))
}

uniqueCount
outputSum
