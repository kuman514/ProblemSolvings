// Solving BOJ 10926

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  console.log(`${line}??!`);
  rl.close();
}).on('close', () => {
  process.exit();
});
