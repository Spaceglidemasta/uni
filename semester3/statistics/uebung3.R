#2.3.3: Simulate 2 dice pmf

random_dice_sum <- function(d1, d2){

    Y <- sample(d1, 1) + sample(d2, 1)

    return(Y)
}

simulate_dice <- function(d1, d2, fun, quan, target){

    count <- 0

    for(i in 1:quan){
        if(fun(d1, d2) == target){
            count <- count + 1
        }
    }

    return(count/quan)
}

simulate_dice(
            1:6,
            1:6,
            random_dice_sum,
            0,
            2
)

#2.3.4

x <- 5:9

'plot(x, dgeom(x, 0.1), type = "h", col = "blue", lwd = 2,
     main = "Plot von dgeom(x, 0.5)", xlab = "x", ylab = "dgeom(x, 0.5)")
'

#2.3.5

x <- seq(0, 1, 0.00001)

'plot(x, dbinom(11, 12, x), type = "h", col = "blue", lwd = 2,
     main = "Plot von dgeom(x, 0.5)", xlab = "x", ylab = "dgeom(x, 0.5)")
'
#this can get us an approximation, but we would
#need to read out small gaps in graphs



forsym <- function(p, fun){
    lastd <- 0
    lastprob <- 0

    for(prob in p){
        if(lastd > fun(prob)){
            return(lastprob)
        }
        lastd <- dbinom(11, 12, prob)
        lastprob <- prob
    }

}

forsym(x, function(p) dbinom(11,12,p))
# returns 0.91667, with ...66 beeing probably periodic

#2.4.3

#the higher this is, the preciser the results
dens <- 0.001
domain <- seq(0, 1, dens)

inUniform <- function(tdomain, d){
    prob <- 0
    for(atom in domain){
        if (any(abs(atom - tdomain) < d)){ #tolerance for periods
            prob <- prob + 1*d
        }
    }
    return(prob)
}

#P(U <= 1/2)
targetdmn <- seq(0, 0.5, dens)
inUniform(targetdmn, dens)

#P(U ⋴ [1/3, 2/3])
targetdmn <- seq(1/3, 2/3, dens)
inUniform(targetdmn, dens)

#P(U = 1)
targetdmn <- c(1)
inUniform(targetdmn, dens)
#this obv. goes against 0, scaling with $dens


#2.4.4:

dens <- 1000000


"2.4.4"
# Im using 1/4 instead of 4, because I think that 4 was a mistake.
# Z = Exp(4) => E[Z] = 1/4
# making P(Z = 5) almost 0, as its 20*mean
# using P(Z = 1/4) => E[Z] = 4, which makes way more sense if 
# we are searching P(Z = 5) 

samples <- rexp(dens,rate =  1/4)

mean(samples > 5)

mean(2 < samples & samples <= 5)




"2.4.5"

for(i in seq(0, 10, 0.1)){
    if(integrate(function(x) i*x, 0, 1)$value == 1){
        print(i)
        break
    }
}

for(i in seq(0, 10, 0.1)){
    if(integrate(function(x) i*(x**2), 0, 1)$value == 1){
        print(i)
        break
    }
}

"2.5.3"
"F[X](x) = {
            0   x < 1
            1/6 1 <= x < 2
            2/6 2 <= x < 3
            3/6 3 <= x < 4
            4/6 4 <= x < 5
            5/6 5 <= x < 6
            1   6 <= x
}"


"2.5.4"
ptwoxseven <- 1/sqrt(2*pi) * integrate(function(t) {exp(-(t**2)/2)}, 2, 6)$value
ptwoxseven

# or just like this apperently
pnorm(7) - pnorm(2)

pnorm(-3)

"2.6.3"


Uniform <- function(L, R, x) x %in% L:R

Y <- function(c, X, d) c*X + d


testemp <- function(R, L, x){
    for(c in 0:5){
        for(d in 0:5){
            cat(Uniform(Y(c, R, d), Y(c, L, d), x))
            cat("   ")
            cat(Y(c, R, d), Y(c, L, d), x)
            cat("\n")
        }
    }
}
testemp(0, 3, 2)

q()