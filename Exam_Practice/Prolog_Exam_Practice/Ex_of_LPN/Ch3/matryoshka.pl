directlyIn(katarina,olga).
directlyIn(olga,natasha).
directlyIn(natasha,irina).
directlyIn(irina,helena).
directlyIn(helena,paula).


in(X,Y):-directlyIn(X,Y).
in(X,Y):-directlyIn(X,Z),in(Z,Y).
