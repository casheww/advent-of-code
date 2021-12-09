
raw <- readLines("09-smoke-basin/input.txt")
heights <- matrix(unlist(strsplit(raw, "")) |> as.numeric(), ncol=nchar(raw[1]), byrow=TRUE)


# part 1 : sum of scores of lowest points
adj <- list(c(-1, 0), c(0, -1), c(0, 1), c(1, 0))
lowestHeights <- c()
#lowest <- data.frame(x=c(), y=c())
lowest <- list()

for (i in 1:nrow(heights)) {
    for (j in 1:ncol(heights)) {
        h <- heights[i, j]
        lower <- c()

        for (a in adj) {
            if (i+a[1] >= 1 && i+a[1] <= nrow(heights) && j+a[2] >= 1 && j+a[2] <= ncol(heights))
                lower <- c(lower, h < heights[i+a[1], j+a[2]])
        }

        if (all(lower)) {
            lowestHeights <- c(lowestHeights, heights[i, j])
            lowest <- append(lowest, list(c(i, j)))
        }
    }
}
sum(lowestHeights + 1)


# part 2
done <- list()

boundaryFillSize <- function(start) {
    if (list(start) %in% done) {
        return(0)
    }
    done <<- append(done, list(start))
    
    area <- 1
    for (a in adj) {
        coords <- start + a
        if (coords[1] >= 1 && coords[1] <= nrow(heights) && coords[2] >= 1 && coords[2] <= ncol(heights) && heights[coords[1], coords[2]] != 9) {
            area <- area + boundaryFillSize(coords)
        }
    }

    return(area)
}

areas <- c()
for (l in lowest) {
    x <- boundaryFillSize(l)
    areas <- c(areas, x)
    done <- list()          # not necessary, but this speeds up our done check a lot
}

prod(sort(areas, decreasing=TRUE)[1:3])
