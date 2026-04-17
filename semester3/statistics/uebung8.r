
#1
x <- cars$speed
y <- cars$dist
n <- nrow(cars)

sum(cars$speed)

meanx <- mean(x)
meany <- mean(y)

meanx
meany

b1 <- sum(
  (x - meanx)*(y - meany)
) / (
  sum((x - meanx)^2)
)

b1

b0 <- meany - b1 * meanx


plot(x, y)
abline(a = b0, b = b1, col="red", lwd=2)

plot(cars)


guessy <- b0 + b1*x

ei <- y - guessy
plot(guessy)
plot(ei)
plot(y)

sum(ei)
#-> 1.85e-13 -> very close to 0

sum(ei * (x - meanx))
#-> -3.1e-13 -> very close to 0

TSS <- sum((y - meany)^2)
TSS
RSS <- sum((guessy - meany)^2)
RSS
SSE <- sum((y - guessy)^2)
SSE

firstR2 <- RSS /TSS
firstR2
secR2 <- 1 - SSE/TSS
secR2
# identical

cor(x,y)^2 - secR2
#identical up to 16 decimal places

#Answer: A high R2 means that speed and stopping distance are strongly correlated,
#but it does not prove causation e.g. that x -> y


var <- SSE / (nrow(cars) - 2)
var
s <- sqrt(var)
s


Sxx <- sum((x-meanx)^2)
Sxx

seb1 <- s/sqrt(Sxx)
seb1
seb0 <- s * sqrt(
  1/nrow(cars) + meanx^2 / Sxx
)
seb0

T0 <- (b1 - 0) / seb1
T0


tcrit <- qt(0.975, df = n - 2)

lower <- b1 - tcrit * seb1
lower
upper <- b1 + tcrit * seb1
upper

#-> H0 kann verworfen werden


#let x0 be 14 m/s

x0 <- 14


meanresponsex0 <- s * sqrt(
  1 / n + (x0 - meanx)^2 / Sxx
)
meanresponsex0

predintervalx0 <- s * sqrt(
  1 + 1 / n + (x0 - meanx)^2 / Sxx
)
predintervalx0

hii <- function(xi) 1/n + ((xi - meanx)^2)/Sxx
plot(hii(1:50))

plot(cars)
abline(x,y)

plot(ei)

stdres <- function(i) ei / (s * sqrt(1 - hii(i)))

summary(lm(cars))


b1
b0
model <- lm(dist ~ speed, data = cars)
coef(model)
# correct

SSE
sum(residuals(model)^2)
# correct


s
summary(model)$sigma
# correct


secR2
#Multiple R-squared:  0.6511
# correct


summary(model)$coefficients[, "Std. Error"]
seb1
# correct



T0
summary(model)$coefficients[, "t value"]


lower
upper
confint(model)



















