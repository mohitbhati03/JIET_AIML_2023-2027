% Define a triangle with three sides
triangle(A, B, C) :-
    A > 0, B > 0, C > 0,           % Sides should be positive
    A + B > C, A + C > B, B + C > A. % Triangle inequality rule

% Define a square with a given side length
square(S) :-
    S > 0.  % Side length should be positive

% Define a circle with a given radius
circle(R) :-
    R > 0.  % Radius should be positive

% Example queries:
% ?- triangle(3, 4, 5).   % Should return true for a valid triangle
% ?- square(4).           % Should return true for a valid square
% ?- circle(5).           % Should return true for a valid circle
