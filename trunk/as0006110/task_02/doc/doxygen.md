# SummaryNon_line_PID

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbsModPID`](#_class_abstract_model_) | Данный класс, необходим классам, рассчитывающим нелинейную пид регулятора и линейную модель пид регулятора
`class `[`Line_PID`](#_class_linear_model_) | Данный класс, служит для реализации линейной модели пид регулятора
`class `[`regulator_detka`](#_class_regulator_detka_) | Класс регулятора
`class `[`Non_line_PID`](#_class_non_linear_model_) | Данный класс, служит для реализации нелинейной модели пид регулятора








# class `AbsModPID` 

Класс, который необходим классам, рассчитывающим линейную пид регулятора и  модель пид регулятора

Абстрактный класс предоставляет интерфейс, который содержит виртуальную функцию _calculate_pid_model_. Этот класс является базовым классом, от которого будут наследоваться другие классы. [Line_PID](#_class_linear_model_) и [Non_line_PID](#_class_non_linear_model_)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~AbsModPID`](#_class_abstract_model__1a70c0c5f53c7edb56bf68838d46de366b)`() = default` | 
`public double `[`_calculate_pid_model_`](#_class_abstract_model__1acfab24a843dd017565c12aa96fd12f64)`(double current_temperature,double teplo_vhod)` | Виртуальная функция, переопределенная в дочерних классах [Line_PID](#_class_linear_model_) и [Non_line_PID](#_class_non_linear_model_).

## Members

#### `public virtual  `[`~AbsModPID`](#_class_abstract_model__1a70c0c5f53c7edb56bf68838d46de366b)`() = default` 

#### `public double `[`_calculate_pid_model_`](#_class_abstract_model__1acfab24a843dd017565c12aa96fd12f64)`(double current_temperature,double teplo_vhod)` 

Виртуальная функция, которая переопределена в дочерних классах, позволяет каждому дочернему классу предоставить свою собственную реализацию этой функции.  [Line_PID](#_class_linear_model_) и [Non_line_PID](#_class_non_linear_model_).

Функция, переопределенная в дочерних классах, выполняет рассчет линейной или нелинейной модели.
#### Parameters
* `current_temperature` Температура помещения задданая на вход программы

* `teplo_vhod` Входящее тепло задданая на вход программы 







# class `Line_PID` 

```
class Line_PID
  : public AbsModPID
```  




Данный класс предназначен для линейной модели. Он содержит методы и атрибуты, которые позволяют задать и вычислить параметры линейной модели, а также провести соответствующие операции и расчеты, связанные с линейной моделью.

Дочерний класс от [AbsModPID](#_class_abstract_model_), который реализует линейную модель через переопределённую функцию _calculate_pid_model_

## Summary


 Members                        | Descriptions                                                
--------------------------------|---------------------------------------------
`public inline  `[`Line_PID`](#_class_linear_model__1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 
| 
`public inline virtual double `[`_calculate_pid_model_`](#_class_linear_model__1a12095f9b671e6165eafc72f86bc7b8f5)`(double current_temperature,double teplo_vhod)` | Переопределённый метод для рассчёта линейной модели пид-регулятора


## Members

#### `public inline  `[`Line_PID`](#_class_linear_model__1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 

#### `public inline virtual double `[`_calculate_pid_model_`](#_class_linear_model__1a12095f9b671e6165eafc72f86bc7b8f5)`(double current_temperature,double teplo_vhod)` 


Переопределённый  метод для рассчёта линейной модели пид-регулятора




Код: 
```cpp
nextY__ = a_ * current_temperature + b_ * teplo_vhod;
return nextY__;
```








# class `Non_line_PID` 


```
class Non_line_PID
  : public AbsModPID
```         

Данный класс нежен для реализации нелинейной модели ПИД-регулятора

Дочерний  класс  от [AbsModPID](#_class_abstract_model_), который  реализует  нелинейную модель  пид регулятора через переопределённую  функцию _calculate_pid_model_

## Summary

 Members                        | Descriptions                                            
--------------------------------|---------------------------------------------
`public inline  `[`Non_line_PID`](#_class_non_linear_model__1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` | 

`public inline virtual double `[`_calculate_pid_model_`](#_class_non_linear_model__1a9bad4ace82cde16f0631b9590e928d14)`(double current_temperature,double teplo_vhod)` | Переопределённый метод для рассчёта  нелинейной модели пид регулятора

## Members

#### `public inline  `[`Non_line_PID`](#_class_non_linear_model__1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` 

#### `public inline virtual double `[`_calculate_pid_model_`](#_class_non_linear_model__1a9bad4ace82cde16f0631b9590e928d14)`(double current_temperature,double teplo_vhod)` 

В данном классе имеется переопределенный метод, который нужен для расчета нелинейной модели ПИД-регулятора.

Код:          
```cpp
nextY__ = a_ * current_temperature - b_ * pow(prevY__, 2) + c_ * teplo_vhod + d_ * sin(prevW__);
prevY__ = nextY__;
prevW__ = teplo_vhod;
return nextY__;
```






# class `regulator_detka` 

Класс регулятора

Этот класс это отдельный компонент, в котором реализовано моделирование регулятора. 

## Summary

 Members                        | Descriptions                                      
--------------------------------|---------------------------------------------
`public inline  `[`regulator_detka`](#_class_regulator_detka__1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` | 
`public inline void `[`pid_calculate_write`](#_class_regulator_detka__1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` | 


## Members

#### `public inline  `[`regulator_detka`](#_class_regulator_detka__1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` 

#### `public inline void `[`pid_calculate_write`](#_class_regulator_detka__1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` 

