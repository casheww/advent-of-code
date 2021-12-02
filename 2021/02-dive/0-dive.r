
cmds <- scan("02-dive/input.txt", list(dir="", val=0))
pos1 <- c(0, 0)

pos1[1] <- sum(cmds$val[cmds$dir == "forward"])
pos1[2] <- sum(cmds$val[cmds$dir == "down"]) - sum(cmds$val[cmds$dir == "up"])

pos1[1] * pos1[2]
