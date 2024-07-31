let port;
let writer;
let connected = false;

document.getElementById('connectButton').addEventListener('click', async () => {
  if (connected) {
    await port.close();
    document.getElementById('onButton').disabled = true;
    document.getElementById('offButton').disabled = true;
    document.getElementById('connectButton').innerText = 'Conectar';
    connected = false;
  } else {
    port = await navigator.serial.requestPort();
    await port.open({ baudRate: 9600 });
    writer = port.writable.getWriter();
    document.getElementById('onButton').disabled = false;
    document.getElementById('offButton').disabled = false;
    document.getElementById('connectButton').innerText = 'Desconectar';
    connected = true;
  }
});

document.getElementById('onButton').addEventListener('click', async () => {
  if (connected) {
    await writer.write(new TextEncoder().encode('1'));
  }
});

document.getElementById('offButton').addEventListener('click', async () => {
  if (connected) {
    await writer.write(new TextEncoder().encode('0'));
  }
});
