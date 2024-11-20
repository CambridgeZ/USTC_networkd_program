<template>
  <div id="app">
    <h1>WebSocket Chat</h1>
    <div>
      <textarea v-model="message" placeholder="Type a message" rows="4" cols="50"></textarea>
      <button @click="sendMessage">Send</button>
    </div>
    <h2>Messages:</h2>
    <ul>
      <li v-for="(msg, index) in messages" :key="index">
        <span v-if="msg.startsWith('Server: ')">
          <strong>{{ msg }}</strong>
        </span>
        <span v-else>
          {{ msg }}
        </span>
      </li>
    </ul>
  </div>
</template>

<script>
export default {
  data() {
    return {
      socket: null,
      message: "",
      messages: [], // 存储从服务器收到的消息
    };
  },
  mounted() {
    // 初始化 WebSocket
    this.socket = new WebSocket("ws://localhost:9002");

    // 监听收到的消息
    this.socket.onmessage = (event) => {
      this.messages.push(event.data); // 将消息添加到本地消息数组
    };

    // 处理 WebSocket 打开事件
    this.socket.onopen = () => {
      console.log("WebSocket connection established.");
    };

    // 处理 WebSocket 关闭事件
    this.socket.onclose = () => {
      console.log("WebSocket connection closed.");
    };

    // 处理 WebSocket 错误
    this.socket.onerror = (error) => {
      console.error("WebSocket error:", error);
    };
  },
  methods: {
    sendMessage() {
      if (this.socket && this.socket.readyState === WebSocket.OPEN) {
        this.socket.send(this.message); // 发送消息到服务器
        this.message = ""; // 清空输入框
      } else {
        alert("WebSocket connection is not open.");
      }
    },
  },
};
</script>

<style>
textarea {
  margin-bottom: 10px;
  display: block;
}
button {
  margin-bottom: 20px;
}
</style>