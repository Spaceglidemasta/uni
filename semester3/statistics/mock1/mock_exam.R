# A1
x <- c(1, 2, 2, 3, 3, 3)
g <- factor(c("A","B","A","B","B","A"))
df <- data.frame(x = x, g = g)
str(df)
# 1)
# each row represents a value of x mapped to the corresponding value of g at the
# same index, representing a value mapped to a group
# 2)
# A: 3
# B: 3
# 3)
meanA <- mean(c(1,2,3)) 
meanB <- mean(c(2,3,3))
aggregate(df[1], list(df$g), mean)

#A2
#1
omega <- 1:100

drawsize <- 50000

drawN <- sample(omega, drawsize, replace = TRUE)



count <- 0
maxcount <- 0
for(draw in drawN){
  
  if(draw %% 3 == 0 || draw %% 5 == 0){
    maxcount <- maxcount + 1
    
    if(draw %% 3 == 0){
        count <- count + 1
    }
    
  }
  
}
Pmul35 <- count / maxcount
Pmul35

#2

div3 <- floor(100 / 3)
div5 <- 100 / 5
div15 <- floor(100 / 15)

exactPmul35 <- div3 / (div3 + div5 - div15)

#A3
#1

drawsize <- 10000

X <- rexp(drawsize, 1)


n5 <- sample(X, 5)
n30 <- sample(X, 30)
n100 <- sample(X, 100)

#2
mean(n5)
mean(n30)
mean(n100)

#3

hist(n5, probability = TRUE)
curve(
  dnorm(x, mean = mean(n5), sd = sd(n5)),
  add=TRUE
)

hist(n30, probability = TRUE)
curve(
  dnorm(x, mean = mean(n30), sd = sd(n30)),
  add=TRUE
)

hist(n100, probability = TRUE)
curve(
  dnorm(x, mean = mean(n100), sd = sd(n100)),
  add=TRUE,
)

#4
#a
Z5 <- (mean(n5) - 1) / (1 / sqrt(5))
Z5

Z30 <- (mean(n30) - 1) / (1 / sqrt(30))
Z30

Z100 <- (mean(n100) - 1) / (1 / sqrt(100))
Z100

#b ???

hist(Z5, probability = TRUE, main = "Z5")
curve(dnorm(x), add = TRUE, col = "red")
hist(Z30, probability = TRUE, main = "Z30")
curve(dnorm(x), add = TRUE, col = "red")
hist(Z100, probability = TRUE, main = "Z100")
curve(dnorm(x), add = TRUE, col = "red")

#c)
# the dist. of X_n gets more dense the higher n is, e.g. it gets closer to lamdba (1)

# d)
# CLT still works because for high sample sizes (10000), every distribution approaches normal distribution

# e)
# standardization makes it possible to compare Z_n's of different n's and lambda's,
# as they normally have completely different means and distributions.



#Part B
library(MASS)
library(dplyr)
library(ggplot2)
library(forcats)

data(birthwt)

bwt <- birthwt %>%
  mutate(
    smoke = factor(smoke, levels = c(0,1), labels = c("No","Yes")),
    ht    = factor(ht, levels = c(0,1), labels = c("No","Yes")),
    ui    = factor(ui, levels = c(0,1), labels = c("No","Yes")),
    low   = factor(low, levels = c(0,1), labels = c("No","Yes"))
  )



#B1
# 1
# one row of bwt represents data from one birth
# 2
# cat.: low / smoke / race / ht / ui
# num.: age / lwt  / ptl / ftv / bwt
#B2

#1
hist(bwt$bwt ,breaks=5000 / 150)
hist(bwt$bwt ,breaks=5000 / 400)
#2
plot(ecdf(bwt$bwt))
#3
'
My estimate: 0.3 -> 30%
1)Higher bin witdh makes the graph more smooth, but makes it harder to find outsiders within the graph.
2) the ECDF shows that most babies weigh 3kg or more after birth, and that the weight stagnates at ~800g
for low values and ~5kg for high values. Most babies weigh between ~3kg and ~5kg.
'
#B3
#1
boxplot(bwt$bwt ~ bwt$smoke,
        xlab = "Smoking status", ylab = "Birth weight",
        names = c("Non Smoker", "Smoker"),
        main= "Zaza plot")

#2
#Median weight for non-smokers
median(bwt$bwt[bwt$smoke == "No"])
#Median weight for smokers
median(bwt$bwt[bwt$smoke == "Yes"])

#3
'
Like seen in the boxplot and the median values, smoking during pregnancy can
substantially reduce the birth weight of the child. Babies from smoking mothers
also have a smaller interval for their birth weight, following the median of ~2.8kg
much more closeley then the non-smoker-babies follow the median of 3.1kg.
'

#B4
#1
table(bwt$smoke , bwt$low)
#2
prop.table(table(bwt$smoke , bwt$low))
#3
#H0: if p > 0.05, bwt$smoke and bwt$low are not related
chisq.test(bwt$smoke, bwt$low)
# p) 0.03958 -> H0 gets thrown away

#B5
#
ggplot(bwt, aes(x = bwt, y = lwt)) + geom_point(colour = "magenta")

cor(bwt$bwt, bwt$lwt)
# -> 0.1857333
# sign -> positive -> the higher the $lwt, the higher the $bwt
# magnitude ->  ~0.18 -> weak correlation

#C1
bwtlm <- lm(bwt$bwt ~ bwt$lwt)

summary(bwtlm)
#2
# f: estimated regression equation; f(x) = 4.429x + 2369.624
#3
# interpretation of the slope (4.429): On average, the $bwt is estimated to be 
# 4.429x as big as the $lwt, e.g. multiplying the $lwt with 4.429 results in an
# estimation of the respective $bwt
#4
ggplot(bwt, aes(x = bwt, y = lwt)) +
  geom_point(colour = "black") +
  geom_smooth(method = "lm", colour = "red") +
  labs(
    title = "Scatterplot + Regression for bwt ~ lwt",
    x = "Bwt",
    y = "Lwt"
  )





