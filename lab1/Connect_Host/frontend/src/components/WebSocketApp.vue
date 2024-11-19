<template>
  <div id="app">
    <h1>WebSocket Client</h1>
    <div>
      <textarea v-model="message" placeholder="Type a message" rows="4" cols="50"></textarea>
    </div>
    <button @click="sendMessage">Send</button>
    <div>
      <h3>Received Messages:</h3>
      <ul>
        <li v-for="(msg, index) in messages" :key="index">{{ msg }}</li>
      </ul>
    </div>
  </div>
</template>

<script>
export default {
  data() {
    return {
      socket: null,
      message: "",
      messages: [],
    };
  },
  methods: {
    connectWebSocket() {
      this.socket = new WebSocket("ws://localhost:9002");
      this.socket.onmessage = (event) => {
        this.messages.push(event.data);
      };
      this.socket.onopen = () => {
        console.log("WebSocket connection established");
      };
      this.socket.onclose = () => {
        console.log("WebSocket connection closed");
      };
    },
    sendMessage() {
      if (this.socket && this.socket.readyState === WebSocket.OPEN) {
        this.socket.send(this.message);
        this.message = "";
      } else {
        alert("WebSocket is not connected");
      }
    },
  },
  mounted() {
    this.connectWebSocket();
  },
};
</script>

<style>
textarea {
  margin-bottom: 10px;
  width: 100%;
}
button {
  margin-bottom: 20px;
}
</style>