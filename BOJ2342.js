// Solving BOJ 2342

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  const commands = line.split(' ').map((item) => parseInt(item));
  const INF = 1000000000;

  /*
       | 0 1 2 3 4
    ---|-----------
     0 | 0 2 2 2 2
     1 | 0 1 3 4 3
     2 | 0 3 1 3 4
     3 | 0 4 3 1 3
     4 | 0 3 4 3 1
    currentPosition [L:[0, 0], R:[0, 0]]
    cost [L: 0, R: 0]
  */
  
  const movementCost = [
    [1, 2, 2, 2, 2],
    [0, 1, 3, 4, 3],
    [0, 3, 1, 3, 4],
    [0, 4, 3, 1, 3],
    [0, 3, 4, 3, 1]
  ];

  // [Level][LeftPos][RightPos]
  const cost = Array.from(
    { length: commands.length - 1 },
    () => Array.from(
      { length: 5 },
      () => Array.from(
        { length: 5 },
        () => INF
      )
    )
  );

  // Very first step
  if (commands[0] !== 0) {
    // Left first
    cost[0][0][commands[0]] = movementCost[0][commands[0]];

    // Right first
    cost[0][commands[0]][0] = movementCost[0][commands[0]];
  }

  for (let index = 1; index < commands.length - 1; index++) {
    const curCommand = commands[index];

    // Left move
    for (let j = 0; j < 5; j++) {
      // i: Left prev pos
      // j: Right prev pos

      if (j === curCommand && j !== 0) {
        continue;
      }

      for (let i = 0; i < 5; i++) {
        const tmpCost = cost[index - 1][i][j] + movementCost[i][curCommand];
        if (cost[index][curCommand][j] > tmpCost) {
          cost[index][curCommand][j] = tmpCost;
        }
      }
    }

    // Right move
    for (let i = 0; i < 5; i++) {
      // i: Left prev pos
      // j: Right prev pos

      if (i === curCommand && i !== 0) {
        continue;
      }

      for (let j = 0; j < 5; j++) {
        const tmpCost = cost[index - 1][i][j] + movementCost[j][curCommand];
        if (cost[index][i][curCommand] > tmpCost) {
          cost[index][i][curCommand] = tmpCost;
        }
      }
    }
  }

  if (commands[0] !== 0) {
    let lowestCost = INF;
    const check = commands.length - 2;
    for (let i = 0; i < 5; i++) {
      for (let j = 0; j < 5; j++) {
        if (lowestCost > cost[check][i][j]) {
          lowestCost = cost[check][i][j];
        }
      }
    }

    console.log(lowestCost);
  } else {
    console.log(0);
  }
  
  rl.close();
}).on('close', () => {
  process.exit();
});
