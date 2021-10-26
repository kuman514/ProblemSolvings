// Solving BOJ 8437

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let total = null;
let diff = null;

rl.on('line', (line) => {
  if (total === null) {
    total = BigInt(line);
  } else {
    diff = BigInt(line);
    // 2x + diff = total
    // x = (total - diff) / 2
    const x = (total - diff) / 2n;
    console.log(`${x + diff}\n${x}`);
    rl.close();
  }
}).on('close', () => {
  process.exit();
});
