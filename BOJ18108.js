// Solving BOJ 18108

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const diff = 2541 - 1998;
  const result = parseInt(line) - diff;
  console.log(result);
  rl.close();
}).on('close', () => {
  process.exit();
});
