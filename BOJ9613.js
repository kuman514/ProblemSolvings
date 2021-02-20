// Solving BOJ 9613

const readLine = require('readline')
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
})

let testCase = -1
let loop = 0

rl.on('line', line => {
  if (testCase === -1) {
    // Get testCase
    testCase = parseInt(line)
  } else {
    // Get and parse the line
    let input = line.split(' ').map(element => parseInt(element))
    input.shift()

    // Run the function with input
    console.log(getGCDSum(input))

    loop++
    if (loop >= testCase) {
      rl.close()
    }
  }
}).on('close', () => {
  process.exit()
})

function getGCDSum (input) {
  if (input.length <= 1) {
    return input[0]
  }

  let result = 0
  for (let i = 0; i < input.length - 1; i++) {
    for (let j = i + 1; j < input.length; j++) {
      result += getGCD(input[i], input[j])
    }
  }

  return result
}

function getGCD (a, b) {
  let x = a
  let y = b

  while (y > 0) {
    let t = y
    y = x % y
    x = t
  }

  return x
}
