tran(eins,one).
tran(zwei,two).
tran(drei,three).
tran(vier,four).
tran(fuenf,five).
tran(sechs,six).
tran(sieben,seven).
tran(acht,eight).
tran(neun,nine).

listtran([],[]).

listtran([X],[Y]):-tran(X,Y);tran(Y,X).

listtran([H1g,H2g|Lg],[H1e,H2e|Le]):-
    tran(H1g,H1e),tran(H2g,H2e),listtran(Lg,Le).
