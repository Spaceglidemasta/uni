data(mtcars)
mpg_pop <- mtcars$mpg
mu_pop  <- mean(mpg_pop)  # "population mean" for this exercise
sigma_pop <- sd(mpg_pop)  # "population sd" for this exercise


'
1)
Population mpg_pop:
The whole mass of the data we are analayzing

sample:
a subset of the population

parameter:
a fixed characteristic of the statistic like mü

statistic:
the result of our calculations

2)
'
c(mu_pop = mu_pop, sigma_pop = sigma_pop, N = length(mpg_pop), sample_size = 10)

##3
mean(
  sample(mtcars$mpg,10)
)


#2

meanx <- mean(mtcars$mpg)
meanx

s <- sd(mtcars$mpg)
s

n <- length(mtcars$mpg)
n

alpha <- 1 - 0.95
alpha

df <- n - 1
df

t_crit <- qt(1 - alpha/2, df)
t_crit

SE <- s / sqrt(n)
SE

upper <- meanx + t_crit * SE
lower <- meanx - t_crit * SE

ttest <- t.test(mtcars$mpg)

c(test = ttest$conf.int[1:2],
  my_lower = lower,
  my_upper = upper) 

# t critical value instead of z crit. because low sample size and unknown sd

# if we pull an infinite amount of samples from the population and calculate a
# 95% CL for each of them, 95% of the from the respective CL resulting intervals
# are going to contain the true mean of the population

ssize <- 15

mainsample <- sample(mtcars$mpg, ssize)


calc_cl <- function(s, alpha) c(
  lower = mean(s) - qt(1 - alpha / 2, length(s) - 1) * sd(s)/sqrt(length(s)),
  upper = mean(s) + qt(1 - alpha / 2, length(s) - 1) * sd(s)/sqrt(length(s))
)



cl90 <- calc_cl(mainsample, 0.1)
cl90

cl95 <-calc_cl(mainsample, 0.05)
cl95

cl99 <- calc_cl(mainsample, 0.01)
cl99


clsdf <- data.frame(cl90, cl95, cl99)
clsdf

lapply(
  list(cl90, cl95, cl99),
  function(ci) ci["upper"] - ci["lower"]
  )

calc_cl(
  sample(mtcars$mpg, length(mtcars$mpg) / 2),
  0.05
)
cl95

# the length of the interval tends to be of same length for the same alpha

ssquared <- sd(mtcars$mpg)^2
ssquared


n <- length(mtcars$mpg)
s2 <- sd(mtcars$mpg)^2
df <- n - 1
alpha <- .05

ci_lower <- (df * s2) / qchisq(1 - alpha/2, df)
ci_upper <- (df * s2) / qchisq(alpha/2, df)

c(lower = ci_lower, upper = ci_upper)


total_pas <- sum(Titanic)

total_cas <- sum(Titanic[,,,"No"])
total_cas

p_hat <- total_cas/total_pas
p_hat


z <- qnorm(1 - 0.05 / 2)
z

SE <- sqrt(p_hat * (1 - p_hat) / total_pas)

c(
  upper =  p_hat + z * SE,
  lower =  p_hat - z * SE
)

ci_exact <- binom.test(total_cas, total_pas, conf.level = 0.95)$conf.int
ci_exact



ozone <- airquality$Ozone
ozone <- ozone[!is.na(ozone)]
ozone


meanOzone <- mean(ozone)
meanOzone

sOzone <- sd(ozone)
sOzone

n <- length(ozone)
n

calc_cl(ozone, 0.05)


airquality

ozone6 <- airquality[airquality$Month == 6
                      & !is.na(airquality$Ozone),]$Ozone
ozone6

ozone8 <- airquality[(airquality$Month == 8)
                     & !is.na(airquality$Ozone),]$Ozone
ozone8

cl6 <- calc_cl(ozone6, .05)
cl6

cl8 <- calc_cl(ozone8, .05)
cl8


cl6width <- cl6["upper"] - cl6["lower"]
cl6width

cl8width <- cl8["upper"] - cl8["lower"]
cl8width


#the width of cl8 is much higher because the sample size of ozone8 is 3 times as
#large as the one of ozone6













