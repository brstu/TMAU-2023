# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`LinMod`](#class_lin_mod) | Класс, представляющий линейную модель объекта
`class `[`Models`](#class_models) | Абстрактный класс, который использоваться для построения линейных и нелинейных моделей
`class `[`NonLinMod`](#class_non_lin_mod) | Класс, представляющий нелинейную модель объекта
`class `[`Regulator`](#class_regulator) | Класс для воплощения регулятора

---------------------------------------------------------------------------------------------------------------------------

# class `LinMod` 

```
class LinMod
  : public Models
```  

Класс, который предоставляет линейную модель контролируемого объекта

Дочерний класс, благодаря которому расширяется класс [Models](#class_models)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinMod`](#class_lin_mod_1a9e6a00330d0b32712deebf9f84fc9567)`(float w,float e,float y_t1)` | конструктор для [LinMod](#class_lin_mod)
`public inline virtual float `[`equation`](#class_lin_mod_1a382c98a02f555215152a8897fa788369)`(float y_T,float u_T)` | функция вычисляет температуру благодаря линейной модели
`public  `[`~LinMod`](#class_lin_mod_1a7167974b1800c1986271fcba01e5a116)`() = default` | 

## Members

#### `public inline  `[`LinMod`](#class_lin_mod_1a9e6a00330d0b32712deebf9f84fc9567)`(float w,float e,float y_t1)` 

конструктор для [LinMod](#class_lin_mod)
#### Parameters
* `A` `B` - коэффициенты 

* `Y_t1` - температура на выходе

#### `public inline virtual float `[`equation`](#class_lin_mod_1a382c98a02f555215152a8897fa788369)`(float y_T,float u_T)` 

функция для вычисления температуры по линейной модели

#### `public  `[`~LinMod`](#class_lin_mod_1a7167974b1800c1986271fcba01e5a116)`() = default` 

---------------------------------------------------------------------------------------------------------------------------

# class `Models` 

Абстрактный класс, который будет использоваться для построения линейных и нелинейных моделей

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public float `[`equation`](#class_models_1a067ebfa9cecec0bfdec65dd9761dbec7)`(float y_t,float u_t)` | абстрактная функция предназначенная для переопределения в дочерних классах
`public virtual  `[`~Models`](#class_models_1a592249eafcf29aeb87675c913c4be06e)`() = default` | 

## Members

#### `public float `[`equation`](#class_models_1a067ebfa9cecec0bfdec65dd9761dbec7)`(float y_t,float u_t)` 

абстрактная функция для переопределения в дочерних классах

#### `public virtual  `[`~Models`](#class_models_1a592249eafcf29aeb87675c913c4be06e)`() = default` 

---------------------------------------------------------------------------------------------------------------------------

# class `NonLinMod` 

```
class NonLinMod
  : public Models
```  

Класс, представляющий нелинейную модель контролируемого объекта

Дочерний класс, служещий для расширения класса [Models](#class_models)

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinMod`](#class_non_lin_mod_1a827e2fe8b4503b1ad91669587249f4ae)`(float m,float a,float k,float s,float y_t1)` | конструктор [NonLinMod](#class_non_lin_mod)
`public inline virtual float `[`equation`](#class_non_lin_mod_1a68e1a1cf8ef96cf8b24d27f22081d0cc)`(float y_T,float u_T)` | функция которая вычисляет температуру по нелинейной модели
`public  `[`~NonLinMod`](#class_non_lin_mod_1a56c8677262fcd887a897720829f1e662)`() = default` | 

## Members

#### `public inline  `[`NonLinMod`](#class_non_lin_mod_1a827e2fe8b4503b1ad91669587249f4ae)`(float m,float a,float k,float s,float y_t1)` 

конструктор для [NonLinMod](#class_non_lin_mod)

#### `public inline virtual float `[`equation`](#class_non_lin_mod_1a68e1a1cf8ef96cf8b24d27f22081d0cc)`(float y_T,float u_T)` 

функция для вычисления температуры по нелинейной модели

#### Parameters
* `M` `A` `K` `S` - коэффициенты
* `Y_t0` - предыдущее(начальное) значение температуры
* `Y_t1` - текущее значение температуры на выходе
* `U_t0` - переменная для предыдущего значения тепла

#### `public  `[`~NonLinMod`](#class_non_lin_mod_1a56c8677262fcd887a897720829f1e662)`() = default` 

---------------------------------------------------------------------------------------------------------------------------

# class `Regulator` 

Класс который реализует регулятор

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`Regulator`](#class_regulator_1ad688597ba6a3eab7ad80cd647e25cdc9)`(float T,float T0,float TD,float K)` | конструктор для [Regulator](#class_regulator)
`public inline float `[`temperature`](#class_regulator_1aee0dd8d239c33e2999b1051e1803f6a6)`(float mt,float mt1,float mt2)` | функция для подсчёта управляющей переменной 

## Members

#### `public inline  `[`Regulator`](#class_regulator_1ad688597ba6a3eab7ad80cd647e25cdc9)`(float T,float T0,float TD,float K)` 

конструктор для [Regulator](#class_regulator)
#### Parameters
* `_K_` `_T0_` `_TD_` `_T_` : коэффициент передачи, шаг, постоянная диференцирования, постоянная интегрирования

#### `public inline float `[`temperature`](#class_regulator_1aee0dd8d239c33e2999b1051e1803f6a6)`(float mt,float mt1,float mt2)` 

функция для подсчёта управляющей переменной 
#### Parameters
* `mt` `mt1` `mt2` - это значения ошибок: текущей, прошлой, позапрошлой

Generated by [Moxygen](https://sourcey.com/moxygen)