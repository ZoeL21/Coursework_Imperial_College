childofMum(bridget,carolina).
childofMum(carolina,donna).
childofMum(donna,emilie).
childofMum(emilie,erica).

/*best slution*/
descendant1(X,Y):-childofMum(X,Y).
descendant1(X,Y):-childofMum(X,Z),descendant1(Z,Y).

/*works as well*/
descendant2(X,Y):-childofMum(Z,Y),descendant2(X,Z).
descendant2(X,Y):-childofMum(X,Y).

/*loops infinitely*/
descendant3(X,Y):-descendant3(Z,Y),childofMum(X,Z).
descendant3(X,Y):-childofMum(X,Y).

/*works sometimes*/
descendant4(X,Y):-childofMum(X,Y).
descendant4(X,Y):-descendant4(Z,Y),childofMum(X,Z).

/*works sometimes but not properly, won't work if X is not a descendant of Y*/
descendant5(X,Y):-childofMum(X,Y).
descendant5(X,Y):-descendant5(X,Z),descendant5(Z,Y).
