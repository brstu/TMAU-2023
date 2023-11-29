# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Linear_Model`](#class_linear___model) | Линейная модель контроля температуры
`class `[`Model`](#class_model) | Класс абстрактной модели
`class `[`Nonlinear_Model`](#class_nonlinear___model) | Нелинейная модель контроля температуры
`class `[`PID_regulator`](#class_p_i_d__regulator) | Пропорциональный интегрально-производный регулятор

# class `Linear_Model` 

```
class Linear_Model
  : public Model
```  

Линейная модель контроля температуры

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Linear_Model`](#class_linear___model_1a052533ea1c91b1d1bd71b06f093851c4)`(double alpha,double beta)` | Строит новый объект [Linear_Model](#class_linear___model).
`public inline virtual double `[`simulate_temperature`](#class_linear___model_1ad00bcb0cf4912f386390249db3f7a623)`(double current_temp,double control_var)` | Метод расчета выходной температуры объекта линейной модели
`public  `[`~Linear_Model`](#class_linear___model_1ae6dcb5477d01b168643542af38a5c986)`() = default` | Удаляет объект [Linear_Model](#class_linear___model).

## Members

#### `public inline  `[`Linear_Model`](#class_linear___model_1a052533ea1c91b1d1bd71b06f093851c4)`(double alpha,double beta)` 

Строит новый объект [Linear_Model](#class_linear___model).

#### Parameters
* `alpha` Константа 

* `beta` Константа

#### `public inline virtual double `[`simulate_temperature`](#class_linear___model_1ad00bcb0cf4912f386390249db3f7a623)`(double current_temp,double control_var)` 

Метод расчета выходной температуры объекта линейной модели

#### `public  `[`~Linear_Model`](#class_linear___model_1ae6dcb5477d01b168643542af38a5c986)`() = default` 

Удаляет объект [Linear_Model](#class_linear___model).

# class `Model` 

Класс абстрактной модели

Модель используется для представления других моделей

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`simulate_temperature`](#class_model_1a05dd80149a1c8ec36fa75445bd4f7f47)`(double current_temp,double control_var)` | Виртуальная функция для определения температуры
`public virtual  `[`~Model`](#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` | 

## Members

#### `public double `[`simulate_temperature`](#class_model_1a05dd80149a1c8ec36fa75445bd4f7f47)`(double current_temp,double control_var)` 

Виртуальная функция для определения температуры

#### Parameters
* `current_temp` 

* `control_var` Температуры на входе 

#### Returns
Температуры на выходе

#### `public virtual  `[`~Model`](#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` 

# class `Nonlinear_Model` 

```
class Nonlinear_Model
  : public Model
```  

Нелинейная модель контроля температуры

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Nonlinear_Model`](#class_nonlinear___model_1a77abfdb8e0c6ba17422e8d906a1a64cb)`(double alpha,double beta,double gamma,double delta)` | Строит новый объект Nonl_inearModel.
`public inline virtual double `[`simulate_temperature`](#class_nonlinear___model_1aa9c68749a89504851dd2f18e2a63310d)`(double current_temp,double control_var)` | Метод расчета выходной температуры объекта нелинейной модели
`public  `[`~Nonlinear_Model`](#class_nonlinear___model_1a4388112ec9ef860bacbbd9facb3301a2)`() = default` | Удаляет объект NonlinearModel.

## Members

#### `public inline  `[`Nonlinear_Model`](#class_nonlinear___model_1a77abfdb8e0c6ba17422e8d906a1a64cb)`(double alpha,double beta,double gamma,double delta)` 

Строит новый объект Nonl_inearModel.

#### Parameters
* `alpha` Константа 

* `beta` Константа 

* `gamma` Константа 

* `delta` Константа

#### `public inline virtual double `[`simulate_temperature`](#class_nonlinear___model_1aa9c68749a89504851dd2f18e2a63310d)`(double current_temp,double control_var)` 

Метод расчета выходной температуры объекта нелинейной модели

#### `public  `[`~Nonlinear_Model`](#class_nonlinear___model_1a4388112ec9ef860bacbbd9facb3301a2)`() = default` 

Удаляет объект NonlinearModel.

# class `PID_regulator` 

 Пропорциональный интегрально-производный регулятор

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline void `[`Regulate`](#class_p_i_d__regulator_1ad00627e0300b8bebf1043c87194b0cb2)`(double desired_temp,double initial_temp,`[`Model`](#class_model)` & model)` | Регулятор моделирования

## Members

#### `public inline void `[`Regulate`](#class_p_i_d__regulator_1ad00627e0300b8bebf1043c87194b0cb2)`(double desired_temp,double initial_temp,`[`Model`](#class_model)` & model)` 

Регулятор моделирования

#### Parameters
* `desired_temp` Требуемое значение 

* `initial_temp` Начальная температура 

* `model` Линейная или нелинейная модель