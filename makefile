main:log.o main.o LST_TIMER.h block_queue.h threadpool.h http_conn.o
	g++ -o main log.o main.o LST_TIMER.h block_queue.h threadpool.h http_conn.o -lpthread
main.o:
	g++ -c main.c
log.o:log.cpp log.h
	g++ -c log.cpp log.h
http_conn.o:http_conn.cpp http_conn.h
	g++ -c http_conn.cpp http_conn.h
clean:
	rm -rf *.o *.h.gch
