// Solving BOJ 1373

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const binToOct = {
  '000': '0',
  '001': '1',
  '010': '2',
  '011': '3',
  '100': '4',
  '101': '5',
  '110': '6',
  '111': '7'
};

rl.on('line', line => {
  let binStr = line;
  while (binStr.length % 3 !== 0) {
    binStr = '0' + binStr;
  }

  let append = '';
  for (let i = 0; i < binStr.length; i += 3) {
    append += binToOct[binStr.slice(i, i + 3)];
  }

  let result = '';
  let trimmingZero = true;
  for (let i = 0; i < append.length; i++) {
    if (trimmingZero && append[i] !== '0') {
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
