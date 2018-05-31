check.cgi:connection_pool.o check_connect_mysql.o
	g++ -o check.cgi connection_pool.o check_connect_mysql.o -lmysqlclient
check_connect_mysql.o:check_connect_mysql.cpp
	g++ -c check_connect_mysql.cpp
connection_pool.o:connection_pool.cpp connection_pool.h
	g++ -c connection_pool.cpp connection_pool.h
clean:
	rm -rf *.o *.h.gch
