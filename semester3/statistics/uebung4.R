
"4.2.4"
"Uniform[0, 1] = 1/2,"
"=> 1/n * Sum[i=1,n](1/2) P-> 1/2"
"=> 1/n * n * 1/2 P-> 1/2"
"=> 1/2 P-> 1/2'"

"4.4.4"
"Simulation:"
testsize <- 30000
count <- 0

for(i in 1:testsize){
    count <- count + (sum(rexp(1600, rate = 3)) <= 540)
}

sim <- count / testsize
sim

"CLT:"
"Y[n] ~= N(mu, sigma^2/n)"
"E(Y[n]) = 1/lambda = 1/3"
"Var(Y[n]) = (1/(lambda^2))*1600 = 1600/9"
"SD(Y[n]) = sqrt(1600/9) = 40/3"
"=> P(Sum[1, 1600](Y[n] <= 540)) ~= N((540 - 1600 * 1600/3)/(40/3))"
"=>"
p <- pnorm((540 - 1600/3)/(40/3))
p
"Δp: "
delta <- abs(sim - p)
delta

"4.4.5"
"*notes"