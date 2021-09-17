// Solving BOJ 1918

// Get readline module
const readLine = require('readline');
const rl = readLine.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Get input
rl.on('line', (line) => {
  console.log(getParsedExp(line));
  rl.close();
}).on('close', () => {
  process.exit();
});

function getParsedExp(exp) {
  // (operand i) (operand (i + 1)) <operator i>
  const operators = [];
  const operands = [];

  // Split +s and -s on this layer
  let bracketStacks = 0;
  let start = 0;
  for (let i = 0; i < exp.length; i++) {
    const token = exp[i];
    switch (token) {
      case '(':
        bracketStacks++;
        break;
      case ')':
        bracketStacks--;
        break;
      case '+': case '-':
        if (bracketStacks === 0) {
          operands.push(exp.slice(start, i));
          operators.push(token);
          start = i + 1;
        }
        break;
    }
  }
  operands.push(exp.slice(start));

  // Parse operands
  for (let i = 0; i < operands.length; i++) {
    // (subOperand i) (subOperand (i + 1)) <multOrDivOperator i>
    const multOrDivs = [];
    const subOperands = [];
    
    bracketStacks = 0;
    let bracketStart = 0;

    // Split *s and /s on this layer
    for (let j = 0; j < operands[i].length; j++) {
      const token = operands[i][j];
      switch (token) {
        case '(':
          if (bracketStacks === 0) {
            bracketStart = j + 1;
          }
          bracketStacks++;
          break;
        case ')':
          bracketStacks--;
          if (bracketStacks === 0) {
            const inBracket = getParsedExp(operands[i].slice(bracketStart, j));
            //console.log(inBracket);
            subOperands.push(inBracket);
          }
          break;
        case '*': case '/':
          if (bracketStacks === 0) {
            multOrDivs.push(token);
          }
          break;
        case '+': case '-':
          break;
        default:
          if (bracketStacks === 0) {
            subOperands.push(token);
          }
          break;
      }
    }

    //console.log(multOrDivs, subOperands);

    // Assemble postfix expression
    let finalExp = subOperands[0];
    for (let j = 0; j < multOrDivs.length; j++) {
      finalExp += `${subOperands[j + 1]}${multOrDivs[j]}`;
    }

    operands[i] = finalExp;
  }

  // Assemble postfix expression
  let finalExp = operands[0];
  for (let i = 0; i < operators.length; i++) {
    finalExp += `${operands[i + 1]}${operators[i]}`;
  }

  return finalExp;
}
