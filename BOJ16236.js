// Solving BOJ 16326

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let lines = null;
let cur = 0;
const sea = [];

rl.on('line', (line) => {
  if (lines === null) {
    lines = Number(line);
  } else if (cur < lines) {
    sea.push(line.split(' ').map((item) => Number(item)));
    cur++;
    if (cur === lines) {
      console.log(secondsEatingAlone());
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function secondsEatingAlone() {
  // Scan the shark's initial position
  let [sharkInitR, sharkInitC] = [-1, -1];
  let found = false;
  for (let i = 0; i < sea.length && !found; i++) {
    for (let j = 0; j < sea[i].length && !found; j++) {
      // The shark's position is determined only by [const shark]
      if (sea[i][j] === 9) {
        [sharkInitR, sharkInitC] = [i, j];
        sea[i][j] = 0;
        found = true;
      }
    }
  }

  // Initialize shark
  const shark = {
    position: [sharkInitR, sharkInitC],
    size: 2,
    remain: 2
  };

  // Essential variables
  let elapsed = 0;
  let continuable = true;
  const direction = [[-1, 0], [0, -1], [1, 0], [0, 1]];

  while (continuable) {
    const visited = Array.from({length: lines}, () => Array.from({length: lines}, () => false));
    // Elements of the queue and edible: [distance, row, column]
    const next = [[0, ...shark.position]];
    const edible = [];

    // Scan for currently edible fishes
    while (next.length > 0) {
      const [curDist, curRow, curCol] = next.shift();

      // If already visited
      if (visited[curRow][curCol]) {
        continue;
      }

      // Mark here visited
      visited[curRow][curCol] = true;

      // If longer than the edible
      if (edible.length > 0 && curDist > edible[0][0]) {
        continue;
      }

      // If same distance but not edible
      if (edible.length > 0 && curDist === edible[0][0]
        && (sea[curRow][curCol] === 0 || sea[curRow][curCol] >= shark.size)) {
        continue;
      }

      // If this fish is edible
      if (0 < sea[curRow][curCol] && sea[curRow][curCol] < shark.size) {
        edible.push([curDist, curRow, curCol]);
        continue;
      }

      // Seek next area
      const nextDist = curDist + 1;
      for (let i = 0; i < 4; i++) {
        const nextRow = curRow + direction[i][0];
        const nextCol = curCol + direction[i][1];

        // Row out of range
        if (nextRow < 0 || nextRow >= lines) {
          continue;
        }

        // Column out of range
        if (nextCol < 0 || nextCol >= lines) {
          continue;
        }

        // Already visited
        if (visited[nextRow][nextCol]) {
          continue;
        }

        // If longer than the edible
        if (edible.length > 0 && nextDist > edible[0][0]) {
          continue;
        }

        // If same distance but not edible
        if (edible.length > 0 && nextDist === edible[0][0]
          && (sea[nextRow][nextCol] === 0 || sea[nextRow][nextCol] >= shark.size)) {
          continue;
        }

        // If can't pass
        if (sea[nextRow][nextCol] > shark.size) {
          continue;
        }

        next.push([nextDist, nextRow, nextCol]);
      }
    }

    // If there is no edible fishes
    if (edible.length === 0) {
      continuable = false;
      continue;
    }

    // Sort edible
    edible.sort((a, b) => {
      for (let i = 0; i < 3; i++) {
        if (a[i] < b[i]) {
          return -1;
        } else if (a[i] > b[i]) {
          return 1;
        }
      }
      return 0;
    });

    // Move to eat the fish
    elapsed += edible[0][0];
    sea[edible[0][1]][edible[0][2]] = 0;
    shark.position = [edible[0][1], edible[0][2]];
    shark.remain--;
    if (shark.remain === 0) {
      shark.size++;
      shark.remain = shark.size;
    }
  }

  return elapsed;
}
