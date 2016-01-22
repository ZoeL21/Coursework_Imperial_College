/*there is a street with 3 neighbouring houses*/
street = [L_house,M_house,R_house].

/*there are 3 possible colours*/
colours = [blue,green,red].

/*there are 3 families of different nationalities*/
nat = [Japanese,Spanish,English].

/*there are 3 pets*/
pets = [snail,jaguar,zebra].

/*every house is a house on the street and has a colour of colours.
it also has a family and a pet*/
house(X,C,F,P):-member(X,street),member(C,colours),member(F,nat),member(P,pets).

house1(

/*position contraints*/
rightof(X,Y):- X = R_house, Y = M_house.
rightof(X,Y):- X = M_house, Y = L_house. 

leftof(X,Y):- X = L_house, Y = M_house.
leftof(X,Y):- X = M_house, Y = R_house.

zebra(owner):-owns(family(owner),zebra).
snail(owner):-owns(family(owner),snail).
jaguar(owner):-owns(family(owner),jaguar).

lives_in(English,red).
owns(Spanish,jaguar).
rightof(Japanese,F):-snail(F).
leftof(F1,F2):-snail(F1),lives_in(F2,X),X=blue.


lives_in(X,Y):-nationality(X),house_colour(Y).
