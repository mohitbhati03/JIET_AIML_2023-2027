% Define a point
point(Name, X, Y) :-
    atom(Name),
    number(X),
    number(Y).

% Define a line segment
line_segment(Name, Point1, Point2) :-
    atom(Name),
    Point1 =.. [point, Name1, X1, Y1],
    Point2 =.. [point, Name2, X2, Y2],
    point(Name1, X1, Y1),
    point(Name2, X2, Y2),
    Name1 \= Name2.

% Calculate the length of a line segment
line_length(line_segment(_, Point1, Point2), Length) :-
    Point1 =.. [point, _, X1, Y1],
    Point2 =.. [point, _, X2, Y2],
    Length is sqrt((X2 - X1) ** 2 + (Y2 - Y1) ** 2).

% Check if two line segments are parallel
parallel(line_segment(_, Point1A, Point2A), line_segment(_, Point1B, Point2B)) :-
    Point1A =.. [point, _, X1A, Y1A],
    Point2A =.. [point, _, X2A, Y2A],
    Point1B =.. [point, _, X1B, Y1B],
    Point2B =.. [point, _, X2B, Y2B],
    (X2A - X1A) * (Y2B - Y1B) =:= (X2B - X1B) * (Y2A - Y1A).

% Check if a point lies on a line segment
point_on_segment(point(_, Px, Py), line_segment(_, Point1, Point2)) :-
    Point1 =.. [point, _, X1, Y1],
    Point2 =.. [point, _, X2, Y2],
    Area is abs((X2 - X1) * (Py - Y1) - (Px - X1) * (Y2 - Y1)),
    Area =:= 0,
    Px >= min(X1, X2), Px =< max(X1, X2),
    Py >= min(Y1, Y2), Py =< max(Y1, Y2).

% Example Queries:
% Define points:
% ?- point(p1, 0, 0).
% ?- point(p2, 3, 4).
% Define line segments:
% ?- line_segment(l1, point(p1, 0, 0), point(p2, 3, 4)).
% Calculate length of a line:
% ?- line_length(line_segment(l1, point(p1, 0, 0), point(p2, 3, 4)), Length).
% Check if segments are parallel:
% ?- parallel(line_segment(l1, point(p1, 0, 0), point(p2, 3, 4)), line_segment(l2, point(p3, 1, 1), point(p4, 4, 5))).
% Check if a point lies on a segment:
% ?- point_on_segment(point(p5, 1.5, 2), line_segment(l1, point(p1, 0, 0), point(p2, 3, 4))).
