/*first version*/
swapfl([Ha|Ta],Tb):-
    swapfl_helper(Ta,Tb,[],Ha).

swapfl_helper([X],Tb,Acc,First):-
    append([X],Acc,Accnext),
    append(Accnext,[First],Tb).

swapfl_helper([Ha|Ta],Tb,Acc,First):-
    append(Acc,[Ha],Accnext),
    swapfl_helper(Ta,Tb,Accnext,First).

/*nicer version*/
swapfl_better([Ha|Ta],S):-
    find_last(Ta,X),
    replace_last(Ha,Ta,Res),
    append([X],Res,S).


find_last([X],X).
find_last([_|T],X):-
    find_last(T,X).

replace_last(Ha,[_],[Ha]).
replace_last(Ha,[H|T],Res):-
    replace_last(Ha,T,Resnext),append([H],Resnext,Res).
