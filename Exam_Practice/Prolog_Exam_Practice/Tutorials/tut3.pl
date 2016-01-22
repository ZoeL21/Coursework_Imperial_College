mysort(L,Sl):-
    setof(X,member(mX,L),Sl).


reverse(L,Lr):-
    reverse(L,[],Lr).

reverse([],Lr,Lr).
reverse([H|T],Acc,Lr):-
    reverse(T,[H|Acc],Lr).


followedby(X,Y,L):-
    append(B,[X,Y|E],L).

nextTo(X,Y,L):-
    followedby(X,Y,L);
    append(B,[Y,X|E],L).


sum([],0).
sum([H|T],S):-
    sum(T,St),S = St + H.


last([X],X).
last([H|T],E):-
    last(T,E).


/*****************/

edge(a,b).
edge(b,c).
edge(c,d).
edge(f,c).
edge(a,e).
edge(e,f).
edge(f,d).


path(X,Y):-
    edge(X,Y).

path(X,Y):-
    edge(X,Z),
    path(Z,Y).

path(X,Y,[X,Y|[]]):-
    edge(X,Y).

path(X,Y,[X,B|T]):-
    edge(X,B),
    path(B,Y,[B|T]).


/*****/

max([],Acc,Acc).
max([H|T],E):-
    max(T,H,E).

max([H|T],Acc,E):-
    H>Acc, max(T,H,E).
max([H|T],Acc,E):-
    H =< Acc, max(T,Acc,E).


max_of_all([H|T],E):-
    max(H,Eh),
    max_of_all(T,Eh,E).

max_of_all([],Acc,Acc).

max_of_all([H|T],Acc,E):-
    max(H,He), 
    He > Acc,
    max_of_all(T,He,E).

max_of_all([H|T],Acc,E):-
    max(H,He), 
    He =< Acc,
    max_of_all(T,Acc,E).
