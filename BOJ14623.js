// Solving BOJ 14623

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const numStr = [];

rl.on('line', line => {
  numStr.push(line);
  if (numStr.length >= 2) {
    const [b1, b2] = numStr.map(item => {
      let adding = 1n;
      let result = 0n;
      for (let i = item.length - 1; i >= 0; i--) {
        if (item[i] === '1') {
          result += adding;
        }
        adding *= 2n;
      }
      return result;
    });
    let decimal = b1 * b2;
    let append = '';
    while (decimal > 0n) {
      append = `${decimal % 2n}` + append;
      decimal /= 2n;
    }
    console.log(append);
    rl.close();
  }
}).on('close', () => {
  process.exit();
});
