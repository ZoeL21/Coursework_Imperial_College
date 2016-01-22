xorgate(g1).
xorgate(g2).
andgate(g3).
andgate(g4).
orgate(g5).

inputone(1).
inputtwo(0).
inputthree(1).

input1(g1,X):-inputone(X).
input2(g1,X):-inputtwo(X).



input1(g4,X):-inputone(X).
input2(g4,X):-inputtwo(X).



output(G,1):-andgate(G),input1(G,1),input2(G,1).



output(G,1):-xorgate(G),((input1(G,1),input2(G,0));(input1(G,0),input2(G,1))).




output(G,1):-orgate(G),(input1(G,1);input2(G,1)).


input1(g5,X):-output(g3,X).
input2(g5,X):-output(g4,X).

input1(g3,X):- output(g1,X).
input2(g3,X):- inputthree(X).

input1(g2,X):-output(g1,X).
input2(g2,X):-inputthree(X).

