# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Linear`](#classLinear) | Класс представляющий линейную математическую модель
`class `[`Model`](#classModel) | Абстрактный класс, предоставляющий функцию уравнения modelFunc, являющийся основой для других моделей
`class `[`NonLinear`](#classNonLinear) | Класс представляющий нелинейную математическую модель
`class `[`Regulator`](#classRegulator) | Модель ПИД регулятора

# class `Linear` {#classLinear}

```
class Linear
  : public Model
```  

Класс представляющий линейную математическую модель

Подкласс [Model](#classModel), представляющий линейную модель, переопределяющий абстрактный метод modelFunc

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Linear`](#classLinear_1a909834d3a470d9e7899aaa8d5f736af3)`(double a,double b,double nextTemp)` | Температура на выходе
`public inline virtual double `[`modelFunc`](#classLinear_1a03f4d23192103c7ee4ec3e9302e1820a)`(double currentTemp,double warmth)` | Переопределённый метод для рассчёта линейной математической модели

## Members

#### `public inline  `[`Linear`](#classLinear_1a909834d3a470d9e7899aaa8d5f736af3)`(double a,double b,double nextTemp)` {#classLinear_1a909834d3a470d9e7899aaa8d5f736af3}

Температура на выходе

#### `public inline virtual double `[`modelFunc`](#classLinear_1a03f4d23192103c7ee4ec3e9302e1820a)`(double currentTemp,double warmth)` {#classLinear_1a03f4d23192103c7ee4ec3e9302e1820a}

Переопределённый метод для рассчёта линейной математической модели

Код: 
```cpp
return A * currentTemp + B * warmth;
```

# class `Model` {#classModel}

Абстрактный класс, предоставляющий функцию уравнения modelFunc, являющийся основой для других моделей

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~Model`](#classModel_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` | 
`public double `[`modelFunc`](#classModel_1ad2e38abac5c35221addb80e09ce17182)`(double curTemp,double warm)` | Виртуальный метод, переопределяемый в классах реализующих данную модель

## Members

#### `public virtual  `[`~Model`](#classModel_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` {#classModel_1a2efbe4ec768191fa70ad86f260ec2fd6}

#### `public double `[`modelFunc`](#classModel_1ad2e38abac5c35221addb80e09ce17182)`(double curTemp,double warm)` {#classModel_1ad2e38abac5c35221addb80e09ce17182}

Виртуальный метод, переопределяемый в классах реализующих данную модель

Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели. 
#### Parameters
* `curTemp` Текущая температура в помещении 

* `warm` Входящее тепло

# class `NonLinear` {#classNonLinear}

```
class NonLinear
  : public Model
```  

Класс представляющий нелинейную математическую модель

Подкласс от [Model](#classModel), представляющий нелинейную модель, переопределяющий метод modelFunc

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinear`](#classNonLinear_1a9a0c42609d84438e345e0d5a63d3b335)`(double a,double b,double c,double d,double nextTemp)` | Предыдущее полученное тепло
`public inline virtual double `[`modelFunc`](#classNonLinear_1a113ab823e8f25090e7acd2e4e7458a67)`(double yCurrent,double inputWarm)` | Переопределённый метод для рассчёта нелинейной модели

## Members

#### `public inline  `[`NonLinear`](#classNonLinear_1a9a0c42609d84438e345e0d5a63d3b335)`(double a,double b,double c,double d,double nextTemp)` {#classNonLinear_1a9a0c42609d84438e345e0d5a63d3b335}

Предыдущее полученное тепло

#### `public inline virtual double `[`modelFunc`](#classNonLinear_1a113ab823e8f25090e7acd2e4e7458a67)`(double yCurrent,double inputWarm)` {#classNonLinear_1a113ab823e8f25090e7acd2e4e7458a67}

Переопределённый метод для рассчёта нелинейной модели

Код: 
```cpp
nextTemp = A * yCurrent - B * pow(prevTemp, 2) + C * inputWarm + D * sin(prevWarmth);
prevTemp = yCurrent;
prevWarmth = inputWarm;
return nextTemp;
```

# class `Regulator` {#classRegulator}

Модель ПИД регулятора

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#classRegulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` | 
`public inline void `[`Regulate`](#classRegulator_1a69ec58971802ba66f7441ecfe03ea73e)`(double want,double initial)` | Метод эмулируюший закон регулирования ПИД-регулятора

## Members

#### `public inline  `[`Regulator`](#classRegulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` {#classRegulator_1a2f9dccd70ab29b72793e37803ef0f0f0}

#### `public inline void `[`Regulate`](#classRegulator_1a69ec58971802ba66f7441ecfe03ea73e)`(double want,double initial)` {#classRegulator_1a69ec58971802ba66f7441ecfe03ea73e}

Метод эмулируюший закон регулирования ПИД-регулятора

В методе используем закон регулирования и записываем результаты в файл 
#### Parameters
* `want` Желаемое значение 

* `initial` Стартовое значение

Код: 
```cpp
std::ofstream fout("results.txt");

      if (fout)
      {
          double ek;
          double ek1 = 0;
          double ek2 = 0;
          double y = initial;
          double u;
          Linear linear(0.333, 0.667, 1);
          fout << "Линейная модель: " << std::endl;
          for (int i = 0; i < 50; ++i)
          {
              ek = want - y;
              u = calculateControlSignal(ek, ek1, ek2);
              y = linear.modelFunc(initial, u);
              fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
              ek2 = ek1;
              ek1 = ek;
          }
          ek1 = 0;
          ek2 = 0;
          y = initial;
          Uk = 0;
          fout << "Нелинейная модель: " << std::endl;
          NonLinear nonLinear(1, 0.0033, 0.525, 0.525, 1);
          for (int i = 0; i < 50; i++)
          {
              ek = want - y;
              u = calculateControlSignal(ek, ek1, ek2);
              y = nonLinear.modelFunc(initial, u);
              fout << "E=" << ek << " Y=" << y << " U=" << u << std::endl;
              ek2 = ek1;
              ek1 = ek;
          }
          std::cout << "Успешно сохранено в results.txt" << std::endl;
      }
      else
      {
          std::cout << "Ошибка при сохранении данных в файловую систему" << std::endl;
      }
```

Generated by [Moxygen](https://sourcey.com/moxygen)