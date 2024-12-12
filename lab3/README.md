# lab3

## 编译命令
```shell
cd lab3
g++ -std=c++11 ./sendFile.cpp -o ./sendFile
```

## 运行

### 服务器端

如果不使用默认的IP和端口号采用下面
```shell
./sendFile <ip> <port>
```

使用默认的端口和IP
```shell
./sendFile
```

在程序当中按照要求输入需要发送的文件名

### 客户端
可以通过telnet 获取文件的内容

```shell
telnet <ip> <port>
```

