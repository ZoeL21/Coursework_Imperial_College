combine3([],[],[]).
combine3([X],[Y],j(X,Y)).
combine3([Ha,H2a|Ta],[Hb,H2b|Tb],[X|Tc]):-
    combine3([H2a|Ta],[H2b|Tb],Tc),X = j(Ha,Hb).
