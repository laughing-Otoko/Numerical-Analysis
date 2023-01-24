#y'(t) = f(t,y)     a<= t <= b y(a) = alpha at N+1 equal spaced numbers in the interval [a,b]
#outputs the approximation w to y at the (N+1) values of t
import math

def f(t,y):
    return y - math.pow(t, 2) + 1

def y(t):
    return math.pow((t+1), 2) - 0.5*math.pow(math.e, t)

N = 10
h = 0.2
t = 0
w = 0.5
a = 0

print('-----------------------------------------------')
print('t        w       y = y(t)        [y-w]')
print('-----------------------------------------------')
print(f'{t}       {w}         {y(t)}          {y(t)-w}')

for i in range(1, N+1):
    w = w + h*f(t,w)
    t = a + i*h
    print(f'{round(t, 7)}     {round(w, 7)}     {round(y(t), 7)}      {round(y(t)-w, 7)}')


