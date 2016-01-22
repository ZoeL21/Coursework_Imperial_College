% child_mother(C, M) means C is a child of mother M.
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
child_mother(amy, mary).

child_mother(arthur, mary).

child_mother(angel, jane).

child_mother(anton, rita).

child_mother(alan, rita).

child_mother(axel, susan).

child_mother(ann, tina).

% age(C, A) means C is of age A.

age(amy, 6).

age(arthur, 15).

age(angel, 16).

age(anton, 4).

age(alan, 8).

age(axel, 16).

age(ann, 1).

% employed(X) means X is employed.

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

employed(susan).
employed(rita).


ecb(M):-
    child_mother(X,M),age(X,A),A =< 14.

ecb(M):-
    child_mother(X,M),age(X,A),A > 14, A < 16,\+ employed(M).



mother_of_the_youngest(M):-
    setof(Mo,X^no_younger_child(Mo,X),[H|T]),
    M = H.

no_younger_child(M,X):-
    child_mother(X,M),
    age(X,A),
    \+ (child_mother(Xo,Mo),age(Xo,Ao),Ao < A).


mothers_of_Young(LM):-
    setof(Mo,X^motherwithyoung(Mo,X),LM).

motherwithyoung(M,X):-
    child_mother(X,M),
    age(X,A),
    A =< 10.



merge(L1,L2,L):-
    merge(L1,L2,[],L).

merge([],L2,Acc,L):-
    append(Acc,L2,L).

merge(L1,[],Acc,L):-
    append(Acc,L1,L).

merge([H1|T1],[H2|T2],Acc,L):-
    H1 > H2,
    append(Acc,[H2],Accnew),
    merge([H1|T1],T2,Accnew,L).

merge([H1|T1],[H2|T2],Acc,L):-
    H1 =< H2,
    append(Acc,[H1],Accnew),
    merge(T1,[H2|T2],Accnew,L).


findElement(N,L,E):-
    N > 0,
    length(L,Ln),
    Ln >= N,
    append(B,[E|End],L),
    Nx is N - 1,
    length(B,Nx).
