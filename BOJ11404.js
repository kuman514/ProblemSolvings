// Solving BOJ 11404

const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

let cities = null;
let buses = null;
let lines = 0;

let routes = null;
const infinity = 100000001;

rl.on('line', (line) => {
  if (cities === null) {
    cities = Number(line);
    routes = Array.from({length: cities}, () => Array.from({length: cities}, () => infinity));
  } else if (buses === null) {
    buses = Number(line);
  } else if (lines < buses) {
    const [orgTmp, dstTmp, cost] = line.split(' ').map((item) => Number(item));
    const [org, dst] = [orgTmp - 1, dstTmp - 1];
    if (cost < routes[org][dst]) {
      routes[org][dst] = cost;
    }
    lines++;

    if (lines === buses) {
      floydWarshall();
      let result = '';
      for (let i = 0; i < routes.length; i++) {
        for (let j = 0; j < routes[i].length; j++) {
          if (j === routes[i].length - 1) {
            result += `${routes[i][j] === infinity ? 0 : routes[i][j]}\n`;
          } else {
            result += `${routes[i][j] === infinity ? 0 : routes[i][j]} `;
          }
        }
      }
      console.log(result);
      rl.close();
    }
  }
}).on('close', () => {
  process.exit();
});

function floydWarshall() {
  /*
    Floyd-Warshall Algorithm

    // entire ==========================================
    let dist be a |V| × |V| array of minimum distances initialized to ∞ (infinity)

    for each edge (u,v)
      dist[u][v] ← w(u,v)  // Weight of Edge (u,v)
    
    // current part ====================================
    for each vertex v
      dist[v][v] ← 0
    
    for k from 1 to |V|
      for i from 1 to |V|
        for j from 1 to |V|
          if dist[i][j] > dist[i][k] + dist[k][j]
            dist[i][j] ← dist[i][k] + dist[k][j]
          end if
    // end of current part =============================
    // end of entire ===================================
  */

  for (let i = 0; i < routes.length; i++) {
    routes[i][i] = 0;
  }

  for (let k = 0; k < routes.length; k++) {
    for (let i = 0; i < routes.length; i++) {
      for (let j = 0; j < routes.length; j++) {
        if (routes[i][j] > routes[i][k] + routes[k][j]) {
          routes[i][j] = routes[i][k] + routes[k][j];
        }
      }
    }
  }
}