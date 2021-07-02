// Solving BOJ 6763

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let speedLimit = null;
let currentSpeed = null;

rl.on('line', (line) => {
  if (speedLimit === null) {
    speedLimit = Number(line);
  } else if (currentSpeed === null) {
    currentSpeed = Number(line);
    console.log(check());
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

function check() {
  const diff = currentSpeed - speedLimit;
  let fine = 0;
  if (1 <= diff && diff <= 20) {
    fine = 100;
  } else if (21 <= diff && diff <= 30) {
    fine = 270;
  } else if (31 <= diff) {
    fine = 500;
  }

  if (fine === 0) {
    return 'Congratulations, you are within the speed limit!';
  } else {
    return `You are speeding and your fine is $${fine}.`;
  }
}
