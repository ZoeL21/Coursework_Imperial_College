/*base case*/
combine1([],[],[]).
combine1([X],[Y],[X,Y]).
combine1([Ha,H2a|La],[Hb,H2b|Lb],[Ha,Hb|Lc]):-
    combine1([H2a|La],[H2b|Lb],Lc).
