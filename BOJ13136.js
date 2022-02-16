// Solving BOJ 13136

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const [r, c, n] = line.split(' ').map((item) => parseInt(item));
  console.log(Math.ceil(r / n) * Math.ceil(c / n));
  rl.close();
}).on('close', () => {
  process.exit();
});
