// Solving BOJ 2754

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', line => {
  switch (line) {
    case 'A+':
      console.log('4.3');
      break;
    case 'A0':
      console.log('4.0');
      break;
    case 'A-':
      console.log('3.7');
      break;
    case 'B+':
      console.log('3.3');
      break;
    case 'B0':
      console.log('3.0');
      break;
    case 'B-':
      console.log('2.7');
      break;
    case 'C+':
      console.log('2.3');
      break;
    case 'C0':
      console.log('2.0');
      break;
    case 'C-':
      console.log('1.7');
      break;
    case 'D+':
      console.log('1.3');
      break;
    case 'D0':
      console.log('1.0');
      break;
    case 'D-':
      console.log('0.7');
      break;
    case 'F':
      console.log('0.0');
      break;
  }
  rl.close();
}).on('close', () => {
  process.exit();
});
