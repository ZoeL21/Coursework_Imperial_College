

subset(S,L):-
    append(_,S,L).

subset(S,L):-
    append(S,_,L).

powerset(Set,Powerset):-
    findall(L,subset(L,Set),Powerset).
