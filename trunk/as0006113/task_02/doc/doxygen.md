# Summary






 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbstMod`](#class_Abst_Mod) | Класс, который необходим классам, рассчитывающим линейную и нелинейную модель
`class `[`LinearMod`](#class_linear_Mod) | Класс, который служит для реализации линейной модели
`class `[`NonLinearMod`](#class_non_linear_Mod) | Класс, который служит для реализации нелинейной модели
`class `[`Regulator`](#class_regulator) | Класс регулятора

# class `AbstMod` 




Класс, который необходим классам, рассчитывающим линейную и нелинейную модель








Абстрактный класс, который предоставляет виртуальную функцию уравнения calculMod и от которого наследуются классы [LinearMod](#class_linear_Mod) и [NonLinearMod](#class_non_linear_Mod)




## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~AbstMod`](#class_Abst_Mod_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` | 



             
`public double `[`calculMod`](#class_Abst_Mod_1acfab24a843dd017565c12aa96fd12f64)`(double yCurrent,double inputWarm)` | 





 
 
  Виртуальная функция, переопределенная в дочерних классах [LinearMod](#class_linear_Mod) и [NonLinearMod](#class_non_linear_Mod).

## Members

#### `public virtual  `[`~AbstMod`](#class_Abst_Mod_1a70c0c5f53c7edb56bf68838d46de366b)`() = default` 



                             
#### `public double `[`calculMod`](#class_Abst_Mod_1acfab24a843dd017565c12aa96fd12f64)`(double yCurrent,double inputWarm)` 

                  

Виртуальная функция, переопределенная в дочерних классах [LinearMod](#class_linear_Mod) и [NonLinearMod](#class_non_linear_Mod).




                                
Функция переопределяется в дочерних классах и служит для рассчета линейной/нелинейной модели. 
#### Parameters
* `yCurrent` Температура помещения 




* `inputWarm` Входящее тепло








# class `LinearMod` 

```
class LinearMod
  : public AbstMod
```  

Класс, который служит для реализации линейной модели





Дочерний класс от [AbstMod](#class_Abst_Mod), который реализует линейную модель через переопределённую функцию calculMod



## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearMod`](#class_linear_Mod_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` | 




`public inline virtual double `[`calculMod`](#class_linear_Mod_1a12095f9b671e6165eafc72f86bc7b8f5)`(double yCurrent,double inputWarm)` | Переопределённый метод для рассчёта линейной модели



## Members

#### `public inline  `[`LinearMod`](#class_linear_Mod_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` 





#### `public inline virtual double `[`calculMod`](#class_linear_Mod_1a12095f9b671e6165eafc72f86bc7b8f5)`(double yCurrent,double inputWarm)` 




Переопределённый метод для рассчёта линейной модели






Код: 
```cpp
yNext_ = a___ * yCurrent + b___ * inputWarm;
return yNext_;
```
                      





# class `NonLinearMod` 

```
class NonLinearMod
  : public AbstMod
```  





Класс, который служит для реализации нелинейной модели

Дочерний класс от [AbstMod](#class_Abst_Mod), который реализует нелинейную модель через переопределённую функцию calculMod




                           
## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinearMod`](#class_non_linear_Mod_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` | 



`public inline virtual double `[`calculMod`](#class_non_linear_Mod_1a9bad4ace82cde16f0631b9590e928d14)`(double yCurrent,double inputWarm)` | 



Переопределённый метод для рассчёта нелинейной модели

                               

## Members





#### `public inline  `[`NonLinearMod`](#class_non_linear_Mod_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` 




#### `public inline virtual double `[`calculMod`](#class_non_linear_Mod_1a9bad4ace82cde16f0631b9590e928d14)`(double yCurrent,double inputWarm)` 






Переопределённый метод для рассчёта нелинейной модели



                           
Код: 
```cpp
yNext_ = a___ * yCurrent - b___ * pow(yPrev_, 2) + c___ * inputWarm + d___ * sin(wPrev_);
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




`public inline void `[`PIDRegulatorcalculAndWrite`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)` | 

## Members

#### `public inline  `[`Regulator`](#class_regulator_1a2f9dccd70ab29b72793e37803ef0f0f0)`(double T,double T0,double TD,double K)` 





#### `public inline void `[`PIDRegulatorcalculAndWrite`](#class_regulator_1a4b9d368fc11c81701f7ac70d3035227b)`(double need,double start)`







Generated by [Moxygen](https://sourcey.com/moxygen)