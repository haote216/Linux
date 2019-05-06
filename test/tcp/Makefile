.PHONY:all
all:tcp_client tcp_server tcp_server_pthread

tcp_client:tcp_client.c 
	gcc -o $@ $^ 
tcp_server:tcp_server.c
	gcc -o $@ $^
tcp_server_pthread:tcp_server_pthread.c
	gcc -o $@ $^ -lpthread

.PHONY:clean
clean:
	rm -f tcp_client tcp_server tcp_server_pthread
