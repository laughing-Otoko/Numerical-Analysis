Wielandt Deflation

Source:
Numerical Analysis, by Richard L.Burden, J.Douglas Faires pg 589

To approximate the second most dominant eigenvalue and an associated eigenvector of the
n × n matrix A given an approximation λ to the dominant eigenvalue, an approximation v
to a corresponding eigenvector, and a vector x ∈ Rn−1:

INPUT dimension n; matrix A; approximate eigenvalue λ with eigenvector v ∈ R^n; vector x ∈ R^n−1,  tolerance TOL, maximum number of iterations N.
OUTPUT approximate eigenvalue μ; approximate eigenvector u or a message that the
method fails.

Step 1 Let i be the smallest integer with 1 ≤ i ≤ n and |vi| = max1≤j≤n |vj|.

Step 2 If i != 1 then
    for k = 1, . . . , i − 1
    for j = 1, . . . , i − 1
    set bkj = akj − (vk/vi)*aij.

Step 3 If i != 1 and i != n then
    for k = i, . . . , n − 1
    for j = 1, . . . , i − 1
    set bkj = ak+1,j − (vk+1/vi)*aij;
    bjk = aj,k+1 − (vj/vi)*ai,k+1

Step 4 If i != n then
    for k = i, . . . , n − 1
    for j = i, . . . , n − 1
    set bkj = ak+1,j+1 − (vk+1/vi)*ai,j+1.

Step 5 Perform the power method on the (n − 1) × (n − 1) matrix B' = (bkj) with x as initial approximation.

Step 6 If the method fails, then OUTPUT (‘Method fails’);
            STOP
       else let μ be the approximate eigenvalue and w = (w1', . . . ,wn−1')^t the approximate eigenvector.

Step 7 If i != 1 then for k = 1, . . . , i − 1 set wk = wk'.

Step 8 Set wi = 0.

Step 9 If i != n then for k = i + 1, . . . , n set wk = wk-1'.

Step 10 For k = 1, . . . , n
                       n
set uk = (μ − λ)wk + (sigma aij*wj )* (vk/vi).
                       j=1
(Compute the eigenvector using Eq. (9.6).)

Step 11 OUTPUT (μ, u); (The procedure was successful.)
        STOP.