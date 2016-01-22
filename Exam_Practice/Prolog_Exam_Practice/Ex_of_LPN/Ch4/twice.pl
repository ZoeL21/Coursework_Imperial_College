twice([],[]).

twice([H1a|La],[H1a,H1a|Lb]):-
    twice(La,Lb).
