# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`AbstractModel`](#classAbstractModel) | Класс, который рассчитывает значения моделей
`class `[`LinearModel`](#classLinearModel) | Класс, который наследуется от класса [AbstractModel](#classAbstractModel) и служит для реализации линейной модели через переопределение функции simulate.
`class `[`NonLinearModel`](#classNonLinearModel) | Класс, который наследуется от класса [AbstractModel](#classAbstractModel) и служит для реализации нелинейной модели через переопределение функции simulate.
`class `[`ParentModel`](#classParentModel) | 
`class `[`RegObject`](#classRegObject) | Класс, который реализует вычисление параметров моделей и вывод результатов в файл

# class `AbstractModel` {#classAbstractModel}

Класс, который рассчитывает значения моделей

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------

## Members

# class `LinearModel` {#classLinearModel}

```
class LinearModel
  : public ParentModel
```  

Класс, который наследуется от класса [AbstractModel](#classAbstractModel) и служит для реализации линейной модели через переопределение функции simulate.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`LinearModel`](#classLinearModel_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` | 
`public inline virtual double `[`simulate`](#classLinearModel_1ae36f9f41705b7eb1ce4281f57d4d4243)`(double y,double warm)` | Переопределённый метод, который рассчитывает значения линейной модели

## Members

#### `public inline  `[`LinearModel`](#classLinearModel_1aa21922a3dd7e060f69855043075d1db5)`(double a,double b,double yNext)` {#classLinearModel_1aa21922a3dd7e060f69855043075d1db5}

#### `public inline virtual double `[`simulate`](#classLinearModel_1ae36f9f41705b7eb1ce4281f57d4d4243)`(double y,double warm)` {#classLinearModel_1ae36f9f41705b7eb1ce4281f57d4d4243}

Переопределённый метод, который рассчитывает значения линейной модели

Код: 
```cpp
next_y = k_a * y + k_b * warm;
return next_y;
```

# class `NonLinearModel` {#classNonLinearModel}

```
class NonLinearModel
  : public ParentModel
```  

Класс, который наследуется от класса [AbstractModel](#classAbstractModel) и служит для реализации нелинейной модели через переопределение функции simulate.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`NonLinearModel`](#classNonLinearModel_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` | 
`public inline virtual double `[`simulate`](#classNonLinearModel_1a3743f88535deff85f6489b0711f8f074)`(double y,double warm)` | Переопределённый метод, который рассчитывает значения нелинейной модели

## Members

#### `public inline  `[`NonLinearModel`](#classNonLinearModel_1aa33bbbe3024131505d356c0df9dcd518)`(double a,double b,double c,double d,double yNext)` {#classNonLinearModel_1aa33bbbe3024131505d356c0df9dcd518}

#### `public inline virtual double `[`simulate`](#classNonLinearModel_1a3743f88535deff85f6489b0711f8f074)`(double y,double warm)` {#classNonLinearModel_1a3743f88535deff85f6489b0711f8f074}

Переопределённый метод, который рассчитывает значения нелинейной модели

Код: 
```cpp
next_y = k_a * y - k_b * pow(prev_y, 2) + k_c * warm + k_d * sin(prev_w);
prev_y = next_y;
prev_w = warm;
return next_y;
```

# class `ParentModel` {#classParentModel}

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~ParentModel`](#classParentModel_1ad87734503c159c4dd931335d9f1d11d4)`() = default` | 
`public double `[`simulate`](#classParentModel_1a1ca8895af8246381297cec9d9dce08d7)`(double y,double warm)` | Виртуальная функция, которая ассчитывает значения модели.

## Members

#### `public virtual  `[`~ParentModel`](#classParentModel_1ad87734503c159c4dd931335d9f1d11d4)`() = default` {#classParentModel_1ad87734503c159c4dd931335d9f1d11d4}

#### `public double `[`simulate`](#classParentModel_1a1ca8895af8246381297cec9d9dce08d7)`(double y,double warm)` {#classParentModel_1a1ca8895af8246381297cec9d9dce08d7}

Виртуальная функция, которая ассчитывает значения модели.

# class `RegObject` {#classRegObject}

Класс, который реализует вычисление параметров моделей и вывод результатов в файл

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline  `[`RegObject`](#classRegObject_1a50db2941e7c76f7c10036bffbabb3be6)`(double T,double T0,double TD,double K)` | 
`public inline void `[`writeModelsInFile`](#classRegObject_1a6979d5fc78c1147dc19f9b0af93b258a)`(double n,double begin)` | 

## Members

#### `public inline  `[`RegObject`](#classRegObject_1a50db2941e7c76f7c10036bffbabb3be6)`(double T,double T0,double TD,double K)` {#classRegObject_1a50db2941e7c76f7c10036bffbabb3be6}

#### `public inline void `[`writeModelsInFile`](#classRegObject_1a6979d5fc78c1147dc19f9b0af93b258a)`(double n,double begin)` {#classRegObject_1a6979d5fc78c1147dc19f9b0af93b258a}

Generated by [Moxygen](https://sourcey.com/moxygen)