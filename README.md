"# CS210-Programming-Languages" 

I chose this project to showcase the use of classes, as well as program loops. This project was designed
to collect data from the user (initial deposit, apr, additional monthly deposit, and length of investment,
and display a summary for the ending balance as well as yearly interest and balance for an account that had
no additional monthly deposits and then display the same summary for an account that accrued additional monthly
deposits.

I feel like I handled encapsulation and abstraction well with my class design. I am also happy with how my reporting
turned out. The method for printing the reports takes an enum value for the report type, allowing the output of the
report with either a pagination of the entire dataset, the head (first 5 records), tail (last 5 records) or both 
head and tail (first 5 / last 5).

One of the areas where my application could use some improvement would be with validating user input. While I had
anticipated the fact that a user may or may not enter a dollar ($) or percent (%) symbol at the beginning of their
input, I am not anticipating any such symbol at the end of their input. This could still give errors with user input
and variable types.

The more challenging part of code to write was the actual calculation of accrued interest, along with the display
of interest accrued for the year and the beginning balance. Firstly, I wanted to do the calculations year by year,
incrementing the beginning balance every year. Ultimately, I decided on using the formula for compouding interest,
which in essence is the formula for exponention growth. With that, I could also use the exponential growth formula
to get the amounts for the monthly deposits and remove them from the balace, leaving me with the accrued interest
for the year. While this is still handled in a loop, this the method to calculate these balances can be specified
for a particular year or number of months without having to iterate through a loop.

