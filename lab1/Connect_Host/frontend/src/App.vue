<template>
  <div id="app">
    <WebSocketApp />
  </div>
</template>

<script>
import WebSocketApp from "./components/WebSocketApp.vue";

export default {
  name: "App",
  components: {
    WebSocketApp,
  },
};
</script>