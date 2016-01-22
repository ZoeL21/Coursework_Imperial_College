

flatten(X,F):-
    flatten(X,[],Rf),
    reverse(Rf,F).


flatten([],Acc,Acc).

flatten([H|T],Acc,Rf):-
    flatten_head(H,Acc,RfH),
    flatten(T,RfH,Rf).

flatten_head(H,AccH,AccH):-
    H = [].

flatten_head(H,AccH,[H|AccH]):-
    atom(H),H \= [];integer(H).

flatten_head(H,AccH,RfH):-
    flatten(H,AccH,RfH).


reverse([X],[X]).
reverse([H|T],R):-
    reverse(T,Rt),append(Rt,[H],R).

    
    

