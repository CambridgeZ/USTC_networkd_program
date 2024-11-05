# lab2 

## 程序编译

编译客户端程序
```shell
cd lab2
g++ -std=c++11 ./ChatRoomClient.cpp -o ./ChatRoomClient
```

编译服务器程序
```shell
g++ -std=c++11 ./ChatRoomServer.cpp  -o ./ChatRoomServer
```

## 程序运行

运行服务器端程序
```shell
./ChatRoomServer <本地ip> <服务器程序运行port>
```

eg:
```shell
./ChatRoomServer 127.0.0.1 12345
```


运行客户端程序
```shell
./ChatRoomServer <服务器ip> <服务器程序运行port>
```

eg:
```shell
./ChatRoomClient 127.0.0.1 12345
```

