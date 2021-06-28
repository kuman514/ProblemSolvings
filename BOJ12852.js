// Solving BOJ 12852

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.on('line', (line) => {
  console.log(seekAndTraceResult(line));
  rl.close();
}).on('close', () => {
  process.exit();
});

function seekAndTraceResult(targetStr) {
  const target = Number(targetStr);
  const from = Array.from({length: target + 1}, () => 0);
  const visited = Array.from({length: target + 1}, () => false);

  // Seek result
  // [currentValue, calcCount, from]
  const queue = [[target, 0, 0]];
  let minCount = 0;
  while (queue.length > 0) {
    const current = queue.shift();

    // If visited current value, skip the below.
    if (visited[current[0]]) {
      continue;
    }

    // Mark the current value visited
    visited[current[0]] = true;
    from[current[0]] = current[2];

    // If the current value is 1
    if (current[0] === 1) {
      minCount = current[1];
      break;
    }

    // Next count
    const nextCount = current[1] + 1;

    // If current[0] % 3 === 0 and not visited
    if (current[0] % 3 === 0) {
      const nextVal = Math.floor(current[0] / 3);
      if (nextVal > 0 && !visited[nextVal]) {
        queue.push([nextVal, nextCount, current[0]]);
      }
    }

    // If current[0] % 2 === 0 and not visited
    if (current[0] % 2 === 0) {
      const nextVal = Math.floor(current[0] / 2);
      if (nextVal > 0 && !visited[nextVal]) {
        queue.push([nextVal, nextCount, current[0]]);
      }
    }

    // If current[0] - 1 not visited
    const nextVal1 = current[0] - 1;
    if (nextVal1 > 0 && !visited[nextVal1]) {
      queue.push([nextVal1, nextCount, current[0]]);
    }
  }

  // Trace result
  let current = 1;
  let result = `${minCount}\n`;
  const tmp = [];
  while (current !== 0) {
    tmp.push(current);
    current = from[current];
  }
  for (let i = tmp.length - 1; i >= 0; i--) {
    if (i !== 0) {
      result += `${tmp[i]} `;
    } else {
      result += `${tmp[i]}`;
    }
  }

  return result;
}
