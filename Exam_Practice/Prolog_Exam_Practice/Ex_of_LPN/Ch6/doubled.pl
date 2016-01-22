doubled([H|T]):-
    doubled_helper(T,[],H).

doubled_helper([H|T],Acc,First):-
    H \= First,
    append(Acc,[H],Accnext),
    doubled_helper(T,Accnext,First).

doubled_helper([H|T],Acc,First):-
    H = First,
    T = Acc.
    

doubled2([H|T]):-
    doubled_helper2(T,[H]).

doubled_helper2([H|T],[Ha|Ta]):-
    H \= Ha,
    append([Ha|Ta],[H],Acc),
    doubled_helper2(T,Acc).

doubled_helper2([H|T],[Ha|Ta]):-
    H = Ha,
    T = Ta.
