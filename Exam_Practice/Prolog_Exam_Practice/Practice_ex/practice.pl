sublist([],_).
sublist([H|T],L):-
    member(H,L),sublist(T,L).

/*****************/

difference([H|T],L2,Ld):-
    difference_helper([H|T],L2,[],Ld).

difference_helper([],_,Ld,Ld).
difference_helper([H|T],L2,Acc,Ld):-
    \+member(H,L2),append(Acc,[H],Acc2),difference_helper(T,L2,Acc2,Ld).

difference_helper([H|T],L2,Acc,Ld):-
    member(H,L2),difference_helper(T,L2,Acc,Ld).

/*****************/
difference2([X],L2,[X]):-
    \+member(X,L2).

difference2([X],L2,[]):-
    member(X,L2).

difference2([H|T],L2,Ld):-
    \+member(H,L2),difference2(T,L2,Ldd),append(Ldd,[H],Ld).

difference2([H|T],L2,Ld):-
    member(H,L2),difference2(T,L2,Ld).
/*****************/
    
sift(L,N,R):-
    sift(L,N,[],R).

sift([],_,X,X).

sift([H|T],N,Acc,R):-
    H =< N, append(Acc,[H],Accnext), sift(T,N,Accnext,R).

sift([H|T],N,Acc,R):-
    H > N,sift(T,N,Acc,R).

/****************/
common(L1,L2,Lc):-
    common(L1,L2,[],Lc).

common([],_,Acc,Acc).
common(_,[],Acc,Acc).

common([H|T],L,Acc,Lc):-
    member(H,L),\+member(H,Acc),common(T,L,[H|Acc],Lc).

common([H|T],L,Acc,Lc):-
    \+member(H,L),common(T,L,Acc,Lc).

common([H|T],L,Acc,Lc):-
    member(H,L),member(H,Acc),common(T,L,Acc,Lc).

/*****************/

common1(L1,L2,Lc):-
    setof(X,(member(X,L1),member(X,L2)),Lc).

common1(L1,L2,Lc):-
    \+setof(X,(member(X,L1),member(X,L2)),Lc),
    Lc = [].
    

/*******************/


common2([],_,[]).

common2([H1|T1],L2,Lc):-
    findall(L,setof(H1,member(H1,L2),L),Element),
    common2(T1,L2,Lct),
    append(Lct,Element,Lc).

/*****************/

common3(L1,L2,Lc):-
    common3(L1,L2,[],Lc).

common3([],_,Acc,Lc):-
    setof(X,member(X,Acc),Lc).

common3([],_,Acc,Lc):-
    \+setof(X,member(X,Acc),Lc),
    Lc = [].

common3([H1|T1],L2,Acc,Lc):-
    member(H1,L2),
    common3(T1,L2,[H1|Acc],Lc).

common3([H1|T1],L2,Acc,Lc):-
    \+member(H1,L2),
    common3(T1,L2,Acc,Lc).

/*********************/

delete([],[]).
delete([X],[X]).
delete([H,_|T1],[H|T2]):-
    delete(T1,T2).

/****************/

split(L,N,L1,L2):-
    append(L1,L2,L),length(L1,N).

/*****************/

process(L1,L2,C,I):-
    process(L1,L2,C,[],I,[]).

process([],L2,C,C,I,AccI):-append(AccI,L2,I).

process([(X,Y)|T1],L2,C,AccC,I,AccI):-
    append(B,[(X,Y,Z)|E],L2),
    append(AccC,[(X,Y,Z)],AccCNew),
    append(B,E,L2New),
    process(T1,L2New,C,AccCNew,I,AccI).

process([(X,Y)|T1],L2,C,AccC,I,AccI):-
    \+append(_,[(X,Y,Z)|_],L2),
    append(AccI,[(X,Y)],AccINew),
    process(T1,L2,C,AccC,I,AccINew).

/***********************/

process2(L1,L2,C,I):-
    process2(L1,L2,[],[],C,I).

process2(_,[],C,I,C,I).

process2(L1,[(X,Y,Z)|T],C1,I1,C,I):-
    member((X,Y),L1),
    process2(L1,T,[(X,Y)|C1],I1,C,I).

process2(L1,[(X,Y,Z)|T],C1,I1,C,I):-
    \+member((X,Y),L1),
    process2(L1,T,C1,[(X,Y)|I1],C,I).

/***********************/

drop(L,N,Result):-
    drop_helper(L,N,[],Result).


drop_helper([],_,Result,Result).
drop_helper(L,N,Acc,Result):- length(L,Y), Y < N, append(Acc,L,Result).

drop_helper(L,N,Acc,Result):-
    Z is N - 1,
    split(L,Z,L1,[_|T]),
    append(Acc,L1,Accnew),
    drop_helper(T,N,Accnew,Result).

/**********************/

drop2(L, N, Result) :-
    N > 0,
( N1 is N - 1, length(Begin, N1), append(Begin, [_|Rest], L) ->
drop2(Rest, N, RestNew), append(Begin, RestNew, Result)
  ;
Result = L
).

/*******************/

enrolment([H1|_],S,D):-
    in_list(Hl,S,D).

enrolment([Hl|Tl],S,D):-
    \+in_list(Hl,S,D),enrolment(Tl,S,D).


in_list([H,H2|T],S,H):-
    member(S,H2).

/*********************/

enrolement2([(D,List)|T],S,D):-
    member(S,List).

enrolment2([(D,List)|T],S,D):-
    \+member(S,List),
    enrolemnt2(T,S,D).

/*********************/

student_list(L,Meng,Msc):-
    student_list(L,[],[],Meng,Msc).

student_list([],X,Y,X,Y).

student_list([(Course,L)|T],Acc1,Acc2,Meng,Msc):-
    Course = 'meng', student_list(T,[L|Acc1],Acc2,Meng,Msc).

student_list([(Course,L)|T],Acc1,Acc2,Meng,Msc):-
    Course = 'msc', student_list(T,Acc1,[L|Acc2],Meng,Msc).

/************************

student_list([H|T],Meng,Msc):-
    student_list_helper([H|T],[],Meng,[],Msc).

student_list_helper([],X,X,Y,Y).

student_list_helper([H|T],Acc1,Meng,Acc2,Msc):-
    is_Meng(H,List),
    append(Acc1,List,Acc1next),
    student_list_helper(T,Acc1next,Meng,Acc2,Msc).

student_list_helper([H|T],Acc1,Meng,Acc2,Msc):-
    is_Msc(H,List),
    append(Acc2,List,Acc2next),
    student_list_helper(T,Acc1,Meng,Acc2next,Msc).

is_Meng([H,H2|T],H2):-
    H = 'meng'.

is_Msc([H,H2|T],H2):-
    H = 'msc'.
    */
