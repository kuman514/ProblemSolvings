// Solving BOJ 18198

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout,
});

rl.on('line', (line) => {
  let [a, b] = [0, 0];
  let overtime = false;
  let finished = false;
  for (let i = 0; i < line.length && !finished; i += 2) {
    switch (line[i]) {
      case 'A':
        a += parseInt(line[i + 1]);
        break;
      case 'B':
        b += parseInt(line[i + 1]);
        break;
    }

    if (overtime) {
      if (a >= b + 2) {
        console.log('A');
        finished = true;
      } else if (b >= a + 2) {
        console.log('B');
        finished = true;
      }
    } else {
      if (a >= 11) {
        console.log('A');
        finished = true;
      } else if (b >= 11) {
        console.log('B');
        finished = true;
      } else if (a === 10 && b === 10) {
        overtime = true;
      }
    }
  }
  rl.close();
}).on('close', () => {
  process.exit();
});
