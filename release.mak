project2: user_interface.o llist.o
	g++ -o project2 user_interface.o llist.o  
llist.o: llist.cpp record.h
	g++ -ansi -pedantic-errors -Wall -c llist.cpp
user_interface.o: user_interface.cpp record.h llist.h
	g++ -ansi -pedantic-errors -Wall -c user_interface.cpp
#homework7: homework7.o\
	g++ -o homework7 homework7.o\
homework7.o: homework7.cpp\
	g++ -ansi -pedantic-errors -Wall -c homework7.cpp
