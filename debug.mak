project_debug: user_interface.o llist.o
	g++ -o project_debug user_interface.o llist.o  
llist.o: llist.cpp record.h
	g++ -Ddebug -ansi -pedantic-errors -Wall -c llist.cpp
user_interface.o: user_interface.cpp record.h llist.h
	g++ -Ddebug -ansi -pedantic-errors -Wall -c user_interface.cpp
