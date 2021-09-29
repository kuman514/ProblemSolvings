// Solving BOJ 21185

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

/*
  sum of N consecutive positive integers
  = Nn + ((N - 1)N / 2)

  mult: N
  adder: ((N - 1) * N) / 2

  mult: even / adder: even => sum: even
  mult: even / adder: odd => sum: odd
  mult: odd / adder: even => sum: either
  mult: odd / adder: odd => sum: either
*/

rl.on('line', (line) => {
  const n = parseInt(line);
  const mult = n;
  const adder = ((n - 1) * n) / 2;

  const even = 'Even';
  const odd = 'Odd';
  const either = 'Either';

  if (mult % 2 === 0) {
    if (adder % 2 === 0) {
      console.log(even);
    } else {
      console.log(odd);
    }
  } else {
    console.log(either);
  }

  rl.close();
}).on('close', () => {
  process.exit();
});
