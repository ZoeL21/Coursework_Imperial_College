/*the students in Hogwarts*/
student(hp, 'Harry James Potter', gryffindor).
student(hg, 'Hermione Jean Granger', gryffindor).
student(rw, 'Ronald Weasley', gryffindor).
student(ll, 'Luna Lovegood', ravenclaw).
student(cc, 'Cho Chang', ravenclaw).
student(tb, 'Terry Boot', ravenclaw).
student(ha, 'Hannah Abbott', hufflepuff).
student(cd, 'Cedric Diggory', hufflepuff).
student(nt, 'Nymphadora Tonks',hufflepuff).
student(dm, 'Draco Malfoy', slytherin).
student(gg, 'Gregory Goyle', slytherin).
student(vc, 'Vincent Crabbe', slytherin).
student(zl, 'Zoe Landgraf', hufflepuff).

/*the teachers in Hogwarts*/
teacher(ad, 'Albus Percival Wulfric Brian Dumbledore').
teacher(ff, 'Filius Flitwick').
teacher(rh, 'Rubeus Hagrid').
teacher(gl, 'Gilderoy Lockhart').
teacher(rl, 'Remus John Lupin').
teacher(mm, 'Minerva McGonagall').
teacher(qq, 'Quirinus Quirrell').
teacher(ss, 'Severus Snape').
teacher(ps, 'Pomona Sprout').
teacher(st, 'Sibyll Patricia Trelawney').
teacher(mh, 'Madam Hooch').
teacher(as, 'Aurora Sinistra').
teacher(cub, 'Cuthbert Binns').
teacher(bb, 'Bathsheba Babbling').
teacher(sv, 'Septima Vector').
teacher(chb, 'Charity Burbage').
teacher(wt, 'Wilkie Twycross').
/*compulsory courses for the MSc in Magic*/
compCourse(astro, 'Astronomy', as).
compCourse(charms, 'Charms', ff).
compCourse(defence, 'Defence against the Dark Arts', qq).
compCourse(fly, 'Flying', mh).
compCourse(herb, 'Herbology', ps).
compCourse(history, 'History of Magic', cub).
compCourse(potions, 'Potions', ss).
compCourse(trans, 'Transfiguration', mm).

/*optional courses for the MSc in Magic*/
optCourse(runes, 'Study of Ancient Runes', bb).
optCourse(arith, 'Arithmancy', sv).
optCourse(muggle, 'Muggle Studies', chb).
optCourse(creatures, 'Care of Magical Creatures', rh).
optCourse(div, 'Divination', st).
optCourse(app, 'Apparition', wt).
optCourse(choir, 'Frog Choir', ff).
optCourse(quid, 'Quidditch', mh).

/*enrollments*/
enrolled_opt(hp,runes).
enrolled_opt(hp,arith).
enrolled_opt(hp,muggle).
enrolled_opt(hg,div).
enrolled_opt(hg,arith).
enrolled_opt(hg,muggle).
enrolled_opt(hg,choir).
enrolled_opt(hg,runes).
enrolled_opt(hg,creatures).

enrolled_opt(rw,runes).
enrolled_opt(rw,arith).
enrolled_opt(rw,muggle).

enrolled_opt(ll,runes).
enrolled_opt(ll,creatures).
enrolled_opt(ll,muggle).

enrolled_opt(cc,runes).
enrolled_opt(cc,muggle).
enrolled_opt(cc,div).

enrolled_opt(tb,div).
enrolled_opt(tb,runes).
enrolled_opt(tb,muggle).

enrolled_opt(ha,div).
enrolled_opt(ha,runes).
enrolled_opt(ha,muggle).

enrolled_opt(cd,div).
enrolled_opt(cd,choir).
enrolled_opt(cd,app).

enrolled_opt(nt,muggle).
enrolled_opt(nt,creatures).
enrolled_opt(nt,app).

enrolled_opt(dm,muggle).
enrolled_opt(dm,app).
enrolled_opt(dm,quid).

enrolled_opt(gg,quid).
enrolled_opt(gg,choir).
enrolled_opt(gg,app).

enrolled_opt(vc,app).
enrolled_opt(vc,div).
enrolled_opt(vc,muggle).

enrolled_opt(zl,app).
enrolled_opt(zl,arith).
enrolled_opt(zl,quid).


/************/
enrolled(SID,SCN):-
    enrolled_opt(SID,SCN);compCourse(SCN,_,_).

teaches(TN,SCN):-
    teacher(TID,TN),
    compCourse(SCN,_,TID);optCourse(SCN,_,TID).


taughtBy(SN,TN):-
    student(SID,SN,House),
    teacher(TID,TN),
    compCourse(_,_,TID);
    optCourse(SCN,_,TID),enrolled(SID,SCN).
    

takesOption(SN,CN):-
    student(SID,SN,House),
    optCourse(SCN,CN,_),
    enrolled_opt(SID,SCN).

takesAllOptions(SN,OptCourses):-
    student(SID,SN,House),
    findall(X,takesOption(SN,X),OptCourses).

studentsInHouse(House,Students):-
    setof(X,(student(X,SN,House)),L),
    replace_name(L,Students).

replace_name([X],Ln):-
    student(X,Ln,_).

replace_name([H|T],[Hl|Ln]):-
    student(H,Hl,_),
    replace_name(T,Ln).

isHouse('gryffindor').
isHouse('slytherin').
isHouse('hufflepuff').
isHouse('ravenclaw').
isHouse('emptyhouse').

isCourse(SCN,CN):-
    (compCourse(SCN,CN,_);optCourse(SCN,CN,_)).

studentsOnCourse(SCN,CN,StudentsByHouse):-
    isCourse(SCN,CN),
    setof(H-L,(isHouse(H),studentsHouseCourse(H,SCN,L)),StudentsByHouse).

studentsHouseCourse(House,SCN,L):-
findall(SN,(student(SID,SN,House),enrolled(SID,SCN)),L),
   write(L).


sharedCourse(SN1,SN2,CN):-
    student(SID1,SN1,House1),
    student(SID2,SN2,House2),
    SN\=SN2,
    isCourse(SCN,CN),
    enrolled(SID1,SCN),
    enrolled(SID2,SCN).


sameOptions(SN1,SN2,Courses):-
    takesAllOptions(SN1,L1),
    student(_,SN2,_),
    SN1 \= SN2,
    findall(X,(takesOption(SN2,X),member(X,L1)),Courses),
    length(Courses,3).
