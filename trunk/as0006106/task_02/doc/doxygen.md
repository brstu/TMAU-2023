# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`LinearModel`](#class_linear_model) | Линейная модель контроля температуры
`class `[`Model`](#class_model) | Обстрактный класс модели
`class `[`NonlinearModel`](#class_nonlinear_model) | Линейная модель контроллера температуры
`class `[`PIDregulator`](#class_p_i_dregulator) | Proportional–integral–derivative регулятор
------------------------------------------------------------------------------
# class `LinearModel` 
_
```
class LinearModel
  : public Model
```  
_
_
_
Линейная модель контроля температуры
_
_
_
_
_

## Summary
_
_
_
_
 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearModel`](#class_linear_model_1a354c216624723c40fa18004290d97941)`(double a,double b)` | Конструктор класса [LinearModel](#class_linear_model).
`public inline virtual double `[`simulate_temperature`](#class_linear_model_1a4f7bb9064ad7490ab43980ac00a392be)`(double Yt,double Uw)` | Этот переопределенный метод возвращает значение температуры по Линейной симуляци
`public  `[`~LinearModel`](#class_linear_model_1a4a9d9e4e2ce4e51ed5a1e70aebdece31)`() = default` | Деструктор для класса [LinearModel](#class_linear_model).
_
_
_
## Members
_
_
_
#### `public inline  `[`LinearModel`](#class_linear_model_1a354c216624723c40fa18004290d97941)`(double a,double b)` 
_
_
_
_
_
Конструктор класса [LinearModel](#class_linear_model).
_
#### Parameters
* `a` `b` some constants
_
_
_
#### `public inline virtual double `[`simulate_temperature`](#class_linear_model_1a4f7bb9064ad7490ab43980ac00a392be)`(double Yt,double Uw)` 
_
_
_
Этот переопределенный метод возвращает значение температуры по Линейной симуляци
_
_
_
_
#### `public  `[`~LinearModel`](#class_linear_model_1a4a9d9e4e2ce4e51ed5a1e70aebdece31)`() = default` 

Деструктор для класса [LinearModel](#class_linear_model).

# class `Model` 

Обстрактный класс модели
------------------------------------------------------------------------------



Модель используется для представления других моделей

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`simulate_temperature`](#class_model_1a5a90c717f9a81a28dc7c01e83d60c507)`(double Yt,double Uw)` | Виртуальная функция для определения температуры
`public virtual  `[`~Model`](#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` | Деструктор модели

## Members

#### `public double `[`simulate_temperature`](#class_model_1a5a90c717f9a81a28dc7c01e83d60c507)`(double Yt,double Uw)` 



Виртуальная функция для определения температуры

#### Parameters
* `Yt` Входная температура 

* `Uw` Входное количество тепло 




#### Returns
double Выходная информация о температуре

#### `public virtual  `[`~Model`](#class_model_1a2efbe4ec768191fa70ad86f260ec2fd6)`() = default` 

Деструктор модели
_
------------------------------------------------------------------------------
_
# class `NonlinearModel` 




```
class NonlinearModel
  : public Model
```  

Линейная модель контроллера температуры




## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonlinearModel`](#class_nonlinear_model_1a9f3a611ca0c92ff58940e6c17e2ee55d)`(double a,double b,double c,double d)` | Конструктор класса NonLinearModel.
`public inline virtual double `[`simulate_temperature`](#class_nonlinear_model_1a5fc532df0aa33e129ce6721d536922bf)`(double Yt,double Uw)` | Этот переопределенный метод для определения температуры по Нелинейной модели
`public  `[`~NonlinearModel`](#class_nonlinear_model_1afd13796ba2713bd1487745ad03dbf034)`() = default` | Destroy the [NonlinearModel](#class_nonlinear_model) object.

## Members




#### `public inline  `[`NonlinearModel`](#class_nonlinear_model_1a9f3a611ca0c92ff58940e6c17e2ee55d)`(double a,double b,double c,double d)` 

Конструктор класса NonLinearModel.

#### Parameters
* `a` `b` `c` `d` some constants




#### `public inline virtual double `[`simulate_temperature`](#class_nonlinear_model_1a5fc532df0aa33e129ce6721d536922bf)`(double Yt,double Uw)` 

Этот переопределенный метод для определения температуры по Нелинейной модели



#### `public  `[`~NonlinearModel`](#class_nonlinear_model_1afd13796ba2713bd1487745ad03dbf034)`() = default` 

Destroy the [NonlinearModel](#class_nonlinear_model) object.

# class `PIDregulator` 

Proportional–integral–derivative регулятор

## Summary



 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline void `[`Regulate`](#class_p_i_dregulator_1a237cb281c5134ada08cee584ac6cfb2b)`(double w,double y0,`[`Model`](#class_model)` & model)` | Регулятор моделирования



## Members

#### `public inline void `[`Regulate`](#class_p_i_dregulator_1a237cb281c5134ada08cee584ac6cfb2b)`(double w,double y0,`[`Model`](#class_model)` & model)` 



------------------------------------------------------------------------------
Регулятор моделирования




#### Parameters
* `w` желаемое значение 

* `y0` начальная температура 

* `model` линейная или нелинейная модель

Generated by [Moxygen](https://sourcey.com/moxygen)
