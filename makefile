server:main.c threadpool.h http_conn.cpp http_conn.h locker.h
	g++ -o server main.c threadpool.h http_conn.cpp http_conn.h locker.h -lpthread
