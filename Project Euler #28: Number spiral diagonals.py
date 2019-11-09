# Enter your code here. Read input from STDIN. Print output to STDOUT
#trciky to solve in c++ or java coz of overflow. We need to do mod arth very carefully and use inverse modulos.

t = int(input())
mod = 10**9 + 7
for _ in range(t):
    n = int(input())
    sum1 = (n * (n + 1) * (2 * n + 1))//3
    sum2 = ((n - 1) * (n - 1)) // 2
    s = sum1 - sum2 - 1
    print (s % mod)
