main:log.cpp log.h block_queue.h main.c threadpool.h LST_TIMER.h http_conn.cpp http_conn.h
	g++ -g -o main log.cpp log.h block_queue.h main.c threadpool.h LST_TIMER.h http_conn.h http_conn.cpp -lpthread
