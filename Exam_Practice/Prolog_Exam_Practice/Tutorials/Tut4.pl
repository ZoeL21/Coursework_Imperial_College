/*****/

article(a).
article(the).
article(an).

noun(grass).
noun(cow).
noun(sky).
noun(girl).
noun(boys).
noun(cows).

verb(eats).
verb(kicks).
verb(walks).
verb(sleeps).

/*****/

sentence(X):-
    nounphrase(Np),verbphrase(Vp),append(Np,Vp,X).

nounphrase(X):-
    article(A),noun(B),append([A],B,X).

verbphrase(X):-
    verb(V),nounphrase(Np),append([V],Np,X).

/**********/

sentence_better(X):-
    nounphrase(Np),verbphrase_single(Vp),append(Np,Vp,X).

sentence_better(X):-
    nounphrase_plural(Np),verbphrase(Vp),append(Np,Vp,X).

verbphrase_single(X):-
    verb(V), atom_chars(V,Va), append(B,E,Va), E = 's',
    nounphrase(Np),append(V,Np,X).

nounphrase_plural(X):-
    article(A),noun(N),
    atom_chars(N,Na), append(B,E,Na), E = 's',
    append(A,N,X).

/********/
