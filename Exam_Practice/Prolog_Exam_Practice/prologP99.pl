
/****last element of a list****/

last([X],X).
last([H|T],E):-
    last(T,E).


/***********************************/

/***second last element****/

second_last([X|_],X).
second_last([H|T],E):-
    second_last(T,E).

/************************************/

/*find Kth element*/

findElement(E,L,N):-
    append(Beg,[E|End],L),
    Nl is N - 1,
    length(Beg,Nl).


/*************************************/

/*find number of elements*/

number_of_el([],0).
number_of_el(L,E):-
    number_of_el([H|T],En),
    E is En + 1.
    
/***********************************/

/*reverse a list*/

reverse([],Acc,Acc).
reverse(L,R):-
    reverse(L,Acc,R).

reverse([H|T],Acc,R):-
    reverse(T,[H|Acc],R).

/*********************************/

/*check if list is a palindrome*/

palindrome(L):-
    length(L,Lng),
    Half is truncate(Lng/2),
    append(Beg,[M|End],L),
    length(Beg,Half),
    length(End,Half),
    reverse(End,End_rev),
    Beg = End_rev.

/*********************************/

/*Flatten a list*/


flatten(L,Lf):-
    flatten(L,[],Lf).

flatten([],Acc,Acc).

flatten([H|T],Acc,Lf):-

    (atomic(H)),
    append(Acc,[H],Accnew),
    flatten(T,Accnew,Lf).


flatten([H|T],Acc,Lf):-
    
    \+(atomic(H)),
    flatten_head(H,[],Hf),
    append(Acc,Hf,Accnew),
    flatten(T,Accnew,Lf).

flatten_head([X],Acc,Hf):-
    (atomic(X)),
    append(Acc,[X],Hf).

flatten_head([X],Acc,Hf):-
    \+(atomic(X)),
    flatten_head(X,Acc,Hf).

flatten_head([H|T],Acc,Hf):-
    (atomic(H)),
    append(Acc,[H],Accnew),
    flatten_head(T,Accnew,Hf).

fatten_head([H|T],Acc,Hf):-
    \+(atomic(H)),
    flatten_head(H,Acc,Hf).

/*******************************/

% P7 Flatten a list of lists
my_flatten([], []) :- !.

my_flatten([H|T], X) :-
    !,
    my_flatten(H, H_New),
    my_flatten(T, T_New),
    append(H_New, T_New, X).
    
my_flatten(L, [L]).

/*
% Tail recursive
my_flatten2(L, X) :-
    my_flatten2(L, [], X).

my_flatten2([], Acc, Acc).
my_flatten2([L|Ls], Acc, X) :-
    (
        is_list(L)
        ->
            my_flatten2(L, L1),
            append(Acc, L1, NewAcc),
            my_flatten2(Ls, NewAcc, X)
     ;
            append(Acc, [L], NewAcc),
            my_flatten2(Ls, NewAcc, X)
    ).
*/
/*Eliminate consecutive duplicates*/


no_dup([X,Y|[]],[X,Y]):-
    X \= Y.
    
no_dup([X,X|[]],[X]).

no_dup([X,X|T1],[H|T2]):-
    no_dup([X|T1],[H|T2]).

no_dup([X,Y|T1],[X|T2]):-
    X \= Y,
    no_dup([Y|T1],T2).


/******************************/


dup_to_sub(L,Ln):-
   dup_to_sub(L,[],[],Ln).

dup_to_sub([X,X|[]],Acc,Ltemp,Ln):-
    append(Acc,[X,X|[]],Accnew),
    append(Ltemp,[Accnew],Ln).

dup_to_sub([X,Y|[]],Acc,Ltemp,Ln):-
    X \= Y,
    append(Acc,[X],Accnew),
    append(Ltemp,[Accnew],Lnew),
    append(Lnew,[[Y]],Ln).

dup_to_sub([X,X|T1],Acc,Ltemp,Ln):-
    append(Acc,[X],Accnew),
    dup_to_sub([X|T1],Accnew,Ltemp,Ln).

dup_to_sub([X,Y|T1],Acc,Ltemp,Ln):-
    X \= Y,
    append(Acc,[X],Accnew),
    append(Ltemp,[Accnew],Lnnew),
    dup_to_sub([Y|T1],[],Lnnew,Ln).

/*******************************/

rl_encode(L,Lrl):-
    dup_to_sub(L,Lsub),
    rl_enc(Lsub,Lrl).

rl_enc([X],[[Len,E]|[]]):-
    length(X,Len),
    get_el(X,E).

rl_enc([H1,H2|T],[[Len,E]|Tacc]):-
    length(H1,Len),
    get_el(H1,E),
    rl_enc([H2|T],Tacc).

get_el([H|T],H).
    
/********************************/

mod_encode(L,Lr):-
    dup_to_sub(L,Lsub),
    mod_enc(Lsub,Lr).

mod_enc([X],X):-
    length(X,1).

mod_enc([X],[[Len,E]|[]]):-
    length(X,Len),
    Len \= 1,
    get_el(X,E).

mod_enc([H1,H2|T],[[Len,E]|Tacc]):-
    length(H1,Len),
    Len \= 1,
    get_el(H1,E),
    mod_enc([H2|T],Tacc).

mod_enc([H1,H2|T],[E|Tacc]):-
    length(H1,1),
    get_el(H1,E),
    mod_enc([H2|T],Tacc).

/*******************************/

decode(L,Ld):-
    decode(L,[],Ld).

decode([],Ld,Ld).

decode([H1|T],Acc,Ld):-
    atomic(H1),
    append(Acc,[H1],Accnew),
    decode(T,Accnew,Ld).

decode([[N,E]|T],Acc,Ld):-
    add_el(N,E,[],L),
    append(Acc,L,Accnew),
    decode(T,Accnew,Ld).

add_el(0,E,L,L).
add_el(N,E,Acc,L):-
    N > 0,
    Nn is N - 1,
    append(Acc,[E],Accnew),
    add_el(Nn,E,Accnew,L).

/*******************************/

enc_dir(L,Lenc):-
    enc_dir(L,[],Lenc).

enc_dir([X,Y|[]],Acc,[Accnew,Y|[]]):-
    X \= Y,
    append(Acc,X,Accnew).

enc_dir([X,X|[]],Acc,[Accnew|[]]):-
    append(Acc,[2,X|[]],Accnew).

enc_dir([X,X|T],Acc,Lenc):-
    append(Acc,[X],Accnew),
    enc_dir([X|T],Accnew,Lenc).

enc_dir([X,Y|T],Acc,[Accnew|Lenc]):-
    X \= Y,
    length(Acc,Len),Len \= 0,
    L is Len + 1,
    append([L],[X],Accnew),
    enc_dir([Y|T],[],Lenc).

enc_dir([X,Y|T],Acc,[X|Lenc]):-
    X \= Y,
    Acc = [],
    enc_dir([Y|T],Acc,Lenc).
    
    
/*******************************/

dup([],[]).
dup([H|T1],[H,H|T2]):-
    dup(T1,T2).

/*********************************/

dup_num(L,N,Ld):-
    dup_num(L,N,N,Ld).

dup_num([],_,_,[]).

dup_num([H|T1],Ns,1,[H|T2]):-
    
    dup_num(T1,Ns,Ns,T2).

dup_num([H|T1],Ns,N,[H|T2]):-
    N > 1,
    Nnext is N - 1,
    dup_num([H|T1],Ns,Nnext,T2).
    
/********************************/

drop_N(L,N,Ln):-
    length(L,Len),
    (Len > N ->
        (Nbeg  is N - 1,
        append(Beg,[X|End],L),
        length(Beg,Nbeg),
        drop_N(End,N,Nextpart),
        append(Beg,Nextpart,Ln))
     ;
        (Ln = L)
    )
    .

/*****************************/

split(L,N,L1,L2):-
    append(L1,L2,L),
    length(L1,N).

/***************************/

slice(L,B,E,Slice):-
    D is E - B + 1,
    Bn is B - 1,
    append(Beg,Slice,Temp),
    append(Temp,End,L),
    length(Beg,Bn),
    length(Slice,D).

/*************************/

rotate(L,N,R):-
    append(Beg,Rest,L),
    length(Beg,N),
    append(Rest,Beg,R).

/*******************************/
remove_el(L,K,Ln):-
    append(Beg,[X|End],L),
    Kb is K - 1,
    length(Beg,Kb),
    append(Beg,End,Ln).

/******************************/

insert_el(E,L,N,Le):-
    append(Beg,End,L),
    Nn is N - 1,
    length(Beg,Nn),
    append(Beg,[E|End],Le).

/******************************/
create(B,E,L):-
    atomic(B),
    atomic(E),
    create_List([B],B,E,L).

create_List(Lso_far,Count,Count,Lso_far).

create_List(Lso_far,Count,End,L):-
    Count < End,
    El_new is Count + 1,
    append(Lso_far,[El_new],Lnew),
    create_List(Lnew,El_new,End,L).

/****************************/
