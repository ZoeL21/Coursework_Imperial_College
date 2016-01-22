reverse1([],[]).

reverse1([H1|T1],Lr):-
    reverse1(T1,Lrr),append(Lrr,[H1],Lr).

reverse2([H1|T1],L):-
    reverse2_helper([H1|T1],[],L).

reverse2_helper([],Acc,Acc).

/*reverse2_helper([H1|T1],[],L):-
    reverse2_helper(T1,H1,L).*/

reverse2_helper([H1|T1],Acc,L):-
    reverse2_helper(T1,[H1|Acc],L).
