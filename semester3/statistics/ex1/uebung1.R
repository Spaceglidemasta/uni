#1

a <- 7.5
b <- 2

print(a + b)
print(a - b)
print(a * b)
print(a / b)

quotient = floor(a / b)
rest     = a %% b

print(quotient)
print(rest)

a = a^b

rm(b)

#2

x <- 1:8

print(x^2 - 3*x + 2)

print(mean(x))
print(var(x))
print(sd(x))

even <- x %% 2
print(even)

#3

y <- c(10, 20, 30, 40, 50)

y <- y[-1]

print(y)

y <- y + c(1,2)

print(y)

#the vector is getting mapped onto y, with the operation of add (+)


#4

sex <- c("male", "female", "female", "male", "male")
facsex <- factor(sex)
print(facsex)

#proportion table
table(sex)

#frequenzy table
prop.table(table(sex))


#5

M <- array(1:9, dim = c(3,3))
print(M)

M %*% t(M)

print(sum(M[1, ]))
print(sum(M[2, ]))
print(sum(M[3, ]))

print(mean(M[ ,1]))
print(mean(M[ ,2]))
print(mean(M[ ,3]))

M <- M[-2, ]

print(M)

M[2,3] <- 0

print(M)


#6

randomnums <- rnorm(5)

initials <- c("LDS","LDS","LDS","LDS","LDS")


dumme_scheiss_liste <- c(randomnums, initials, M)

dummes_dataframe <- data.frame(dumme_scheiss_liste)

print(dummes_dataframe)
q()
#7


smalldf <- data.frame(
    x = rnorm(10, 5, 2),
    y = rnorm(10, 10, 3)
)

print(smalldf)

tmpfile <- tempfile(fileext = ".csv")
write.csv(smalldf, tmpfile, row.names = FALSE)

df_from_csv <- read.csv(tmpfile)
print(df_from_csv)


plot(df_from_csv$x, df_from_csv$y,
     main = "Scatter plot with fitted least-squares line",
     xlab = "x",
     ylab = "y",
     pch = 19, col = "blue")


fit <- lm(y ~ x, data = df_from_csv)


abline(fit, col = "red", lwd = 2)


print(fit)

#8

zscore <- function(x){
    if(sd(x) == 0){
        cat("WARNING: sd(x) = 0\n")
        return()
    }
    return(x - mean(x)) / sd(x)
}

zscore(c(5, 5, 5))
zscore(c(1, 2, 3, 4))


#9

sapply(mtcars, mean)

apply(mtcars, 2, quantile, probs = c(0.25, 0.75))

aggregate(. ~ cyl, data = mtcars, FUN = mean)

mtcars

#10

n <- 100

x <- rnorm(n, mean = 0, sd = 1)

e <- rnorm(n, mean = 0, sd = 1)

y <- 3 + 2*x + e

dfy <- data.frame(x = x, y = y)
print(dfy)

fit <- lm(y ~ x, data = dfy)
summary(fit)

#Bonus

set.seed(69)

if(all(rnorm(5)) == all(rnorm(5))){
    print("The seed works!")
}

drawing <- rnorm(10000, mean = 0, sd = 1)

history <- hist(drawing,
                breaks = 30,
                col = "lightblue",
                main = "Histogram of 1000 draws from N(0,1)",
                xlab = "x values",
                ylab = "Frequency")

history