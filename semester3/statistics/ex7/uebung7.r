
library(rdwd)
library(dplyr)
library(ggplot2)
library(lubridate)

station_name <- "Frankfurt/Main"

# DWD product:
# res = "daily" -> Tageswerte
# var = "kl"    -> Klima (temperature, precip, sunshine, etc.)
# per = "recent" -> recent years (or "historical")
res <- "daily"
var <- "kl"
per <- "recent"


dwd <- station_name %>%
  selectDWD(
      res = res,
      var = var,
      per = per
  ) %>%
  dataDWD(
    dir = "DWDdata",
    read = TRUE
  ) %>%
  as_tibble(
  ) %>%
  mutate(
    date = ymd(MESS_DATUM)
  ) %>%
  select(
    station = STATIONS_ID,
    date,
    t_mean = TMK,   # mean temp (degrees C)
    t_max  = TXK,   # daily max
    t_min  = TNK,   # daily min
    precip = RSK,   # precipitation (mm)
    sun    = SDK    # sunshine duration (h)
  )

dwd

cat("### Summary after column selection:\n")
dwd_summary <- dwd %>%
  summarise(
    across(
      where(is.numeric),
      list(
        min = ~min(.x, na.rm = TRUE),
        q1  = ~quantile(.x, 0.25, na.rm = TRUE),
        med = ~median(.x, na.rm = TRUE),
        mean= ~mean(.x, na.rm = TRUE),
        q3  = ~quantile(.x, 0.75, na.rm = TRUE),
        max = ~max(.x, na.rm = TRUE)
      ),
      .names = "{.col}_{.fn}"
    )
  )


cat("### Missing values per column:\n")
dwd_missing_vals <- is.na(dwd) %>%
  colSums() %>%
  as_tibble()
dwd_missing_vals

# Optionally restrict to a more recent period
dwd_since_2010 <- dwd %>% filter(date >= as.Date("2010-01-01"))
dwd_since_2010

############################################################
## 4. Univariate analysis: mean temperature
############################################################

# Histogram of mean daily temperature
ggplot(dwd, aes(t_mean)) +
  geom_histogram(binwidth = 1, fill = "steelblue", color = "white") +
  labs(
    title = "Histogram of Daily Mean Temperature",
    x = "Mean Temperature (degrees C)",
    y = "Count"
  ) +
  theme_minimal()

# Bin width matters: noisy vs oversmoothed
p_small <- ggplot(dwd, aes(t_mean)) +
  geom_histogram(binwidth = 0.5, fill = "skyblue", color = "white") +
  labs(
    title = "Very Small Bin Width (0.5 degrees C)",
    x = "Mean Temperature (degrees C)",
    y = "Count"
  ) +
  theme_minimal()

p_medium <- ggplot(dwd, aes(t_mean)) +
  geom_histogram(binwidth = 2, fill = "steelblue", color = "white") +
  labs(
    title = "Moderate Bin Width (2 degrees C)",
    x = "Mean Temperature (degrees C)",
    y = "Count"
  ) +
  theme_minimal()

p_large <- ggplot(dwd, aes(t_mean)) +
  geom_histogram(binwidth = 5, fill = "navy", color = "white") +
  labs(
    title = "Very Large Bin Width (5 degrees C)",
    x = "Mean Temperature (degrees C)",
    y = "Count"
  ) +
  theme_minimal()

p_small
p_medium
p_large

# ECDF of mean temperature
ggplot(dwd, aes(t_mean)) +
  stat_ecdf(geom = "step") +
  labs(
    title = "ECDF of Daily Mean Temperature",
    x = "Mean Temperature (degrees C)",
    y = "F_n(x)"
  ) +
  theme_minimal()

# Numerical summaries
cat("### Numerical summary of mean temperature:\n")
print(summary(dwd$t_mean)) #1b

cat("### Quartiles of mean temperature:\n")
print(quantile(dwd$t_mean, probs = c(0.25, 0.5, 0.75), na.rm = TRUE)) #1b

############################################################
## 5. Seasonal patterns: boxplots by month & season
############################################################

dwd <- dwd %>%
  mutate(
    month = factor(
      month(date),
      levels = 1:12,
      labels = c(
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
      )
    ),
    season = case_when(
      month(date) %in% c(12, 1, 2) ~ "Winter",
      month(date) %in% c(3, 4, 5)  ~ "Spring",
      month(date) %in% c(6, 7, 8)  ~ "Summer",
      TRUE                         ~ "Autumn"
    ),
    season = factor(season, levels = c("Winter", "Spring", "Summer", "Autumn"))
  ) #1a

# Boxplot by month
ggplot(dwd, aes(month, t_mean)) +
  geom_boxplot(fill = "lightgray") +
  labs(
    title = "Monthly Distribution of Daily Mean Temperature",
    x = "Month",
    y = "Mean Temperature (degrees C)"
  ) +
  theme_minimal()

# Boxplot by season
ggplot(dwd, aes(season, t_mean)) +
  geom_boxplot(fill = "lightgray") +
  labs(
    title = "Seasonal Distribution of Daily Mean Temperature",
    x = "Season",
    y = "Mean Temperature (degrees C)"
  ) +
  theme_minimal()

############################################################
## 6. Precipitation analysis
############################################################

cat("### Precipitation summary:\n")
print(summary(dwd$precip)) #1b

# Histogram (right-skewed, zoomed)
ggplot(dwd, aes(precip)) +
  geom_histogram(binwidth = 1, fill = "steelblue", color = "white") +
  coord_cartesian(xlim = c(0, 50)) +
  labs(
    title = "Histogram of Daily Precipitation (Zoomed to 0–50 mm)",
    x = "Precipitation (mm)",
    y = "Count"
  ) +
  theme_minimal()

# Wet vs dry days
dwd <- dwd %>% mutate(wet = precip > 0) #1a
print(dwd_with_wet, n = 550)

cat("### Wet vs dry days:\n")



############################################################
## 7. Bivariate analysis: Temperature vs Sunshine
############################################################

# Scatter plot
ggplot(dwd, aes(sun, t_mean)) +
  geom_point(alpha = 0.4) +
  labs(
    title = "Daily Mean Temperature vs Sunshine Duration",
    x = "Sunshine Duration (hours)",
    y = "Mean Temperature (degrees C)"
  ) +
  theme_minimal()

# Pearson correlation
cat("### Correlation (sunshine vs temperature):\n")
print(cor(dwd$sun, dwd$t_mean, use = "complete.obs")) #1b

# Linear regression
model_temp_sun <- lm(t_mean ~ sun, data = dwd)

cat("### Regression: t_mean ~ sun\n")
print(summary(model_temp_sun)) #1b

# Regression line
ggplot(dwd, aes(sun, t_mean)) +
  geom_point(alpha = 0.4) +
  geom_smooth(method = "lm", se = TRUE, color = "red") +
  labs(
    title = "Regression of Mean Temperature on Sunshine",
    x = "Sunshine Duration (hours)",
    y = "Mean Temperature (degrees C)"
  ) +
  theme_minimal()

############################################################
## 8. Contingency table: wet vs dry by season
############################################################

#4.bc
tab_wet_season <- dwd %>%
  group_by(season) %>%
  count(wet) %>%
  mutate(prop = n / sum(n)) %>%
  ungroup()


cat("### Wet vs dry by season:\n")
print(tab_wet_season)

cat("### Relative frequencies (within season):\n")
print(prop.table(tab_wet_season, margin = 2)) #1c

ggplot(dwd, aes(season, fill = wet)) +
  geom_bar(position = "fill") +
  scale_y_continuous(labels = scales::percent) +
  labs(
    title = "Relative Frequency of Wet vs Dry Days by Season",
    x = "Season",
    y = "Proportion"
  ) +
  theme_minimal()


tmeanhist <- hist(dwd$t_mean)

tmeanecdf <- ecdf(dwd$t_mean)

ggplot(dwd, aes(x = dwd$t_mean, y = dwd$season)) +
  geom_boxplot()


ggplot(tab_wet_season, aes(x = season, y = prop, fill = wet)) +
  geom_bar(stat = "identity")


library(broom)


lm(t_mean ~ sun, data = dwd, na.action = na.omit) %>%
  tidy()

lm(t_mean ~ sun, data = dwd, na.action = na.omit) %>%
  glance()

lm(t_mean ~ sun, data = dwd, na.action = na.omit) %>%
  augment()


#7a
#changes in data are easily track able over the code. Also, using tidy objects in the tidyverse ensures 
#data safety

#7b
#because they can be saved and reprocessed easily. "Written summaries" are just print statements or bare text,
#which makes them hard to apply under different circumstances 

#7c
#^^^ -> Data safety & inclusiveness

#7d
#data is processed step by step, with every change beeing visible easily. The old script hid changes and
#calculations in print statements and different datatypes


    
