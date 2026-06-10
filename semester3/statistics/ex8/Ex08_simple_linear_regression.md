---
title: "Ex08: Inferential Statistics - Simple Linear Regression (6 exercises)"
output:
  html_document:
    toc: true
    toc_depth: 2
    number_sections: true
editor_options: 
  markdown: 
    wrap: 72
---

```{r setup, include=FALSE}
knitr::opts_chunk$set(echo = TRUE, message = FALSE, warning = FALSE)
```

## Dataset used throughout

We use the **built-in** R dataset `cars`, which records stopping
distances (ft) for cars at different speeds (mph).

```{}
```

------------------------------------------------------------------------

# Exercise 1: Least squares fit (manual)

In this exercise you compute the least-squares line *without* using
`lm()`.


```math
b_1=\frac{\sum (x_i-\bar x)(y_i-\bar y)}{\sum (x_i-\bar x)^2},
\qquad
b_0=\bar y-b_1\bar x.
```




## 1.1 Compute $\bar x$, $\bar y$, $b_1$, $b_0$

```{}
```

## 1.2 Fitted values and residuals (manual)

```math
\hat y_i=b_0+b_1x_i,\qquad e_i=y_i-\hat y_i.
```

```{}
```

### Checks (normal-equation properties)

1.  Verify that `sum(e)` is (numerically) close to 0.\
2.  Verify that `sum(e * (x - xbar))` is (numerically) close to 0.

```{}
```

## 1.3 Plot data + your fitted line

```{}
```

**Question:** Does a straight line seem plausible from the scatter plot
alone?

------------------------------------------------------------------------

# Exercise 2: ANOVA decomposition, $R^2$, and correlation (manual)

## 2.1 Compute TSS, RSS, SSE and verify TSS = RSS + SSE

```math
\text{TSS}=\sum (y_i-\bar y)^2,\quad
\text{RSS}=\sum (\hat y_i-\bar y)^2,\quad
\text{SSE}=\sum (y_i-\hat y_i)^2.
```


```{}
```

## 2.2 Compute $R^2$ two ways

$$
R^2=\frac{\text{RSS}}{\text{TSS}} = 1 - \frac{\text{SSE}}{\text{TSS}}.
$$

```{}
```

## 2.3 Show (numerically) that $R^2=r_{xy}^2$

Compute the sample correlation `cor(x, y)` and compare its square to
your `R2_from_RSS`.

```{}
```

**Question:** Why does a high $R^2$ *not* imply that speed *causes*
stopping distance (in general)?

------------------------------------------------------------------------

# Exercise 3: Inference under normal errors (manual)

In this exercise you compute standard errors and tests *using the
formulas*, and then later compare to `lm()`.

## 3.1 Residual variance $s^2$

$$
s^2 = \frac{\text{SSE}}{n-2},\qquad s=\sqrt{s^2}.
$$

```{}
```

## 3.2 Standard errors for $b_1$ and $b_0$

$$
\mathrm{se}(b_1)=\frac{s}{\sqrt{S_{xx}}},\qquad
\mathrm{se}(b_0)=s\sqrt{\frac{1}{n}+\frac{\bar x^2}{S_{xx}}}.
$$

```{}
```

## 3.3 Test $H_0: \beta_1=0$ (two-sided) using a t statistic

$$
T_1 = \frac{b_1-0}{\mathrm{se}(b_1)} \sim t_{n-2}.
$$

```{}
```

## 3.4 95% confidence interval for $\beta_1$

```{}
```

------------------------------------------------------------------------

# Exercise 4: Mean response vs. prediction at a chosen speed

Pick a speed value `x0` (try both interpolation and extrapolation).

```{}
```

## 4.1 Point prediction (fitted mean)

```{}
```

## 4.2 95% CI for the mean response at $x_0$

$$
\mathrm{se}(\hat m(x_0)) = s\sqrt{\frac{1}{n}+\frac{(x_0-\bar x)^2}{S_{xx}}}.
$$

```{}
```

## 4.3 95% prediction interval for a new observation at $x_0$

$$
\mathrm{se}_{\text{pred}} = s\sqrt{1+\frac{1}{n}+\frac{(x_0-\bar x)^2}{S_{xx}}}.
$$

```{}
```

**Question:** Why is the prediction interval wider than the CI for the
mean?

------------------------------------------------------------------------

# Exercise 5: Residuals and model checking

## 5.1 Standardized residuals

Compute leverage values
$$
h_{ii}=\frac{1}{n}+\frac{(x_i-\bar x)^2}{S_{xx}}
$$
and standardized residuals
$$
r_i = \frac{e_i}{s\sqrt{1-h_{ii}}}.
$$

```{}
```

## 5.2 Residuals vs predictor

```{}
```

## 5.3 Normal Q–Q plot

```{}
```

### Interpretation questions

-   Do you see evidence of nonlinearity (curvature) in the residual
    plot?
-   Do you see evidence of non-constant variance (spread changing with
    speed)?
-   Are there potential outliers (e.g., \|r\| \> 3)?

------------------------------------------------------------------------

# Exercise 6: Compare your manual computations to `lm()`

Now verify that your hand-computed quantities match what R reports.

## 6.1 Compare coefficients

```{}
```

## 6.2 Compare SSE, $s$, and $R^2$

```{}
```

## 6.3 Compare standard errors and the t-test for the slope

```{}
```

## 6.4 Compare confidence intervals

```{}
```

## 6.5 (Optional) Compare mean CI and prediction interval with `predict()`

```{}
```

------------------------------------------------------------------------
