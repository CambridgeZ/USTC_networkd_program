# README

## 环境配置

环境 Ubantu Linux 22

1. 安装 WebSocket 客户端库（可选，原生 API 也可以）。
```shell
npm install vue-native-websocket-vue3 --save
```

2. 安装 WebSocket++ 库
```shell
sudo apt-get install libwebsocketpp-dev
```

3. 安装 Boost 库
```shell
sudo apt-get update
sudo apt-get install libboost-all-dev
```

编译命令
```shell
g++ -std=c++11 -o server server.cpp -I/usr/local/include -lboost_system
```

运行后端
```shell
./server
```

运行前端vue
```shell
npm run dev
```