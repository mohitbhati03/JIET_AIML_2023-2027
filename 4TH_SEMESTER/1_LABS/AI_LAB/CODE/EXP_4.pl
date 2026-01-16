% Check if a list is empty
is_empty([]).

% Insert an element at the beginning of a list
insert_head(Element, List, [Element|List]).

% Insert an element at the end of a list
insert_end(Element, [], [Element]).  % Base case: inserting into an empty list
insert_end(Element, [H|T], [H|NewT]) :- insert_end(Element, T, NewT).

% Delete an element from a list
delete_element(_, [], []).  % Base case: empty list
delete_element(E, [E|T], T).  % Delete first occurrence
delete_element(E, [H|T], [H|NewT]) :- delete_element(E, T, NewT).

% Search for an element in a list
search_element(E, [E|_]).  % Found at the head
search_element(E, [_|T]) :- search_element(E, T).  % Continue searching in the tail

% Find the length of a list
list_length([], 0).  % Base case: empty list
list_length([_|T], N) :- list_length(T, N1), N is N1 + 1.

% Reverse a list
reverse_list([], []).  % Base case: empty list
reverse_list([H|T], Rev) :- reverse_list(T, RevT), append(RevT, [H], Rev).

% Example Queries:
% ?- insert_head(5, [1, 2, 3], L).  % Output: L = [5, 1, 2, 3]
% ?- insert_end(5, [1, 2, 3], L).   % Output: L = [1, 2, 3, 5]
% ?- delete_element(2, [1, 2, 3], L). % Output: L = [1, 3]
% ?- search_element(3, [1, 2, 3]). % Output: true
% ?- list_length([1, 2, 3, 4], N). % Output: N = 4
% ?- reverse_list([1, 2, 3], L).   % Output: L = [3, 2, 1]
