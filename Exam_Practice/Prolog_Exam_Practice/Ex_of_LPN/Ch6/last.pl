last([X],X).

last([H|T],X):-
    last(T,X).
