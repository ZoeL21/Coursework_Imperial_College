

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


    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    

age(amy, 6).

age(arthur, 15).

age(angel, 16).

age(anton, 4).
    
age(alan, 8).
    
age(axel, 16).
    
age(ann, 4).



% employed(X) means X is employed.
    

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

    
employed(susan).
employed(rita).
    



/*i)*/

ecb(M):-child_mother(C,M),age(C,A),A=<14.
ecb(M):-child_mother(C,M),\+employed(M),age(C,A),A>14,A=<16.


/*ii)*/

mother_of_the_youngest(M):-
    setof(M,C^child_mother(C,M),[Hlom|LoM]),
    child_mother(C1,Hlom),
    age(C1,Age),
    find_youngest(LoM,Age,Hlom,M).
    

/*auxiliary predicate*/
/*base case*/
find_youngest([],_,M,M).

/*case where current age is younger*/
find_youngest([H|T],Age,Mcurrent,M):-
    setof(A,H^C^(child_mother(C,H),age(C,A)),[Ha|Tc]),
    Ha<Age,
    find_youngest(T,Ha,H,M).

/*case where current age is older or equal*/
find_youngest([H|T],Age,Mcurrent,M):-
    setof(A,H^C^(child_mother(C,H),age(C,A)),[Ha|Tc]),
    Ha>=Age,
    find_youngest(T,Age,Mcurrent,M).


/*iii)*/

mothers_of_young(LM):-
    setof(M,C^A^(child_mother(C,M),age(C,A),A =< 10),LM).


/*2*/

merge(L1,[],L1).
merge([],L2,L2).
    
merge(L1,L2,L):-
    merge_acc(L1,L2,[],L).

merge_acc([],L2,Acc,L):-append(Acc,L2,L).
merge_acc(L1,[],Acc,L):-append(Acc,L1,L).

merge_acc([H1|T1],[H2|T2],Acc,L):-
    H1>H2,append(Acc,[H2,H1|[]],AccNew),merge_acc(T1,T2,AccNew,L).

merge_acc([H1|T1],[H2|T2],Acc,L):-
    H1=<H2,append(Acc,[H1,H2|[]],AccNew),merge_acc(T1,T2,AccNew,L).

   
