# Task 1

omega <- c("1", "2", "3")

subs <- c()

#seq_along ist besser als 1:length(omega) sagt Rscript
for (i in seq_along(omega)){ 
    subs <- append(subs, combn(omega, i, simplify = FALSE))
}



p <- c(1 / 2, 1 / 3, 1 / 6)

names(p) <- omega


p_12 <- p["1"] + p["2"]


p_all <- sum(p)




vals <- lapply(subs, function(A){
    
    if (length(A) != 0){
        sum <- 0
        for (value in A){
            sum <- sum + p[value]
        }
        return(sum)
    }
    else{
        return(0)
    }

})



subs_str <- sapply(subs, function(A) {
  if (length(A) == 0) "{}"
  else paste0("{", paste(A, collapse=","), "}")
})

both <- data.frame(subs = subs_str, P = unlist(vals))


equal_half <- function(array){
    substr <- c()
    for(prob in unname(array)){
        if(prob == 0.5){
            substr <- append(substr, both[0.5])
        }
    }
    return(substr)
}

output <- list(P_12 = p_12, P_all = p_all, events_p_eq_half = both[both$P == 0.5,])



#2

N <- 100000

omega <- 1:100

x <- sample(omega, N, replace = TRUE)

EXACT_VALUE <- 0.47

estimate <- mean(x%%3 == 0 | x%%5 == 0)

output <- c(estimate = estimate,
            exact_value = EXACT_VALUE,
            delta = abs(estimate - EXACT_VALUE))
output

#3

N <- 1000

omega <- 1:6

ind_outc <- sample(omega, 2*N, replace = TRUE)

M <- array(ind_outc, dim = c(N,2))


sums_M <- apply(M, 1, sum)


output <- c(estimate = mean(sums_M == 10),
            exact_value = 3 / 36)
output


#4
#a) 365 / 365^2 = 1/365
#b) 365 / 365^C = 1/365^(C-1)
#c) 1 - (365! * (365 - N + 1)) / 365^C
#d) 23 <- Birthday paradoxon

#simulates the bd paradox with the number of persons and the number of tests
simulate_bd_pardaox <- function(n_persons, accuracy){
    succ <- 0

    for (i in 1:accuracy){
        bdays <- sample(1:365, n_persons, replace = TRUE)
        m <- duplicated(bdays)
        if(any(m)){
            succ <- succ + 1
        }
    }

    return (succ/accuracy)
}
simulate_bd_pardaox(23, 100)

#5
#get predicted

#6
#2/3

#7


q()