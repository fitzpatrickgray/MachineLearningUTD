# Data Exploration
## C++ Output
<br>![](cppoutput.png)
<br>
## ROutput
<br>![](routput.png)
<br>
+ b. R's process of gathering data from csv files, compared to C++ is smoother. Data is automatically parsed into separated vectors and common statistical functions are already implemented.
+ c. Mean is one of the more obvious uses, a value can be picked with respect to the mean and be compared. The result is not likely to be too far off from the sample, a sort of prediction. Median can be used to determine whether data is skewed one way or another. A mean equal to the median could imply a Gaussian curve. Range is a quick view into how much the dataset varies.
+ d. Variance on its own is used to show the average difference between data and the average (squared to make it positive). When approaching covariance we replace the square with a sample x, and another sample y, multiplying each other. 
  - This can result in a positive or negative result this relationship can show how one sample could affect the other.
      * +x & +y or -x & -y = positive covariance
      * -x & +y or +x & -y = negative covariance
  - Correlation, is the covariance divided by the standard deviation of x and y multiplied by each other. If x and y were one and the same (x and itself) we would get a 100% correlation. Since cov(x, x) = var(x) and var(x) = sd(x)^2
     * Therefore we get Var(x) / (sd(x)^2) = 1 a.k.a. 100%
  - Hence, replacing one factor with a different set can show us how strongly two datasets are related to one another.
