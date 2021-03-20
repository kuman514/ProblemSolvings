// Solving BOJ 1992

const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

let field = []
let count = 0
let iteration = 0

rl.on('line', line => {
  if (count === 0) {
    count = parseInt(line)
  } else if (iteration < count) {
    const added = Array.from(line).map(item => parseInt(item))
    field.push(added)
    iteration++

    if (iteration >= count) {
      console.log(compressField(0, 0, count))
      rl.close()
    }
  }
}).on('close', () => {
  process.exit()
})

function compressField (firstRow, firstCol, currentSpan) {
  const splitSpan = currentSpan / 2
  let eachResult = []

  for (let order = 0; order < 4; order++) {
    const startRow = firstRow + (splitSpan * Math.floor(order / 2))
    const endRow = startRow  + splitSpan
    const startCol = firstCol + (splitSpan * (order % 2))
    const endCol = startCol  + splitSpan

    const first = field[startRow][startCol]
    let isAllSame = true
    
    for (let i = startRow; i < endRow; i++) {
      for (let j = startCol; j < endCol; j++) {
        if (first !== field[i][j]) {
          isAllSame = false
          break
        }
      }
  
      if (!isAllSame) {
        break
      }
    }
  
    if (!isAllSame) {
      const toChild = compressField(startRow, startCol, currentSpan / 2)
      eachResult.push(`${toChild}`)
    } else {
      eachResult.push(`${first}`)
    }
  }

  let isAllSame = true
  for (let i = 1; i < 4; i++) {
    if (eachResult[0].length !== 1 || eachResult[0] !== eachResult[i]) {
      isAllSame = false
      break
    }
  }

  if (!isAllSame) {
    return `(${eachResult.join('')})`
  } else {
    return eachResult[0]
  }
}
