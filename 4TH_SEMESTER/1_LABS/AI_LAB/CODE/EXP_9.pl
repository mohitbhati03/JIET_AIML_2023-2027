% Define the possible moves in the water jug problem
move(state(X, Y), state(MaxX, Y), MaxX, _) :-
    X < MaxX, write('Fill Jug 1'), nl. % Fill Jug 1

move(state(X, Y), state(X, MaxY), _, MaxY) :-
    Y < MaxY, write('Fill Jug 2'), nl. % Fill Jug 2

move(state(X, Y), state(0, Y), _, _) :-
    X > 0, write('Empty Jug 1'), nl. % Empty Jug 1

move(state(X, Y), state(X, 0), _, _) :-
    Y > 0, write('Empty Jug 2'), nl. % Empty Jug 2

% Pour water from Jug 1 to Jug 2
move(state(X, Y), state(NewX, MaxY), _, MaxY) :-
    X > 0, TotalY is X + Y, TotalY > MaxY,
    NewX is TotalY - MaxY, write('Pour Jug 1 -> Jug 2 (Overflow)'), nl.

move(state(X, Y), state(0, TotalY), _, MaxY) :-
    X > 0, TotalY is X + Y, TotalY =< MaxY,
    write('Pour Jug 1 -> Jug 2'), nl.

% Pour water from Jug 2 to Jug 1
move(state(X, Y), state(MaxX, NewY), MaxX, _) :-
    Y > 0, TotalX is X + Y, TotalX > MaxX,
    NewY is TotalX - MaxX, write('Pour Jug 2 -> Jug 1 (Overflow)'), nl.

move(state(X, Y), state(TotalX, 0), MaxX, _) :-
    Y > 0, TotalX is X + Y, TotalX =< MaxX,
    write('Pour Jug 2 -> Jug 1'), nl.

% Solve the problem using BFS to avoid cycles
solve_water_jug(MaxX, MaxY, Z) :-
    bfs([state(0, 0)], [], MaxX, MaxY, Z).

bfs([state(X, Y) | _], _, _, _, Z) :-
    (X =:= Z; Y =:= Z),
    write('Goal Reached: '), write(state(X, Y)), nl, !.

bfs([State | Rest], Visited, MaxX, MaxY, Z) :-
    \+ member(State, Visited), % Avoid revisiting states
    findall(NextState, (move(State, NextState, MaxX, MaxY), \+ member(NextState, Visited)), NextStates),
    append(Rest, NextStates, Queue),
    bfs(Queue, [State | Visited], MaxX, MaxY, Z).

bfs([], _, _, _, _) :-
    write('No Solution Found'), nl, fail.


%?- solve_water_jug(4, 3, 2).
%Fill Jug 1
%Fill Jug 2
%Fill Jug 2
%Empty Jug 1
%Pour Jug 1 -> Jug 2 (Overflow)
%Fill Jug 1
% Empty Jug 2
%Pour Jug 2 -> Jug 1
%Empty Jug 1
%Empty Jug 2
%Pour Jug 1 -> Jug 2 (Overflow)
%Pour Jug 2 -> Jug 1 (Overflow)
%Fill Jug 1
%Empty Jug 1
%Empty Jug 2
%Pour Jug 1 -> Jug 2 (Overflow)
%Pour Jug 2 -> Jug 1
%false.
