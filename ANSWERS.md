Rylan Petroelje
Professor Charitha Subrahmanya Kodumagulla
CIS 343 02
11 November 2025

# Project 3: Life After a CS Degree

## Problem 1:
The professor was right, his static variables are correct, but the way he declares his new cars is broken. In `main.c`, cars are being declared with other cars like so:
```cpp
Car b(a);
```
This structure doesn't adhere to the implemented constructor, which takes in an integer and a string. What I'm guessing is happening here is it's just making a copy of the last car and not running the intended instructor. To fix this, I added a new constructor that takes in a Car and passes the previous car's information by reference instead of value, as well as updating the id.

## Problem 2:


## Problem 3:


## Problem 4:

