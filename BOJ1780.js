// Solving BOJ 1780

const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

let paper = []
let count = 0
let iteration = 0

let result = [0, 0, 0]
const offset = 1

rl.on('line', line => {
  if (count === 0) {
    count = parseInt(line)
  } else if (iteration < count) {
    const added = line.split(' ').map(item => parseInt(item))
    paper.push(added)
    iteration++

    if (iteration >= count) {
      countpaper(0, 0, count)
      for (let i = 0; i < 3; i++) {
        console.log(result[i])
      }
      rl.close()
    }
  }
}).on('close', () => {
  process.exit()
})

function countpaper (startRow, startCol, span) {
  if (span === 1) {
    result[offset + paper[startRow][startCol]]++
    return
  }

  const first = paper[startRow][startCol]
  let isAllSame = true
  const endRow = startRow + span
  const endCol = startCol + span

  for (let i = startRow; i < endRow; i++) {
    for (let j = startCol; j < endCol; j++) {
      if (first !== paper[i][j]) {
        isAllSame = false
        break
      }
    }

    if (!isAllSame) {
      break
    }
  }

  if (!isAllSame) {
    for (let i = startRow; i < endRow; i += (span / 3)) {
      for (let j = startCol; j < endCol; j += (span / 3)) {
        countpaper(i, j, span / 3)
      }
    }
  } else {
    result[offset + first]++
  }
}
