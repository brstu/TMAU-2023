# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbsModPID`](#class_abstract_model) | Данный класс, необходим классам, рассчитывающим линейную пид регулятора и нелинейную модель пид регулятора
`class `[`LinModPID`](#class_linear_model) | Данный класс, служит для реализации линейной модели пид регулятора
`class `[`NonModPID`](#class_non_linear_model) | Данный класс, служит для реализации нелинейной модели пид регулятора
`class `[`RegulPID`](#class_RegulPID) | Класс регулятора

# class `AbsModPID` 

Класс, который необходим классам, рассчитывающим линейную пид регулятора и нелинейную модель пид регулятора

Абстрактный класс предоставляет интерфейс, который содержит виртуальную функцию calcPIDMod. Этот класс является базовым классом, от которого будут наследоваться другие классы. [LinModPID](#class_linear_model) и [NonModPID](#class_non_linear_model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~AbsModPID`](#class_abstract_model_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` | 
`public double `[`calcPIDMod`](#class_abstract_model_1acfab24a843dd017565c12aa96fd12f64)`(double curr_temp,double warm_input)` | Виртуальная функция, переопределенная в дочерних классах [LinModPID](#class_linear_model) и [NonModPID](#class_non_linear_model).

## Members

#### `public virtual  `[`~AbsModPID`](#class_abstract_model_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` 

#### `public double `[`calcPIDMod`](#class_abstract_model_1acfab24a843dd017565c12aa96fd12f64)`(double curr_temp,double warm_input)` 

Виртуальная функция, которая переопределена в дочерних классах, позволяет каждому дочернему классу предоставить свою собственную реализацию этой функции.  [LinModPID](#class_linear_model) и [NonModPID](#class_non_linear_model).

Функция, переопределенная в дочерних классах, выполняет рассчет линейной или нелинейной модели.
#### Parameters
* `curr_temp` Температура помещения задданая на вход программы

* `warm_input` Входящее тепло задданая на вход программы 

# class `LinModPID` 

```
class LinModPID
  : public AbsModPID
```  

Данный класс предназначен для реализации линейной модели. Он содержит методы и атрибуты, которые позволяют задать и вычислить параметры линейной модели, а также провести соответствующие операции и расчеты, связанные с линейной моделью.

Дочерний класс от [AbsModPID](#class_abstract_model), который реализует линейную модель через переопределённую функцию calcPIDMod

## Summary


 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinModPID`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 
| 
`public inline virtual double `[`calcPIDMod`](#class_linear_model_1a12095f9b671e6165eafc72f86bc7b8f5)`(double curr_temp,double warm_input)` | Переопределённый метод для рассчёта линейной модели пид регулятора


## Members

#### `public inline  `[`LinModPID`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 

#### `public inline virtual double `[`calcPIDMod`](#class_linear_model_1a12095f9b671e6165eafc72f86bc7b8f5)`(double curr_temp,double warm_input)` 


Переопределённый  метод для рассчёта линейной модели пид регулятора


Код: 
```cpp
nextY__ = a_ * curr_temp + b_ * warm_input;
return nextY__;
```


# class `NonModPID` 


```
class NonModPID
  : public AbsModPID
```  

Данный класс предназначен для реализации нелинейной модели ПИД-регулятора

Дочерний  класс  от [AbsModPID](#class_abstract_model), который  реализует  нелинейную модель  пид регулятора через переопределённую  функцию calcPIDMod

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonModPID`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` | 

`public inline virtual double `[`calcPIDMod`](#class_non_linear_model_1a9bad4ace82cde16f0631b9590e928d14)`(double curr_temp,double warm_input)` | Переопределённый метод для рассчёта  нелинейной модели пид регулятора

## Members

#### `public inline  `[`NonModPID`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` 

#### `public inline virtual double `[`calcPIDMod`](#class_non_linear_model_1a9bad4ace82cde16f0631b9590e928d14)`(double curr_temp,double warm_input)` 

В данном классе имеется переопределенный метод, который используется для расчета нелинейной модели ПИД-регулятора.

Код: 
```cpp
nextY__ = a_ * curr_temp - b_ * pow(prevY__, 2) + c_ * warm_input + d_ * sin(prevW__);
prevY__ = nextY__;
prevW__ = warm_input;
return nextY__;
```

# class `RegulPID` 

Класс регулятора

Этот класс представляет собой отдельный компонент, в котором реализовано моделирование регулятора. 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`RegulPID`](#class_RegulPID_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` | 
`public inline void `[`PIDCalcWrit`](#class_RegulPID_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` | 


## Members

#### `public inline  `[`RegulPID`](#class_RegulPID_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` 

#### `public inline void `[`PIDCalcWrit`](#class_RegulPID_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` 

