# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbsModPID`](#class_AbsModPID) | Данный класс, необходим классам, рассчитывающим линейную пид регулятора и нелинейную модель пид регулятора
`class `[`LinModPID`](#class_LinModPID) | Данный класс, служит для реализации линейной модели пид регулятора
`class `[`NonModPID`](#class_NonModPID) | Данный класс, служит для реализации нелинейной модели пид регулятора
`class `[`RegulPID`](#class_RegulPID) | Класс регулятора

# class `AbsModPID` 

Класс, который необходим классам, рассчитывающим линейную пид регулятора и нелинейную модель пид регулятора

Абстрактный класс предоставляет интерфейс, который содержит виртуальную функцию calcPIDMod. Этот класс является базовым классом, от которого будут наследоваться другие классы. [LinModPID](#class_LinModPID) и [NonModPID](#class_NonModPID)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~AbsModPID`](#class_AbsModPID_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` | 
`public double `[`calcPIDMod`](#class_AbsModPID_1acfab24a843dd017565c12aa96fd12f64)`(double curTemmmp,double warmInpuutt)` | Виртуальная функция, переопределенная в дочерних классах [LinModPID](#class_LinModPID) и [NonModPID](#class_NonModPID).

## Members
#### `public virtual  `[`~AbsModPID`](#class_AbsModPID_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` 
#### `public double `[`calcPIDMod`](#class_AbsModPID_1acfab24a843dd017565c12aa96fd12f64)`(double curTemmmp,double warmInpuutt)` 

Виртуальная функция, которая переопределена в дочерних классах, позволяет каждому дочернему классу предоставить свою собственную реализацию этой функции.  [LinModPID](#class_LinModPID) и [NonModPID](#class_NonModPID).
Функция, переопределенная в дочерних классах, выполняет рассчет линейной или нелинейной модели.

#### Parameters
* `curTemmmp` Температура помещения задданая на вход программы
* `warmInpuutt` Входящее тепло задданая на вход программы 

# class `LinModPID` 

```
class LinModPID
  : public AbsModPID
```  

Данный класс предназначен для реализации линейной модели. Он содержит методы и атрибуты, которые позволяют задать и вычислить параметры линейной модели, а также провести соответствующие операции и расчеты, связанные с линейной моделью.

Дочерний класс от [AbsModPID](#class_AbsModPID), который реализует линейную модель через переопределённую функцию calcPIDMod

## Summary
 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinModPID`](#class_LinModPID_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 
| 
`public inline virtual double `[`calcPIDMod`](#class_LinModPID_1a12095f9b671e6165eafc72f86bc7b8f5)`(double curTemmmp,double warmInpuutt)` | Переопределённый метод для рассчёта линейной модели пид регулятора

## Members

#### `public inline  `[`LinModPID`](#class_LinModPID_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 

#### `public inline virtual double `[`calcPIDMod`](#class_LinModPID_1a12095f9b671e6165eafc72f86bc7b8f5)`(double curTemmmp,double warmInpuutt)` 


Переопределённый  метод для рассчёта линейной модели пид регулятора


Код: 
```cpp
nextY___ = a_ * curTemmmp + b_ * warmInpuutt;
return nextY___;
```


# class `NonModPID` 


```
class NonModPID
  : public AbsModPID
```  

Данный класс предназначен для реализации нелинейной модели ПИД-регулятора

Дочерний  класс  от [AbsModPID](#class_AbsModPID), который  реализует  нелинейную модель  пид регулятора через переопределённую  функцию calcPIDMod

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonModPID`](#class_NonModPID_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` | 

`public inline virtual double `[`calcPIDMod`](#class_NonModPID_1a9bad4ace82cde16f0631b9590e928d14)`(double curTemmmp,double warmInpuutt)` | Переопределённый метод для рассчёта  нелинейной модели пид регулятора

## Members

#### `public inline  `[`NonModPID`](#class_NonModPID_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` 

#### `public inline virtual double `[`calcPIDMod`](#class_NonModPID_1a9bad4ace82cde16f0631b9590e928d14)`(double curTemmmp,double warmInpuutt)` 

В данном классе имеется переопределенный метод, который используется для расчета нелинейной модели ПИД-регулятора.

Код: 
```cpp
nextY___ = a_ * curTemmmp - b_ * pow(prevY___, 2) + c_ * warmInpuutt + d * sin(prevW__);
prevY___ = nextY___;
prevW__ = warmInpuutt;
return nextY___;
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

