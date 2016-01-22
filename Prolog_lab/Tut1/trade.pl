sells(usa, grain, japan).
sells(S, P, R) :-  produces(S, P), needs(R, P).

produces(oman, oil).
produces(iraq, oil).
produces(japan, computers).
produces(germany, cars).
produces(france, iron).

needs(germany, iron).
needs(britain, cars).
needs(japan, cars).

/*Question 3*/
country(britain).
country(france).
country(japan).
/*another way of doing it would be to find common properties of all existing coountries*/

/*Question 2*/
country(X):- needs(X, computers).

needs(C, oil) :- needs(C, cars).

/*Question 4*/
needs(britain, coal).
needs(japan, coal).
needs(japan, diamonds).

/*Qiuestion 5*/
nat_res(france, coal).
nat_res(britain, coal).
nat_res(south_africa, diamonds).

/*Q5*/
ce(france, coal).
ce(south_africa, diamonds).

/*Question 8*/
mines(C1,I):-ce(C1,I).
exports(C1,I,C2):-(produces(C1,I);mines(C1,I)),(needs(C2,I)).
competition(C1,C2,I):-(exports(C1,I,_),exports(C2,I,_)),C1\=C2.
lower_price(I):-competition(_,_,I).
