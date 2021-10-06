// Solving BOJ 1271

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const [realD, h, w] = line.split(' ').map((item) => parseInt(item));
  const d = Math.sqrt(h ** 2 + w ** 2);
  const mult = realD / d;
  const [realH, realW] = [h * mult, w * mult];
  console.log(`${Math.floor(realH)} ${Math.floor(realW)}`);
  rl.close();
}).on('close', () => {
  process.exit();
});
