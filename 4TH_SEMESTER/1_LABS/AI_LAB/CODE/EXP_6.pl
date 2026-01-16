move(state(middle, onBox, middle, hasNot), grasp, state(middle, onBox, middle, has)).
move(state(P, onFloor, P, H), climb, state(P, onBox, P, H)).
move(state(P1, onFloor, P1, H), push(P1, P2), state(P2, onFloor, P2, H)).
move(state(P1, onFloor, B, H), walk(P1, P2), state(P2, onFloor, B, H)).

% Solution: find sequence of moves to reach goal
solve(state(_, _, _, has)).
solve(State1) :-
    move(State1, Move, State2),
    write('Monkey does: '), write(Move), nl,
    solve(State2).
