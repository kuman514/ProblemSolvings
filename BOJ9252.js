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

  // Calculate maximum length
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

  // Get LCS tracing the previous calculation
  const lcs = [];
  let [i, j] = [strings[0].length, strings[1].length];
  while (i > 0 && j > 0) {
    const [curI, curJ] = [i - 1, j - 1];

    if (strings[0][curI] === strings[1][curJ]) {
      lcs.push(strings[0][curI]);
      i--;
      j--;
    } else {
      if (sqLength[i][j - 1] >= sqLength[i - 1][j]) {
        j--;
      } else {
        i--;
      }
    }
  }

  let result = `${sqLength[strings[0].length][strings[1].length]}\n`;
  lcs.reverse();
  for (let i = 0; i < lcs.length; i++) {
    result += `${lcs[i]}`;
  }
  result += '\n';

  return result;
}
