% Medical Diagnosis Expert System

% Start diagnosis
diagnose :-
    write('Welcome to the Medical Diagnosis Expert System!'), nl,
    write('Please answer the following questions with yes or no.'), nl,
    find_disease(Disease),
    write('Based on your symptoms, you may have: '), write(Disease), nl, !.

% Check disease based on symptoms
find_disease(flu) :-
    symptom(fever),
    symptom(cough),
    symptom(sore_throat),
    symptom(body_ache),
    symptom(runny_nose),
    symptom(fatigue).

find_disease(common_cold) :-
    symptom(sneezing),
    symptom(runny_nose),
    symptom(sore_throat),
    symptom(mild_cough).

find_disease(covid_19) :-
    symptom(fever),
    symptom(cough),
    symptom(breathing_difficulty),
    symptom(loss_of_taste),
    symptom(loss_of_smell).

find_disease(malaria) :-
    symptom(fever),
    symptom(chills),
    symptom(sweating),
    symptom(headache),
    symptom(nausea).

find_disease(pneumonia) :-
    symptom(fever),
    symptom(cough),
    symptom(chest_pain),
    symptom(breathing_difficulty),
    symptom(fatigue).

% If no known disease is found
find_disease(unknown) :-
    write('Sorry, we could not determine your disease. Please consult a doctor.'), nl, fail.

% Ask user for symptoms
symptom(S) :-
    write('Do you have '), write(S), write('? (yes/no) '),
    read(Reply),
    Reply == yes.

% Start the expert system
start :-
    diagnose,
    write('Take care!').
