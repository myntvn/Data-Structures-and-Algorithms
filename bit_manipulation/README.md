## Applications
- Set kth bit of x to one: ```x | (1 << k)```
- Set kth bit of x to zero: ```x & ~(1 << k) ```
- Invert the kth bit of x: ```x ^ (1 << k)```
- Set last one bit of x to zero: ``` x & (x−1)```
- Set all the one bits to zero, except for the last one bit: ```x & −x```
- Inverts all the bits after the last one bit: ```x | (x−1)```
- Positive number x is a power of two exactly when ```x & (x−1) = 0```
- The kth bit of a number is one exactly when ```x & (1 << k)``` is not zero

## Additional functions
- ```__builtin_clz(x)```: the number of zeros at the beginning of the number
- ```__builtin_ctz(x)```: the number of zeros at the end of the number
- ```__builtin_popcount(x)```: the number of ones in the number
- ```__builtin_parity(x)```: the parity (even or odd) of the number of ones

## Set operations
- Intersection: ```a & b```
- Union: ```a | b```
- Complement: ```~a```
- Difference: ```a & (~b)```