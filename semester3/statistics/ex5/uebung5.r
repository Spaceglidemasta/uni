



library(rdwd)
library(dplyr)
library(readr)

options(max.print = 1000000)


meta <- selectDWD(id = 1420, res = "daily", var = "kl", period = "recent")
2

file <- dataDWD(meta, read = FALSE)
df <- readDWD(file)

df <- df %>% select(-eor)

df$MESS_DATUM <- as.Date(df$MESS_DATUM)


print(df)




"4"
plot(df$MESS_DATUM, df$TMK, type="b", xlab="Datum (YYYY-MM)", ylab="TMK (°C)")

plot(df$MESS_DATUM, df$RSK, type="b", xlab="Datum (YYYY-MM)", ylab="Precipation (mm)")

plot(df$MESS_DATUM, df$SDK, type="b", xlab="Datum (YYYY-MM)", ylab="Daily Sunshine (h)")

plot(df$MESS_DATUM, df$NM, type="b", xlab="Datum (YYYY-MM)", ylab="Cloud cover")

plot(df$MESS_DATUM, df$PM, type="b", xlab="Datum (YYYY-MM)", ylab="Air pressure (hPa)")


"5"
"Mean temp (°C) over the whole year:"
mean(df$TMK, na.rm = TRUE)
"Mean precipation (mm) over the whole year:"
mean(df$RSK, na.rm = TRUE)
"Sd of Sunshine: "
sd(df$SDK, na.rm = TRUE)
"Maximum wind Gust(m/s): "
max(df$FX,na.rm = TRUE)

"6"
"Hottest day"
df$MESS_DATUM[df$TXK == max(df$TXK, na.rm = TRUE)]
"Maximum wind day"
df$MESS_DATUM[df$FM == max(df$FM,na.rm = TRUE)]
"Sunshine and Temperatur relationship (°C/h)"
plot(df$TMK, df$SDK, type="p", xlab="Average day Temp (°C)", ylab="Sunshine per day (h)")

"lineares Modell"
lm_fit <- lm(SDK ~ TMK, data = df)

"Gerade hinzufügen"
abline(lm_fit, col = "blue", lwd = 2)

"
## Legend

• STATIONS ID: Station identifier 
• MESS DATUM: Date of measurement
• QN 3: Quality level for precipitation-related variables
• FX: Maximum wind gust (m/s)
• FM: Mean wind speed (m/s)
• QN 4: Quality code for temperature, humidity, radiation
• RSK: Daily precipitation amount (mm)
• RSKF: Precipitation form (0=no precipitation, 6=rain, etc.)
• SDK: Sunshine duration (hours)
• SHK TAG: Snow depth (cm)
• NM: Cloud cover
• VPM: Water vapor pressure (hPa)
• PM: Air pressure (hPa)
• TMK: Mean daily air temperature (°C)
• UPM: Relative humidity (%)
• TXK: Daily maximum temperature (°C)
• TNK: Daily minimum temperature (°C)
• TGK: Minimum ground-level temperature (°C)
• eor: End-of-record marker (can be removed)
"
