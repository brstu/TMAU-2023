# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbstractModelPID`](#class_abstract_model) | Данный класс, необходим классам, рассчитывающим линейную пид регулятора и нелинейную модель пид регулятора
`class `[`LinearModelPID`](#class_linear_model) | Данный класс, служит для реализации линейной модели пид регулятора
`class `[`NonlinearModelPID`](#class_non_linear_model) | Данный класс, служит для реализации нелинейной модели пид регулятора
`class `[`Regulator`](#class_regulator) | Класс регулятора

# class `AbstractModelPID` 

Класс, который необходим классам, рассчитывающим линейную пид регулятора и нелинейную модель пид регулятора

Абстрактный класс предоставляет интерфейс, который содержит виртуальную функцию calculate_pid_model. Этот класс является базовым классом, от которого будут наследоваться другие классы. [LinearModelPID](#class_linear_model) и [NonlinearModelPID](#class_non_linear_model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~AbstractModelPID`](#class_abstract_model_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` | 
`public double `[`calculate_pid_model`](#class_abstract_model_1acfab24a843dd017565c12aa96fd12f64)`(double curr_temp,double warm_input)` | Виртуальная функция, переопределенная в дочерних классах [LinearModelPID](#class_linear_model) и [NonlinearModelPID](#class_non_linear_model).

## Members

#### `public virtual  `[`~AbstractModelPID`](#class_abstract_model_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` 

#### `public double `[`calculate_pid_model`](#class_abstract_model_1acfab24a843dd017565c12aa96fd12f64)`(double curr_temp,double warm_input)` 

Виртуальная функция, которая переопределена в дочерних классах, позволяет каждому дочернему классу предоставить свою собственную реализацию этой функции.  [LinearModelPID](#class_linear_model) и [NonlinearModelPID](#class_non_linear_model).

Функция, переопределенная в дочерних классах, выполняет рассчет линейной или нелинейной модели.
#### Parameters
* `curr_temp` Температура помещения задданая на вход программы

* `warm_input` Входящее тепло задданая на вход программы 

# class `LinearModelPID` 

```
class LinearModelPID
  : public AbstractModelPID
```  

Данный класс предназначен для реализации линейной модели. Он содержит методы и атрибуты, которые позволяют задать и вычислить параметры линейной модели, а также провести соответствующие операции и расчеты, связанные с линейной моделью.

Дочерний класс от [AbstractModelPID](#class_abstract_model), который реализует линейную модель через переопределённую функцию calculate_pid_model

## Summary


 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearModelPID`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 
| 
`public inline virtual double `[`calculate_pid_model`](#class_linear_model_1a12095f9b671e6165eafc72f86bc7b8f5)`(double curr_temp,double warm_input)` | Переопределённый метод для рассчёта линейной модели пид регулятора


## Members

#### `public inline  `[`LinearModelPID`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 

#### `public inline virtual double `[`calculate_pid_model`](#class_linear_model_1a12095f9b671e6165eafc72f86bc7b8f5)`(double curr_temp,double warm_input)` 


Переопределённый  метод для рассчёта линейной модели пид регулятора


Код: 
```cpp
nextY__ = a_ * curr_temp + b_ * warm_input;
return nextY__;
```


# class `NonlinearModelPID` 


```
class NonlinearModelPID
  : public AbstractModelPID
```  

Данный класс предназначен для реализации нелинейной модели ПИД-регулятора

Дочерний  класс  от [AbstractModelPID](#class_abstract_model), который  реализует  нелинейную модель  пид регулятора через переопределённую  функцию calculate_pid_model

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonlinearModelPID`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` | 

`public inline virtual double `[`calculate_pid_model`](#class_non_linear_model_1a9bad4ace82cde16f0631b9590e928d14)`(double curr_temp,double warm_input)` | Переопределённый метод для рассчёта  нелинейной модели пид регулятора

## Members

#### `public inline  `[`NonlinearModelPID`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` 

#### `public inline virtual double `[`calculate_pid_model`](#class_non_linear_model_1a9bad4ace82cde16f0631b9590e928d14)`(double curr_temp,double warm_input)` 

В данном классе имеется переопределенный метод, который используется для расчета нелинейной модели ПИД-регулятора.

Код: 
```cpp
nextY__ = a_ * curr_temp - b_ * pow(prevY__, 2) + c_ * warm_input + d_ * sin(prevW__);
prevY__ = nextY__;
prevW__ = warm_input;
return nextY__;
```

# class `Regulator` 

Класс регулятора

Этот класс представляет собой отдельный компонент, в котором реализовано моделирование регулятора. 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` | 
`public inline void `[`pid_calculate_write`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` | 


## Members

#### `public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` 

#### `public inline void `[`pid_calculate_write`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` 

