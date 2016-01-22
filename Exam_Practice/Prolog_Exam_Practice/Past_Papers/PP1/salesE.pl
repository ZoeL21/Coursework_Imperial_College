sellsFor('Peter Jones',swan123,28).
sellsFor('Peter Jones',electrolux214,27).

sellsFor('Peter Jones',hoover02,60).
sellsFor('Peter Jones',electrolux09,70).

sellsFor('Harrods', electrolux214, 31).
sellsFor('Harrods', swan123, 30).

sellsFor('Harrods', hoover02, 65).
sellsFor('Harrods', electrolux09, 80).

inStock('Peter Jones',electrolux214).
inStock('Peter Jones',hoover02).
inStock('Peter Jones',electrolux09).

inStock('Harrods',swan123).
inStock('Harrods',electrolux09).

locatedIn('Peter Jones',london).
locatedIn('Harrods',london).
    

typeOfItem(swan123,electricKettle).
typeOfItem(electrolux214,electricKettle).
typeOfItem(hoover02, vacuum_cleaner).     
typeOfItem(electrolux09, vacuum_cleaner).        

equivalentItems(electrolux214,swan123).
equivalentItems(electrolux09,hoover02).



forall(C1,C2) :- \+ ((C1,\+C2)).



sellsOneForLessThan(T,MP,S,I,P):-
    typeOfItem(I,T),sellsFor(S,I,P), MP > P.

equivalent(I1,I2):-
    typeOfItem(I2,T),typeOfItem(I1,T),I1 \= I2.

sellsEquivalentItemIn(I,C,EI,S):-
    locatedIn(S,C),inStock(S,I),EI = I.

sellsEquivalentItemIn(I,C,EI,S):-
    locatedIn(S,C), equivalent(I,EI), inStock(S,EI), sellsFor(S,I,Pi),
    sellsFor(S,EI,Pei),Pei=<Pi.

neverUnderSold(S,C):-
    locatedIn(S,C),
    forall(sellsFor(S,I,P), \+ (sellsFor(X,I,Px),Px < P)).

listOfSuppliersFor(I,C,L):-
    setof((P,S),(sellsFor(S,I,P),inStock(S,I),locatedIn(S,C)),L).
