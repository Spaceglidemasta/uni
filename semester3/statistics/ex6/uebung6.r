library(MASS)
library(dplyr)
library(ggplot2)
library(forcats)
data(birthwt)
bwt <- birthwt %>%
  mutate(
    race = factor(race, levels = c(1,2,3),
                  labels = c("White","Black","Other")),
    smoke = factor(smoke, levels = c(0,1),
                   labels = c("No","Yes")),
    ht = factor(ht, levels = c(0,1),
                labels = c("No","Yes")),
    ui = factor(ui, levels = c(0,1),
                labels = c("No","Yes")),
    low = factor(low, levels = c(0,1),
                 labels = c("No","Yes"))
  )

#1.1 Every row in this ds shows a birthing with given attributes
#1.2 & 3
#low: categorical; 1 if the baby was born underweight
#age: numeric; age of the mother at time of birth in years
#lwt: numeric; the last weight of the mother before pregnancy (in pounds)
#race: categorical; ethnicity of the mother
#smoke: categorical; 1 if the mother smoked during pregnancy
#ptl: numeric; previous preterm labours
#ht: categorical; 1 if the mother had hight blood pressure / hypertension
#ui: categorical; 1 if the mother had uterine irritablity
#ftv: numeric; number of first trimester doctor visits
#bwt: numeric; weight of baby after birth (in gramms)
bwt


p <- ggplot(data=data.frame(low=bwt$low, smoke=bwt$smoke), aes(x=low, y=smoke)) + geom_bar(stat="identity")
p

prop.table(table(bwt$low))
#=>  31%: very very high ()


#3.1
hist(bwt$bwt, xlab = "Birthweight", col="#9a9aff", breaks = 25)
#3.2: A higher bin width smoothens out the histogram, but makes it less precise
#3.3: symmetric with a tiny right shift



#4.1
p <- ggplot(bwt, aes(x = bwt)) + stat_ecdf() + labs( title = "ECDF of Birth Weight",
                                                x = "Birth Weight (g)",
                                                y = "ECDF")

p
#4.2 ~ 37.5%
#4.3
median(bwt$bwt)

#5.1

sixnumsum <- function(x){
  return (c(fivenum(x), mean(x)))
}

sixnumsum(bwt$bwt)

#5.2
#the lower the Pearson skewness coefficient is, the more evenly is the data spread.
#the psc of {1, 1.5, 2, 1.3, 1000} would have a very high psc, because its highly spread

psc <- abs((mean(bwt$bwt) - median(bwt$bwt)) / sd(bwt$bwt))
psc


#6
range(bwt$lwt)
IQR(bwt$lwt)
sd(bwt$lwt)

#6.2: sd, because the IQR may not capture outliers in high X ranges, like in the example above (5.2)
#?: Does he (the prof) want to capture the outliers or not? I know that most of the time u dont, but 
#   "as a measure of spread" sounds like you really want to capture those strong outliers

boxplot(bwt$lwt)
# a lot of "outliers"

#7.1
boxplot(bwt$smoke)

#7.2
median(bwt$bwt[bwt$smoke =="No"],na.rm = TRUE)
median(bwt$bwt[bwt$smoke =="Yes"],na.rm = TRUE)

#7.3
IQR(bwt$bwt[bwt$smoke == "No"], na.rm = TRUE)
IQR(bwt$bwt[bwt$smoke == "Yes"], na.rm = TRUE)

#7.4 there are more outliers in the no smoking group
x <- bwt$bwt[bwt$smoke == "No"]
abs((mean(x) - median(x)) / sd(x))
x <- bwt$bwt[bwt$smoke == "Yes"]
abs((mean(x) - median(x)) / sd(x))

#8.1
ggplot(bwt, aes(x = bwt, color = smoke)) +
  geom_density()
#8.2 The birthweight of smokers is 1. higher, and 2. less more spreaded out.
#Its less dense then the bwt of non smokers

#9.1
ggplot(bwt, aes(x = smoke, y = bwt)) +
  geom_violin()
#9.2 it also reveals the kernel density estimation

#10.1
ggplot(bwt, aes(x = bwt, y = lwt)) +
  geom_point()

#10.2
#this shows that the weight of mother does not influance the weight of the baby by a significant amount
#10.3
#yes, one baby was born with ~450g and one with 5kg, and one mother weights 250 pounds while her baby weighs ~3.2kg
#also, there is one baby with ~1.2kg (which is critically light) despite its mother weighing almost 200 pounds

#11.1
r <- cor(bwt$lwt, bwt$bwt, use = "complete.obs")
r
#=> 0.186 => The heavier the mother, the heavier the child.
#11.2=> direction: postive, strenght: 18,6%
#11.3 Yes, it leans towards a positive linear correlation, but its of no significance

#12.1
t <- table(bwt$smoke, bwt$low)
t
#12.2
prop.table(t, margin = 1)
#12.3 Smokers

#13
#Null Hypothesis: Underweight births are tied to if the mother smokes
#Alternative Hypothesis: Smoking is not tied to underweight carriage
chisq.test(bwt$smoke, bwt$low)
#=> p = 0.03958 <=> p < 0.05 => we discard the null Hypothesis.

#15.1

lm(bwt ~ lwt, data = bwt)

#15.2

#bwt(lwt) = 2369.624 + 4.429*lwt

#15.3
#The expected weight in gramms at birth is 2369.624, plus 4.429 times the weight of the mother in pounds

#16.1

ggplot(bwt, aes(x = bwt, y = lwt)) +
  geom_smooth(method="lm")

#16.2 the relation lmt ~ bwt is linear, so a straight line seems fitting, yes.

#16.3 definitely smoke, as it was already shown in several subtasks that it has a big
# impact on the bwt

#17.1
#non-smokers
mean(bwt$bwt[bwt$smoke=="No"])
median(bwt$bwt[bwt$smoke=="No"])
#smokers
mean(bwt$bwt[bwt$smoke=="Yes"])
median(bwt$bwt[bwt$smoke=="Yes"])


'
The contingency table clearly showed that smoking during pregnency increases the rate of
having a lwt. This is backed up by the means and medians above, which also show that
smoking during pregnency decreases the expected bwt.
The violin graphs also show that not only is the average bwt lower, the spreading (and therefore
the chance of potential outliers) is increased when smoking. The density- and boxgraph show the same.
'

#18
#It is important to look at both numeric and graphical summaries, because either one can
#be misleading in certain regards. For example, the mean can be misleading when the data has outliers,
#but the median can be misleading when trying to spot these exact outliers. The graphical summaries
#on the other hand may give you a better view on the big picture, but make it hard to get precise data.
#They are also limited in what they can show; Most graphs are 2 Dimensional and can therefore only
#represent the relation of 2 variables at a time, which may not be sufficient.
#An example for this is the scatter plot, which provided us with the outliers, which are
#not visible to most numeric answers.





