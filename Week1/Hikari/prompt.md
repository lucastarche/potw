# Problem of the Week: Modified FizzBuzz (Week 1)

### Problem statement

You and your friends are bored, and decide to play a popular game known as FizzBuzz. However, after a bit, it gets boring, so you decide to make it a bit harder. Instead of having to say "Fizz" when a number is divisible by 3, and "Buzz" when it is divisible by 5, you decide to agree on a set of numbers and words, and use those instead.

### Input Format

You will be given two integers, n and m. n represents the number up to which you have to process FizzBuzz. m represents the amount of numbers that will be replaced by words.
After this, m more lines follow, each with the following format:
First, a number m_i, which represents the number to replace.
After this, a string s_i, which represents the string which we have to replace when a number is divisible by m_i.

### Output Format

You should print n lines, each with a string if the number is divisible by some m_i, or the number itself if it isn't divisible by any m_i.

### Example Input

```
20 5
2 Foo
3 Bar
4 Baz
5 Qux
6 Quux
```

### Expected output

```
1
Foo
Bar
FooBaz
Qux
FooBarQuux
7
FooBaz
Bar
FooQux
11
FooBarBazQuux
13
Foo
BarQux
FooBaz
17
FooBarQuux
19
FooQux
```

### Restrictions

None, you may use any number of classes, functions and lines of code you wish to.
You are also allowed to program in any language you wish to, but making sure code stays fairly trivial and readable, and with proper naming.

### Extra points

1. Make the solution run in O(n*m) time

### Bounds

1 <= n <= 100000

1 <= m <= 1000

The length of each s_i will be of ten characters at most

### Notes

N0 - The input will come from standard input, and output is expected to be printed to standard output.

N1 - Every number m_i is guaranteed to be different

N2 - Every string s_i is guaranteed to be different

N3 - Every string s_i will not contain any spaces
