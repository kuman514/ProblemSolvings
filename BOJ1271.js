// Solving BOJ 1271

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const [a, b] = line.split(' ').map((item) => BigInt(item));
  console.log(`${a / b}\n${a % b}\n`);
  rl.close();
}).on('close', () => {
  process.exit();
});
