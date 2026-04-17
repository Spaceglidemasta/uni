
t / z _crit <- qt(1 - alpha / 2) or qnorm(1 - alpha / 2)
(2 sided)
left:  qx(1 - alpha)
right: qx(alpha)

z or t _test <- (meanx - mu_0) / (s / sqrt(n))
z:s <- known (true) sigma
t:s <- sigma / s from sample

p_2sided <- 2 * (1 - pt(abs(t_obs), df = n-1))
p_2sided <- 2 * min(
  pchisq(Q, df=31),      # linke Seite
  1 - pchisq(Q, df=31)   # rechte Seite
)