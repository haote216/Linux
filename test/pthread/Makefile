.PHONY:all
all:pthread_create pthread_join pthread_mutex pthread_cancel rwlock conditon

pthread_create:pthread_create.cpp
	g++ -o $@ $^ -lpthread
pthread_join:pthread_join.cpp 
	g++ -o $@ $^ -lpthread
pthread_mutex:pthread_mutex.cpp
	g++ -o $@ $^ -lpthread
pthread_cancel:pthread_cancel.cpp 
	g++ -o $@ $^ -lpthread
rwlock:rwlock.cpp 
	g++ -o $@ $^ -lpthread 
conditon:conditon.cpp 
	g++ -o $@ $^ -lpthread 

.PHONY:clean 
clean:
	rm -f pthread_create pthread_join pthread_mutex pthread_cancel rwlock conditon
