toptail([H|T],Outlist):-
    remove_last(T,T_rem),
    Outlist = T_rem.

remove_last([X],[]).

remove_last([H|T],T_rem):-
    remove_last(T,Y),append([H],Y,T_rem).
