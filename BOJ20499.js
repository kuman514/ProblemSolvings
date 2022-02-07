// Solving BOJ 20499

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const [k, d, a] = line.split('/').map((item) => parseInt(item));
  if (k + a < d || d === 0) {
    console.log('hasu');
  } else {
    console.log('gosu');
  }
  rl.close();
}).on('close', () => {
  process.exit();
});
