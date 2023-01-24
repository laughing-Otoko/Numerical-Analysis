Numerical analysis codes in python

* Euler's method
The object of Euler’s method is to obtain approximations to the well-posed initial-value problem
dy/dt = f (t, y), a ≤ t ≤ b, y(a) = α.

continuous approximation to the solution y(t) will not be obtained; instead, approximations
to y will be generated at various values, called mesh points, in the interval [a, b].

choosing a positive integer N and selecting the mesh points
      ti = a + ih, for each i = 0, 1, 2, . . . , N
      
Euler’s method is
    w0 = α,
    wi+1 = wi + hf (ti,wi), for each i = 0, 1, . . . , N − 1.    
