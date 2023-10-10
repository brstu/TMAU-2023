# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbstractModel`](#class_abstract_model) | Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
`class `[`LinearModel`](#class_linear_model) | Класс, который служит для реализации линейной модели
`class `[`NonLinearModel`](#class_non_linear_model) | Класс, который служит для реализации нелинейной модели
`class `[`Regulator`](#class_regulator) | Класс регулятора

# class `AbstractModel` 

Класс, который необходим классам, рассчитывающим линейную и нелинейную модель

Абстрактный класс, который предоставляет виртуальную функцию уравнения calculateModel и от которого наследуются классы [LinearModel](#class_linear_model) и [NonLinearModel](#class_non_linear_model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`calculateModel`](#class_abstract_model_1acfab24a843dd017565c12aa96fd12f64)`(double yCurrent,double inputWarm)` | Виртуальная функция, переопределенная в дочерних классах [LinearModel](#class_linear_model) и [NonLinearModel](#class_non_linear_model).

## Members

#### `public double `[`calculateModel`](#class_abstract_model_1acfab24a843dd017565c12aa96fd12f64)`(double yCurrent,double inputWarm)` 

Виртуальная функция, переопределенная в дочерних классах [LinearModel](#class_linear_model) и [NonLinearModel](#class_non_linear_model).

Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели. 
#### Parameters
* `yCurrent` Температура помещения 

* `inputWarm` Входящее тепло

# class `LinearModel` 

```
class LinearModel
  : public AbstractModel
```  

Класс, который служит для реализации линейной модели

Дочерний класс от [AbstractModel](#class_abstract_model), который реализует линейную модель через переопределённую функцию calculateModel

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearModel`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` | 
`public inline virtual double `[`calculateModel`](#class_linear_model_1a0d8fba6c6f1d6d9eb23f7a33e20f1d7e)`(double yCurrent,double inputWarm)` | Переопределённый метод для рассчёта линейной модели

## Members

#### `public inline  `[`LinearModel`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 

#### `public inline virtual double `[`calculateModel`](#class_linear_model_1a0d8fba6c6f1d6d9eb23f7a33e20f1d7e)`(double yCurrent,double inputWarm)` 

Переопределённый метод для рассчёта линейной модели

Код: 
```cpp
yNext_ = a_ * yCurrent + b_ * inputWarm;
return yNext_;
```

# class `NonLinearModel` 

```
class NonLinearModel
  : public AbstractModel
```  

Класс, который служит для реализации нелинейной модели

Дочерний класс от [AbstractModel](#class_abstract_model), который реализует нелинейную модель через переопределённую функцию calculateModel

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinearModel`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` | 
`public inline virtual double `[`calculateModel`](#class_non_linear_model_1ac48d7e25a35fcc57b8288de331865025)`(double yCurrent,double inputWarm)` | Переопределённый метод для рассчёта нелинейной модели

## Members

#### `public inline  `[`NonLinearModel`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` 

#### `public inline virtual double `[`calculateModel`](#class_non_linear_model_1ac48d7e25a35fcc57b8288de331865025)`(double yCurrent,double inputWarm)` 

Переопределённый метод для рассчёта нелинейной модели

Код: 
```cpp
yNext_ = a_ * yCurrent - b_ * pow(yPrev_, 2) + c_ * inputWarm + d_ * sin(wPrev_);
yPrev_ = yNext_;
wPrev_ = inputWarm;
return yNext_;
```

# class `Regulator` 

Класс регулятора

Отдельный класс, в котором мы моделируем регулятор

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` | 
`public inline void `[`PIDRegulatorCalculateAndWrite`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` | 

## Members

#### `public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` 

#### `public inline void `[`PIDRegulatorCalculateAndWrite`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` 

Generated by [Moxygen](https://sourcey.com/moxygen)