
sigma(X,_):- X < 0.
sigma(0,0).
sigma(X,Y):-
    Z is X - 1,sigma(Z,Yt),Y is X + Yt.
    



    
    
