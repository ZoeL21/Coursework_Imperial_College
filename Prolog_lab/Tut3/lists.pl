mysort(L,SL):-(setof(X,member(X,L),SL)).

rev([],[]).
rev([H|T],R) :- rev(T,RevT),append(RevT,[H],R).

rev2(L,RevL):-accrev(L,[],RevL).

accrev([H|T],A,R):-accrev(T,[H,A],R).
accrev([],A,A).

followedBy(X,Y,[X,Y|T]).
followedBy(X,Y,[H1,H2|T]):- followedBy(X,Y,[H2|T]).

nextTo(X,Y,[X,Y|T]).
nextTo(Y,X,[X,Y|T]).
nextTo(X,Y,[H1,H2|T]):-nextTo(X,Y,[H2|T]).

sumList([X],X).
sumList([H|T],S):-sumList(T,St),(S is St + H). 

lastE(T,[X]):-T = X.
lastE(E,[H1,H2|T]):-lastE(E,[H2|T]).

max(X,[X]).
max(R,[H|T]):-max(Tr,T),(H>Tr->R=H;R=Tr).

max_of_All(E,[X]):-max(E,X).
max_of_All(E,[H1,H2|T]):-max(M1,H1),max(M2,H2),M1>M2,max_of_All(E,[H1|T]).
max_of_All(E,[H1,H2|T]):-max(M1,H1),max(M2,H2),M1<M2,max_of_All(E,[H2|T]).
