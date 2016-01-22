remove_item(E,L,NewL):-
    remove_item(E,L,[],NewL).

remove_item(_,[],Acc,Acc).

remove_item(E,[E|T],Acc,NewL):-
    remove_item(E,T,Acc,NewL).

remove_item(E,[H|T],Acc,NewList):-
    E \= H, append(Acc,[H],Acc2),remove_item(E,T,Acc2,NewList).


drop_items(L,N,[]):- length(L,NL),NL < N.
drop_items(L,N,NewL):-
    append(X,NewL,L),length(X,N).

drop_more_items(L,N,[]):- length(L,NL),NL < N.
drop_more_items(L,N,NewL):-
    append(X,NewLtemp,L),length(X,N),
    findall(E,(member(E,NewLtemp),\+member(E,X)),NewL).

count(L,R):-
    count(L,[],R).

count([],Acc,Acc).

count([X|T],Acc,R):-
    member((X,Y),Acc),
    append(B,[(X,Y)|E],Acc),
    Ynew is Y + 1,
    append(B,[(X,Ynew)|E],Acc2),
    count(T,Acc2,R).

count([X|T],Acc,R):-
    \+member((X,Y),Acc),
    count(T,[(X,1)|Acc],R).
    
