/*version with accumulator*/
palindrome([H|T]):-
    palindrome_helper([H|T],[],[H|T]).

palindrome_helper([],L,L).

palindrome_helper([H|T],Acc,L):-
    palindrome_helper(T,[H|Acc],L).


/*version with append*/
palindrome2([H|T]):-
    palindrome2_helper([H|T],R),
    [H|T] = R.

palindrome2_helper([],[]).

palindrome2_helper([H|T],R):-
    palindrome2_helper(T,Rt),append(Rt,[H],R).
