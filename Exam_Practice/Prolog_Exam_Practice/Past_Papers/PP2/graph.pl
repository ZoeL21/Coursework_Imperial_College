


/*
merge_ordered(Left,Right,Merged):-
    merge_ordered(Left,Right,[],Merged).

merge_ordered([],Right,Acc,Merged):-
    append(Acc,Right,Acc2),
    setof(X,member(X,Acc2),Merged).

merge_ordered(Left,[],Acc,Merged):-
    append(Acc,Left,Acc2),
    setof(X,member(X,Acc2),Merged).

*/

merge_ordered(Left,Right,Merged):-
    append(Left,Right,Full),
    setof(X,member(X,Full),Merged).


/**********/

hf_to_graph_term(Hform,Graph):-
    hf_to_graph_term(Hform,[],[],Graph).

hf_to_graph_term([],Nodes,Edges,[Nodes,Edges]).
   
hf_to_graph_term([X > Y | T],Nodes,Edges,Graph):-
    sort([X,Y],[U,V]),
    merge_ordered([U,V],Nodes,NodesNew),
    merge_ordered([e(U,V)],Edges,EdgesNew),   
    hf_to_graph_term(T,NodesNew,EdgesNew,Graph).

hf_to_graph_term([X > X | T],Nodes,Edges,Graph):-
    merge_ordered([X],Nodes,NodesNew),
    merge_ordered([e(X,X)],Edges,EdgesNew),
    hf_to_graph_term(T,NodesNew,EdgesNew,Graph).

hf_to_graph_term([X| T],Nodes,Edges,Graph):-
    atom(X),
    merge_ordered([X],Nodes,NodesNew),
    hf_to_graph_term(T,NodesNew,Edges,Graph).



/**************/

graph_term_to_adj_list(([],_),[]).

graph_term_to_adj_list(([Hn|Tn],Edges),AdjList):-
    graph_term_to_adj_list((Tn,Edges),AdjListNew),
    find_adj(Hn,Edges,[],An),
    append(AdjListNew,[n(Hn,An)],AdjList).
    
find_adj(Hn,[],An,An).

find_adj(Hn,[e(Hn,N)|T],Acc,An):-
    find_adj(Hn,T,[N|Acc],An).

find_adj(Hn,[e(N,Hn)|T],Acc,An):-
    find_adj(Hn,T,[N|Acc],An).

find_adj(Hn,[e(X,Y)|T],Acc,An):-
    X \= Hn, Y \= Hn,
    find_adj(Hn,T,Acc,An).
