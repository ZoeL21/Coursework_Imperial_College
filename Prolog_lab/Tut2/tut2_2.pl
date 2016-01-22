fib(2,X):-X=1.
fib(1,X):-X=1.


fib(Y,X):- Y1 is Y - 2, fib(Y1,X1),Y2 is Y - 1, fib(Y2,X2), X is X1 + X2.
    
