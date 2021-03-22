// Solving BOJ 5525

const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

let n = 0
let m = 0
let pn = ''

rl.on('line', line => {
  if (n === 0) {
    n = parseInt(line)
    const must = (2 * n) + 1
    for (let i = 0; i < must; i++) {
      if (i % 2 === 0) {
        pn += 'I'
      } else {
        pn += 'O'
      }
    }
  } else if (m === 0) {
    m = parseInt(line)
  } else {
    console.log(countKMPMatchs(line, pn))
    rl.close()
  }
}).on('close', () => {
  process.exit()
})

function countKMPMatchs (t, p) {
  let fail = Array.from({length: 1000000}, () => 0)
  const tlen = t.length
  const plen = p.length

  // Calculate fail values
  for (let i = 1, j = 0; i < plen; i++) {
    while (j > 0 && p[i] !== p[j]) {
      j = fail[j - 1]
    }

    if (p[i] === p[j]) {
      j++
      fail[i] = j
    }
  }

  // Find match pattern using KMP
  let result = 0
  for (let i = 1, j = 0; i < tlen; i++) {
    while (j > 0 && t[i] !== p[j]) {
      j = fail[j - 1]
    }

    if (t[i] === p[j]) {
      if(j === plen - 1) {
        result++
        j = fail[j]
      } else {
        j++
      }
    }
  }

  return result
}
