
depths <- readLines("01-sonar-sweep/input.txt") |> as.numeric()

png("01-sonar-sweep/plot.png")
plot(-depths, type="l")
