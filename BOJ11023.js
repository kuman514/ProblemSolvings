// Solving BOJ 11023

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  const array = line.split(' ').map(item => parseInt(item));
  const result = array.reduce((prev, cur) => (prev + cur));
  console.log(result);
  rl.close();
}).on('close', () => {
  process.exit();
});
