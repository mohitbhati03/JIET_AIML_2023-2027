% Facts: parent relationships
parent(john, mary).  % John is a parent of Mary
parent(susan, mary). % Susan is a parent of Mary
parent(john, mike).  % John is a parent of Mike
parent(susan, mike). % Susan is a parent of Mike
parent(mary, alice). % Mary is a parent of Alice
parent(jack, alice). % Jack is a parent of Alice

% Rules
% X is a father of Y
father(X, Y) :-
    parent(X, Y),
    male(X).

% X is a mother of Y
mother(X, Y) :-
    parent(X, Y),
    female(X).

% X is a sibling of Y
sibling(X, Y) :-
    parent(P, X),
    parent(P, Y),
    X \= Y.

% X is a grandparent of Y
grandparent(X, Y) :-
    parent(X, Z),
    parent(Z, Y).

% X is a grandchild of Y
grandchild(X, Y) :-
    grandparent(Y, X).

% X is an ancestor of Y
ancestor(X, Y) :-
    parent(X, Y).
ancestor(X, Y) :-
    parent(X, Z),
    ancestor(Z, Y).

% Gender information
male(john).
male(mike).
male(jack).
female(susan).
female(mary).
female(alice).

% Example Queries:
% ?- father(john, mary).
% ?- sibling(mike, mary).
% ?- grandparent(john, alice).
% ?- ancestor(john, alice).
