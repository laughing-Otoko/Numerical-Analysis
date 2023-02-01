Euler's method algorithm
source: Numerical Analysis by Richard L. Burden, J. Douglas Faires: 9th edition

To approximate the solution of the initial-value problem
y' = f (t, y), a ≤ t ≤ b, y(a) = α,
at (N + 1) equally spaced numbers in the interval [a, b]:

INPUT endpoints a, b; integer N; initial condition α.
OUTPUT approximation w to y at the (N + 1) values of t.

Step 1 Set h = (b − a)/N;
        t = a;
        w = α;
        OUTPUT (t, w).

Step 2 For i = 1, 2, . . . , N do Steps 3, 4.
Step 3 Set w = w + hf (t, w); (Compute wi.)
      t = a + ih. (Compute ti.)
      Step 4 OUTPUT (t,w).
      Step 5 STOP
      
 Function f(t,y) in eulersmethod.cpp should be changed to correspond the function you are working with.
 As well as the function y(t).
