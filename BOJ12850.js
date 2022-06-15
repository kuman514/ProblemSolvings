// Solving BOJ 12850

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

/*
  ID of each buildings
  정보과학관 0
  전산관 1
  미래관 2
  신양관 3
  한경직기념관 4
  진리관 5
  형남공학관 6
  학생회관 7

  Combinations of 0 minutes
  1 0 0 0 0 0 0 0
  0 1 0 0 0 0 0 0
  0 0 1 0 0 0 0 0
  0 0 0 1 0 0 0 0
  0 0 0 0 1 0 0 0
  0 0 0 0 0 1 0 0
  0 0 0 0 0 0 1 0
  0 0 0 0 0 0 0 1

  Combinations of 1 minute
  0 1 1 0 0 0 0 0
  1 0 1 1 0 0 0 0
  1 1 0 1 1 0 0 0
  0 1 1 0 1 1 0 0
  0 0 1 1 0 1 1 0
  0 0 0 1 1 0 0 1
  0 0 0 0 1 0 0 1
  0 0 0 0 0 1 1 0
*/

const combinations = [
  [
    [0n, 1n, 1n, 0n, 0n, 0n, 0n, 0n],
    [1n, 0n, 1n, 1n, 0n, 0n, 0n, 0n],
    [1n, 1n, 0n, 1n, 1n, 0n, 0n, 0n],
    [0n, 1n, 1n, 0n, 1n, 1n, 0n, 0n],
    [0n, 0n, 1n, 1n, 0n, 1n, 1n, 0n],
    [0n, 0n, 0n, 1n, 1n, 0n, 0n, 1n],
    [0n, 0n, 0n, 0n, 1n, 0n, 0n, 1n],
    [0n, 0n, 0n, 0n, 0n, 1n, 1n, 0n]
  ]
];

for (let cur = 0; cur <= 32; cur++) {
  const currentComb = Array.from({length: 8}, () => Array.from({length: 8}, () => 0n));
  for (let i = 0; i < 8; i++) {
    for (let j = 0; j < 8; j++) {
      for (let k = 0; k < 8; k++) {
        currentComb[i][j] += (combinations[cur][i][k] * combinations[cur][k][j]);
        currentComb[i][j] %= 1000000007n;
      }
      currentComb[i][j] %= 1000000007n;
    }
  }
  combinations.push(currentComb);
}

rl.on('line', line => {
  console.log(`${totalCombinationToInfoSci(parseInt(line))}`);
  rl.close();
}).on('close', () => {
  process.exit();
});

function totalCombinationToInfoSci(minutes) {
  let finalCombs = [
    [1n, 0n, 0n, 0n, 0n, 0n, 0n, 0n],
    [0n, 1n, 0n, 0n, 0n, 0n, 0n, 0n],
    [0n, 0n, 1n, 0n, 0n, 0n, 0n, 0n],
    [0n, 0n, 0n, 1n, 0n, 0n, 0n, 0n],
    [0n, 0n, 0n, 0n, 1n, 0n, 0n, 0n],
    [0n, 0n, 0n, 0n, 0n, 1n, 0n, 0n],
    [0n, 0n, 0n, 0n, 0n, 0n, 1n, 0n],
    [0n, 0n, 0n, 0n, 0n, 0n, 0n, 1n]
  ];
  const bit = [];
  let remain = minutes;
  while (remain > 0) {
    bit.push(remain % 2);
    remain = Math.floor(remain / 2);
  }
  for (let cur = 0; cur < bit.length; cur++) {
    if (bit[cur] === 0) {
      continue;
    }
    const currentComb = Array.from({length: 8}, () => Array.from({length: 8}, () => 0n));
    for (let i = 0; i < 8; i++) {
      for (let j = 0; j < 8; j++) {
        for (let k = 0; k < 8; k++) {
          currentComb[i][j] += (finalCombs[i][k] * combinations[cur][k][j]);
          currentComb[i][j] %= 1000000007n;
        }
        currentComb[i][j] %= 1000000007n;
      }
    }
    finalCombs = currentComb;
  }
  return finalCombs[0][0];
}
