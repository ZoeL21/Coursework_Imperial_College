%Country(Country,Capital,Inhabitants_in_millions,Area_in_square_kilometers)
country('Sweden','Stockholm',9.3,449964).
country('Denmark','Copenhagen',5.5,43094).
country('Norway','Oslo',4.8,385199).
country('Finland','Helsinki',5.3,338145).
country('Iceland','Reykjavik',0.32,103125).
country('GreatBritain','London',60.6,244820).
country('Turkey','Ankara',71.5,783562).
country('Russia','Moscow',143.5, 17100000).


%Nordic_country(Country)
nordic_country('Sweden').
nordic_country('Norway').
nordic_country('Denmark').
nordic_country('Finland').
nordic_country('Iceland').

%National_day(Country,date(Day,Month))
national_day('Sweden',date(6,'June')).
national_day('Norge',date(17,'May')).
national_day('Finland',date(6,'December')).
national_day('Turkey',date(29,'October')).
national_day('Denmark',date(5,'June')).
national_day('GreatBritain',date(11,'June')).
national_day('Iceland',date(17,'June')).
national_day('Russia',date(12,'June')).

%Form_of_government(Country,Form)
form_of_government('Sweden',monarchy).
form_of_government('Norway',monarchy).
form_of_government('Finland',republic).
form_of_government('Denmark',monarchy).
form_of_government('GreatBritain',monarchy).
form_of_government('Iceland',republic).
form_of_government('Turkey',republic).
form_of_government('Russia', putin).

%Queen(Country,Name)
queen('Denmark','MargretheII').
queen('GreatBritain','ElisabethII').

%King(Country,Name)
king('Sweden','KarlXVIGustav').
king('Norway','HaraldV').
king('Russia', 'Vladimir').


%Flag(Country,Colour_list)
flag('Sweden',[blue,yellow]).
flag('Norway',[red,blue,white]).
flag('Finland',[blue,white]).
flag('Denmark',[red,white]).
flag('GreatBritain',[blue,white,red]).
flag('Russia',[white,blue,red]).


%Exercises:
%should return a list of countries (or country) with populations larger than 100 million
large_countries(C) :- 
    country(N,Cap,In,Size),
    In > 100.

%should return a list of nordic countries with republic governments
republic_governments(C) :-
    findall(X,(nordic_country(X),form_of_government(X,'republic')),C).


%returns list of countries that have national holidays in june
national_days_june(C) :-
	    findall(X,national_day(X,date(D,'June')),C).

%returns list of monarch(Name,Country) objects
monarchs(Monarchs) :-
	    findall(monarch(X,Y),king(Y,X),Monarchs).

%returns a list of all countries with a given colour in their flag
colour_in_flag(Colour,Countries) :-
	    findall(X,(flag(X,[Colour,C]);flag(X,[C,Colour])),Countries).
	    

%computes inhabitants per square kilometer for all countries in the form of L = [population_density(Sweden,20.66), population_density(Denmark,127.62) etc.
count_pop_density(List) :-
      findall(population_density(X,Y),(country(X,Cap,Pop,Size), Y is Pop / Size),List).										 
										 

%helper
%population_density(population_density(Country,Number)) :-

%government_types returns a list of counties segregated by govenemnt type
government_types(Return) :-
      findall((L,Y),setof(X,government_type(X,Y),L),Return).						 
%helper
government_type(Country,Type) :-
      form_of_government(Country,Type).
										 
/*
%national_infos returns lists of countries info segregated by govenment type
national_infos(List) :-

%helper
national_info(Country,CapitalCity,GovernmentType) :-
*/
