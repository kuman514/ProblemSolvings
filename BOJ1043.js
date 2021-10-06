// Solving BOJ 1043

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

const cntInputs = {
  n: null,
  m: null,
  t: null
};
const knowingTruth = new Set();
const connection = [];
const parties = [];

rl.on('line', (line) => {
  if (cntInputs.n === null && cntInputs.m === null) {
    [cntInputs.n, cntInputs.m] = line.split(' ').map((item) => parseInt(item));
    connection.push(...(Array.from({length: cntInputs.n + 1}, () => new Set())));
  } else if (cntInputs.t === null) {
    const inputs = line.split(' ').map((item) => parseInt(item));
    cntInputs.t = inputs[0];
    for (let i = 1; i <= cntInputs.t; i++) {
      knowingTruth.add(inputs[i]);
    }
  } else if (parties.length < cntInputs.m) {
    const inputs = line.split(' ').map((item) => parseInt(item));
    const party = inputs.slice(1);

    // Connection
    for (let i = 0; i < party.length - 1; i++) {
      for (let j = i + 1; j < party.length; j++){
        connection[party[i]].add(party[j]);
        connection[party[j]].add(party[i]);
      }
    }

    parties.push(party);

    if (parties.length === cntInputs.m) {
      console.log(countLiableParties());
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function countLiableParties() {
  // Scan for all unliable connection
  const visited = Array.from({length: cntInputs.n + 1}, () => false);
  const finalKnowingTruth = new Set();

  // BFS search
  knowingTruth.forEach((first) => {
    const next = [first];
    while (next.length > 0) {
      const cur = next.shift();

      if (visited[cur]) {
        continue;
      }

      visited[cur] = true;
      finalKnowingTruth.add(cur);

      // Next
      connection[cur].forEach((nextPerson) => {
        if (visited[nextPerson]) {
          return;
        }

        next.push(nextPerson);
      });
    }
  });

  // Find liable parties
  let result = 0;

  for (let i = 0; i < parties.length; i++) {
    let liable = true;
    for (let j = 0; j < parties[i].length && liable; j++) {
      if (finalKnowingTruth.has(parties[i][j])) {
        liable = false;
      }
    }

    if (liable) {
      result++;
    }
  }

  return result;
}
