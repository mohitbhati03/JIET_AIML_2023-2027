% Facts: Food categories and ingredients
food_category(fruit, [apple, banana, mango, orange]).
food_category(vegetable, [carrot, broccoli, spinach, potato]).
food_category(dairy, [milk, cheese, yogurt, butter]).
food_category(meat, [chicken, beef, pork, lamb]).
food_category(grain, [rice, wheat, oats, barley]).

% Rules
% Check if X is a food item in category Y
is_food_in_category(X, Y) :-
    food_category(Y, Items),
    member(X, Items).

% Get all items in a category
list_food_in_category(Category, Items) :-
    food_category(Category, Items).

% Find the category of a given food
find_category_of_food(Food, Category) :-
    food_category(Category, Items),
    member(Food, Items).

% Example Queries:
% ?- is_food_in_category(apple, fruit).
% ?- list_food_in_category(dairy, Items).
% ?- find_category_of_food(carrot, Category).
