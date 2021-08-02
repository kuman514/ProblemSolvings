// Solving BOJ 17626

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  console.log(getFourSquares(Number(line)));
  rl.close();
}).on('close', () => {
  process.exit();
});

function getFourSquares(n) {
  let result = 4;

  const limit = Math.sqrt(n);
  let current = Math.floor(limit);
  while (current >= 1) {
    // 1st
    const remaining = n - (current ** 2);
    if (remaining === 0) {
      // Very minimum result
      result = 1;
      break;
    } else {
      // 2nd
      let current2 = Math.floor(Math.sqrt(remaining));
      while (current2 >= 1) {
        const remaining2 = remaining - (current2 ** 2);
        if (remaining2 === 0) {
          if (result > 2) {
            result = 2;
          }
          break;
        } else {
          // 3rd
          let current3 = Math.floor(Math.sqrt(remaining2));
          while (current3 >= 1) {
            const reamining3 = remaining2 - (current3 ** 2);
            if (reamining3 === 0) {
              if (result > 3) {
                result = 3;
              }
              break;
            }

            current3--;
          }
        }

        current2--;
      }
    }

    current--;
  }

  return result;
}
