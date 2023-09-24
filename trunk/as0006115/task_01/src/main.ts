import { question as prompt } from "readline-sync";

class TemperatureModel {
  constructor(public temp: number, public warm: number, public t: number) {}

  toString(): string {
    return `{ y(t): ${this.temp}; t: ${this.t} }`;
  }
}

// Some physical constants
const A = 0.5;
const B = 1;
const C = 1.2;
const D = 0.4;
// Should've been discrete value chaning over time but
const WARM = 1;

function showData(tempModels: TemperatureModel[]) {
  for (const model of tempModels) {
    console.log(model.toString());
  }
}

function simulateLinearModel(time: number, temp: number) {
  const linearTemps: TemperatureModel[] = [];

  for (let t = 1; t <= time; t++) {
    const curWarm = WARM;
    // let warm = parseInt(prompt(`Input warm for tau=${t}: `));
    temp = Math.round((A * temp + B * curWarm) * 100) / 100;
    linearTemps.push(new TemperatureModel(temp, curWarm, t));
  }

  return linearTemps;
}

function simulateNonLinearModel(time: number, temp: number) {
  const nonLinearTemps: TemperatureModel[] = [];
  let prevTemp = 0;
  let prevWarm = 0;
  for (let t = 1; t <= time; t++) {
    // let warm = parseInt(prompt(`Input warm for tau=${t} s: `));
    let curWarm = WARM;
    temp =
      A * temp -
      B * Math.pow(prevTemp, 2) +
      C * curWarm +
      D * Math.sin(prevWarm);
    temp = Math.round(temp * 100) / 100;
    nonLinearTemps.push(new TemperatureModel(temp, curWarm, t));
    prevTemp = temp;
    prevWarm = curWarm;
  }

  return nonLinearTemps;
}

const time = parseInt(prompt("Input time parameter: "));
let temp = parseInt(prompt("Input initial temperature: "));

console.log("Linear model data");
showData(simulateLinearModel(time, temp));
console.log("Non linear model data");
showData(simulateNonLinearModel(time, temp));
