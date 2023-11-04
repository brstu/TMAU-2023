# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`abstract_model_pid`](#class_abstract_model) | Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
`class `[`linear_model_pid`](#class_linear_model) | Класс, который служит для реализации линейной модели
`class `[`nonlinear_model_pid`](#class_non_linear_model) | Класс, который служит для реализации нелинейной модели
`class `[`Regulator`](#class_regulator) | Класс регулятора

# class `abstract_model_pid` 

Класс, который необходим классам, рассчитывающим линейную и нелинейную модель

Абстрактный класс, который предоставляет виртуальную функцию уравнения calculate_pid_model и от которого наследуются классы [linear_model_pid](#class_linear_model) и [nonlinear_model_pid](#class_non_linear_model)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~abstract_model_pid`](#class_abstract_model_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` | 
`public double `[`calculate_pid_model`](#class_abstract_model_1acfab24a843dd017565c12aa96fd12f64)`(double curr_temp,double warm_input)` | Виртуальная функция, переопределенная в дочерних классах [linear_model_pid](#class_linear_model) и [nonlinear_model_pid](#class_non_linear_model).

## Members

#### `public virtual  `[`~abstract_model_pid`](#class_abstract_model_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` 

#### `public double `[`calculate_pid_model`](#class_abstract_model_1acfab24a843dd017565c12aa96fd12f64)`(double curr_temp,double warm_input)` 

Виртуальная функция, переопределенная в дочерних классах [linear_model_pid](#class_linear_model) и [nonlinear_model_pid](#class_non_linear_model).

Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели. 
#### Parameters
* `curr_temp` Температура помещения 

* `warm_input` Входящее тепло

# class `linear_model_pid` 

```
class linear_model_pid
  : public abstract_model_pid
```  

Класс, который служит для реализации линейной модели

Дочерний класс от [abstract_model_pid](#class_abstract_model), который реализует линейную модель через переопределённую функцию calculate_pid_model

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`linear_model_pid`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` | 
`public inline virtual double `[`calculate_pid_model`](#class_linear_model_1a12095f9b671e6165eafc72f86bc7b8f5)`(double curr_temp,double warm_input)` | Переопределённый метод для рассчёта линейной модели

## Members

#### `public inline  `[`linear_model_pid`](#class_linear_model_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 

#### `public inline virtual double `[`calculate_pid_model`](#class_linear_model_1a12095f9b671e6165eafc72f86bc7b8f5)`(double curr_temp,double warm_input)` 

Переопределённый метод для рассчёта линейной модели

Код: 
```cpp
yNext_ = a_ * curr_temp + b_ * warm_input;
return yNext_;
```

# class `nonlinear_model_pid` 

```
class nonlinear_model_pid
  : public abstract_model_pid
```  

Класс, который служит для реализации нелинейной модели

Дочерний класс от [abstract_model_pid](#class_abstract_model), который реализует нелинейную модель через переопределённую функцию calculate_pid_model

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`nonlinear_model_pid`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` | 
`public inline virtual double `[`calculate_pid_model`](#class_non_linear_model_1a9bad4ace82cde16f0631b9590e928d14)`(double curr_temp,double warm_input)` | Переопределённый метод для рассчёта нелинейной модели

## Members

#### `public inline  `[`nonlinear_model_pid`](#class_non_linear_model_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` 

#### `public inline virtual double `[`calculate_pid_model`](#class_non_linear_model_1a9bad4ace82cde16f0631b9590e928d14)`(double curr_temp,double warm_input)` 

Переопределённый метод для рассчёта нелинейной модели

Код: 
```cpp
yNext_ = a_ * curr_temp - b_ * pow(yPrev_, 2) + c_ * warm_input + d_ * sin(wPrev_);
yPrev_ = yNext_;
wPrev_ = warm_input;
return yNext_;
```

# class `Regulator` 

Класс регулятора

Отдельный класс, в котором мы моделируем регулятор

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` | 
`public inline void `[`pid_calculate_write`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` | 

## Members

#### `public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` 

#### `public inline void `[`pid_calculate_write`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` 

Generated by [Moxygen](https://sourcey.com/moxygen)