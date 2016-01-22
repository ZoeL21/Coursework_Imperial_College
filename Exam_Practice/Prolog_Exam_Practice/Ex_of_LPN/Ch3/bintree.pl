swap(leaf(X),leaf(X)).

swap(tree(X,Y),tree(Y1,X1)):-
    swap(X,X1),
    swap(Y,Y1).
