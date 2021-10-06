// Solving BOJ 2338

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let [a, b] = [null, null];

rl.on('line', (line) => {
  if (a === null) {
    a = BigInt(line);
  } else if (b === null) {
    b = BigInt(line);
    console.log(`${a + b}\n${a - b}\n${a * b}\n`);
    rl.close();
  }
}).on('close', () => {
  process.exit();
});
