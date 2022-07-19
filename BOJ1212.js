// Solving BOJ 1212

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const octToBin = ['000', '001', '010', '011', '100', '101', '110', '111'];

rl.on('line', line => {
  let append = '';
  for (let i = 0; i < line.length; i++) {
    const num = parseInt(line[i]);
    append += octToBin[num];
  }

  let result = '';
  let trimmingZero = true;
  for (let i = 0; i < append.length; i++) {
    if (trimmingZero && append[i] === '1') {
      trimmingZero = false;
    }

    if (trimmingZero) {
      continue;
    }

    result += append[i];
  }

  if (result.length === 0) {
    result = '0';
  }
  
  console.log(result);
  rl.close();
}).on('close', () => {
  process.exit();
});
