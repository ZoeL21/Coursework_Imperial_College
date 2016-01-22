

   byCar(auckland,hamilton).
   byCar(hamilton,raglan).
   byCar(valmont,saarbruecken).
   byCar(valmont,metz).
   
   byTrain(metz,frankfurt).
   byTrain(saarbruecken,frankfurt).
   byTrain(metz,paris).
   byTrain(saarbruecken,paris).
   
   byPlane(frankfurt,bangkok).
   byPlane(frankfurt,singapore).
   byPlane(paris,losAngeles).
   byPlane(bangkok,auckland).
   byPlane(singapore,auckland).
   byPlane(losAngeles,auckland). 

travel(X,Y):-byCar(X,Y);byTrain(X,Y);byPlane(X,Y).
travel(X,Y):-(byCar(X,Z);byTrain(X,Z);byPlane(X,Z)),travel(Z,Y).

travel(X,Y,N):-(byCar(X,Y),N = gobyCar(X,Y));(byTrain(X,Y),gobyTrain(X,Y));(byPlane(X,Y),N = gobyPlane(X,Y)).

travel(X,Y,N):-byCar(X,Z),travel(Z,Y,M),N = gobyCar(X,Z,M).
travel(X,Y,N):-byTrain(X,Z),travel(Z,Y,M),N = gobyTrain(X,Z,M).
travel(X,Y,N):-byPlane(X,Z),travel(Z,Y,M),N = gobyPlane(X,Z,M).
