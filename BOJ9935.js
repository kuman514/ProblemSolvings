// Solving BOJ 9935

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let t = null;

rl.on('line', (line) => {
  if (t === null) {
    t = line;
  } else {
    console.log(explodeStrings(t, line));
    rl.close();
  }
}).on('close', () => {
  process.exit();
});

function explodeStrings(target, bomber) {
  let curTarget = [];

  for (let i = 0; i < target.length; i++) {
    curTarget.push(target[i]);
    if (curTarget.length >= bomber.length) {
      let boom = true;
      let edge = curTarget.length - 1;
      for (let j = bomber.length - 1; j >= 0 && boom; j--) {
        if (curTarget[edge] !== bomber[j]) {
          boom = false;
          break;
        }
        edge--;
      }

      if (boom) {
        for (let j = 0; j < bomber.length; j++) {
          curTarget.pop();
        }
      }
    }
  }

  if (curTarget.length === 0) {
    return 'FRULA';
  } else {
    let finalValue = '';
    for (let i = 0; i < curTarget.length; i++) {
      finalValue += curTarget[i];
    }
    return finalValue;
  }
}
