.PHONY:all
all:udp_client udp_server

udp_client:udp_client.cpp 
	g++ -o $@ $^
udp_server:udp_server.cpp 
	g++ -o $@ $^

.PHONY:clean
clean:
	rm -f udp_client udp_server
