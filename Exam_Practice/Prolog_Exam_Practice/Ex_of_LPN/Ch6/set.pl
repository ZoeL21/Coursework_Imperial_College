set([Ha|Ta],L):-
    set_helper([Ha|Ta],[],L).

set_helper([],L,L).

set_helper([Ha|Ta],Acc,L):-
    member(Ha,Acc),
    set_helper(Ta,Acc,L).

set_helper([Ha|Ta],Acc,L):-
    \+member(Ha,Acc),
    append(Acc,[Ha],Accnext),
    set_helper(Ta,Accnext,L).
    
