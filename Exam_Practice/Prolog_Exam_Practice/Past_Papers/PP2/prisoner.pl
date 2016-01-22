forall(C1,C2) :- \+ (C1, \+ C2).

in_range(Min,Max,N):-
    N < Min.
in_range(Min,Max,N):-
 N >= Max.

empty_cell(N):-
    cell(N),
    forall(prisoners(F,S,Cn,C,S,Ts),N\=Cn).

all_female_cell(N):-
    cell(N),
    forall(prisoners(Fn,Sn,N,C,S,Ts),female_name(Fn)).

female_priisoners(N):-
    setof(Fn,(prisoner(Fn,Sn,Cn,C,S,Ts),female_name(Fn)),L),length(L,N).
