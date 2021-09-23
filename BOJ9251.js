// Solving BOJ 9251

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const inputs = [];

rl.on('line', (line) => {
  if (inputs.length < 2) {
    inputs.push(line);
    if (inputs.length === 2) {
      console.log(getLongestCommonSubsequence(inputs));
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function getLongestCommonSubsequence(strings) {
  const sqLength = Array.from(
    {length: strings[0].length + 1},
    () => Array.from(
      {length: strings[1].length + 1},
      () => 0
    )
  );

  for (let i = 1; i < sqLength.length; i++) {
    const curI = i - 1;
    for (let j = 1; j < sqLength[i].length; j++) {
      const curJ = j - 1;

      if (strings[0][curI] === strings[1][curJ]) {
        sqLength[i][j] = sqLength[i - 1][j - 1] + 1;
      } else {
        sqLength[i][j] = Math.max(sqLength[i][j - 1], sqLength[i - 1][j]);
      }
    }
  }

  return sqLength[strings[0].length][strings[1].length];
}
