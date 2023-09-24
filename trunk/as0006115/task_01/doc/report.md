<p align="center"> Министерство образования Республики Беларусь</p>
<p align="center">Учреждение образования</p>
<p align="center">“Брестский Государственный технический университет”</p>
<p align="center">Кафедра ИИТ</p>
<br><br><br><br><br><br><br>
<p align="center">Лабораторная работа №1</p>
<p align="center">По дисциплине “Теория и методы автоматического управления”</p>
<p align="center">Тема: “Моделирования температуры объекта”</p>
<br><br><br><br><br>
<p align="right">Выполнил:</p>
<p align="right">Студент 3 курса</p>
<p align="right">Группы АС-61</p>
<p align="right">Рыжко С. И.</p>
<p align="right">Проверил:</p>
<p align="right">Иванюк Д. С.</p>
<br><br><br><br><br>
<p align="center">Брест 2023</p>

---

**Задание**:

Let's get some object to be controlled. We want to control its temperature, which can be described by this differential equation:

$$\Large\frac{dy(\tau)}{d\tau}=\frac{u(\tau)}{C}+\frac{Y_0-y(\tau)}{RC} $$ (1)

where $\tau$ – time; $y(\tau)$ – input temperature; $u(\tau)$ – input warm; $Y_0$ – room temperature; $C,RC$ – some constants.

After transformation we get these linear (2) and nonlinear (3) models:

$$\Large y_{\tau+1}=ay_{\tau}+bu_{\tau}$$ (2)
$$\Large y_{\tau+1}=ay_{\tau}-by_{\tau-1}^2+cu_{\tau}+d\sin(u_{\tau-1})$$ (3)

where $\tau$ – time discrete moments ($1,2,3{\dots}n$); $a,b,c,d$ – some constants.

Task is to write program (**С++**), which simulates this object temperature.

**Код решения:**

``` typescript
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


```

Пример вывода программы:

``` bash
➜  src git:(task_01) ✗ npm run build

> src@1.0.0 build
> tsc && node ./dist/main.js

Input time parameter: 10
Input initial temperature: 0
Linear model data
{ y(t): 1; t: 1 }
{ y(t): 1.5; t: 2 }
{ y(t): 1.75; t: 3 }
{ y(t): 1.88; t: 4 }
{ y(t): 1.94; t: 5 }
{ y(t): 1.97; t: 6 }
{ y(t): 1.99; t: 7 }
{ y(t): 2; t: 8 }
{ y(t): 2; t: 9 }
{ y(t): 2; t: 10 }
Non linear model data
{ y(t): 1.2; t: 1 }
{ y(t): 0.7; t: 2 }
{ y(t): 1.4; t: 3 }
{ y(t): 0.28; t: 4 }
{ y(t): 1.6; t: 5 }
{ y(t): -0.22; t: 6 }
{ y(t): 1.38; t: 7 }
{ y(t): 0.32; t: 8 }
{ y(t): 1.59; t: 9 }
{ y(t): -0.2; t: 10 }



```
