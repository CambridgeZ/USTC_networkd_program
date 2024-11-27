
#include "./config.hpp"
#include "ChatClient.hpp"

using std::cout;

int main(int argc,char* argv[]){
	if(argc <= 2){
		printf("usage: %s ip_address port_number\n",basename(argv[0]));
		return 1;
	}
	const char* ip = argv[1];
	int port = atoi(argv[2]);

	ChatClient client(ip,port);
	client.run();

	return 0;
}

