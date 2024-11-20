<template>
    <div>
      <h1>WebSocket Client</h1>
      <div>
        <input v-model="message" placeholder="Type a message" />
        <button @click="sendMessage">Send</button>
      </div>
      <ul>
        <li v-for="msg in messages" :key="msg.id">{{ msg.text }}</li>
      </ul>
    </div>
  </template>
  
  <script>
  export default {
    data() {
      return {
        ws: null, // WebSocket instance
        message: "",
        messages: [],
        messageId: 0,
      };
    },
    methods: {
      connect() {
        this.ws = new WebSocket("ws://localhost:9002");
  
        this.ws.onopen = () => {
          console.log("Connected to server");
        };
  
        this.ws.onmessage = (event) => {
          console.log("Received message:", event.data);
          this.messages.push({ id: this.messageId++, text: event.data });
        };
  
        this.ws.onclose = () => {
          console.log("Disconnected from server");
        };
  
        this.ws.onerror = (error) => {
          console.error("WebSocket error:", error);
        };
      },
      sendMessage() {
        if (this.ws && this.ws.readyState === WebSocket.OPEN) {
          this.ws.send(this.message);
          this.message = "";
        } else {
          console.log("WebSocket is not connected.");
        }
      },
    },
    mounted() {
      this.connect();
    },
  };
  </script>
  
  <style>
  h1 {
    color: #333;
  }
  </style>