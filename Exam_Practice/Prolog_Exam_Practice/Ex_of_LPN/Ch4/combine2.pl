combine2([],[],[]).
combine2([X],[Y],[[X,Y]]).
combine2([Ha,H2a|Ta],[Hb,H2b|Tb],[[Ha,Hb]|Tc]):-
    combine2([H2a|Ta],[H2b|Tb],Tc).
