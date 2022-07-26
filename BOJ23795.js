// Solving BOJ 23795

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let money = 0;

rl.on('line', line => {
  const num = parseInt(line);
  if (num === -1) {
    console.log(money);
    rl.close();
    return;
  }
  money += num;
}).on('close', () => {
  process.exit();
});
