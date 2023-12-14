# Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`ModelLinerValue`](#class_model_liner_value) | Linear model class.
`class `[`NotModelLinerValue`](#class_not_model_liner_value) | The class of a non-linear model.
`class `[`Object`](#class_object) | abstract model class
`class `[`Regulator`](#class_regulator) | The controller's PID class.

# class `ModelLinerValue` 

```
class ModelLinerValue
  : public Object
```  

Linear model class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`a`](#class_model_liner_value_1aa8888835392c1d35b59429dceace77bb) | 
`public double `[`b`](#class_model_liner_value_1aa569e962a2e48ac7f2641aaff730e6f2) | 
`public inline  `[`ModelLinerValue`](#class_model_liner_value_1ad8f1c91b6232081915c0619f3b77b9fa)`(double a,double b)` | 
`public  `[`~ModelLinerValue`](#class_model_liner_value_1a3f49bd2ac08e61b3bd287fa98889a229)`() = default` | 
`public inline virtual double `[`ModelFunction`](#class_model_liner_value_1ab04efd8533b055ebe608772cbb092b06)`(double yt,double ut)` | 
`public inline virtual void `[`OutputModel`](#class_model_liner_value_1a8f870ca8c4343fb79b54a3845c277168)`(double y,double u,int NumLin)` | 

## Members

#### `public double `[`a`](#class_model_liner_value_1aa8888835392c1d35b59429dceace77bb) 

#### `public double `[`b`](#class_model_liner_value_1aa569e962a2e48ac7f2641aaff730e6f2) 

#### `public inline  `[`ModelLinerValue`](#class_model_liner_value_1ad8f1c91b6232081915c0619f3b77b9fa)`(double a,double b)` 

#### `public  `[`~ModelLinerValue`](#class_model_liner_value_1a3f49bd2ac08e61b3bd287fa98889a229)`() = default` 

#### `public inline virtual double `[`ModelFunction`](#class_model_liner_value_1ab04efd8533b055ebe608772cbb092b06)`(double yt,double ut)` 

#### `public inline virtual void `[`OutputModel`](#class_model_liner_value_1a8f870ca8c4343fb79b54a3845c277168)`(double y,double u,int NumLin)` 

# class `NotModelLinerValue` 

```
class NotModelLinerValue
  : public Object
```  

The class of a non-linear model.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public double `[`a`](#class_not_model_liner_value_1a7117af67016ef70619ae134a71ca7ef2) | 
`public double `[`b`](#class_not_model_liner_value_1a353d5452baa497a5e3d972e40896bb73) | 
`public double `[`prev_ut`](#class_not_model_liner_value_1a0f6220bfbf2e7cb6561f674391eb6783) | 
`public double `[`prev_yt`](#class_not_model_liner_value_1a621f1fd3266c03fb7739063f94c50131) | 
`public double `[`c`](#class_not_model_liner_value_1af705a9c18b995435615afc011ec264ce) | 
`public double `[`d`](#class_not_model_liner_value_1a6cbfaab913bfc82c3e917030f8259e0c) | 
`public inline  `[`NotModelLinerValue`](#class_not_model_liner_value_1ab7267ce0aad0b458f5ee07fac23c6a1d)`(double a,double b,double c,double d)` | 
`public  `[`~NotModelLinerValue`](#class_not_model_liner_value_1a70e44c48441b7569c91d1aa1e0be3fca)`() = default` | 
`public inline virtual double `[`ModelFunction`](#class_not_model_liner_value_1afe20de33c3443c597a0f50da3c6f1541)`(double yt,double ut)` | 
`public inline virtual void `[`OutputModel`](#class_not_model_liner_value_1a0605f532f6acd82f4adfd134e2b1b4c3)`(double y,double u,int NotNumLin)` | 

## Members

#### `public double `[`a`](#class_not_model_liner_value_1a7117af67016ef70619ae134a71ca7ef2) 

#### `public double `[`b`](#class_not_model_liner_value_1a353d5452baa497a5e3d972e40896bb73) 

#### `public double `[`prev_ut`](#class_not_model_liner_value_1a0f6220bfbf2e7cb6561f674391eb6783) 

#### `public double `[`prev_yt`](#class_not_model_liner_value_1a621f1fd3266c03fb7739063f94c50131) 

#### `public double `[`c`](#class_not_model_liner_value_1af705a9c18b995435615afc011ec264ce) 

#### `public double `[`d`](#class_not_model_liner_value_1a6cbfaab913bfc82c3e917030f8259e0c) 

#### `public inline  `[`NotModelLinerValue`](#class_not_model_liner_value_1ab7267ce0aad0b458f5ee07fac23c6a1d)`(double a,double b,double c,double d)` 

#### `public  `[`~NotModelLinerValue`](#class_not_model_liner_value_1a70e44c48441b7569c91d1aa1e0be3fca)`() = default` 

#### `public inline virtual double `[`ModelFunction`](#class_not_model_liner_value_1afe20de33c3443c597a0f50da3c6f1541)`(double yt,double ut)` 

#### `public inline virtual void `[`OutputModel`](#class_not_model_liner_value_1a0605f532f6acd82f4adfd134e2b1b4c3)`(double y,double u,int NotNumLin)` 

# class `Object` 

abstract model class

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public virtual  `[`~Object`](#class_object_1a226f2ae2af766b77d83c09a4d766b725)`() = default` | 
`public double `[`ModelFunction`](#class_object_1a5889b27e7b6d8c7251a61390fd39e302)`(double Yt,double Ut)` | 
`public void `[`OutputModel`](#class_object_1a9e4fc9aca9fc6b4ae8298f77db8de81d)`(double y,double u,int NumLin)` | 

## Members

#### `public virtual  `[`~Object`](#class_object_1a226f2ae2af766b77d83c09a4d766b725)`() = default` 

#### `public double `[`ModelFunction`](#class_object_1a5889b27e7b6d8c7251a61390fd39e302)`(double Yt,double Ut)` 

#### `public void `[`OutputModel`](#class_object_1a9e4fc9aca9fc6b4ae8298f77db8de81d)`(double y,double u,int NumLin)` 

# class `Regulator` 

The controller's PID class.

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline void `[`Regulating`](#class_regulator_1aa1fea003c9080aa31d1182873d670a0d)`(double w,double y0,`[`Object`](#class_object)` & obj)` | 

## Members

#### `public inline void `[`Regulating`](#class_regulator_1aa1fea003c9080aa31d1182873d670a0d)`(double w,double y0,`[`Object`](#class_object)` & obj)` 

Generated by [Moxygen](https://sourcey.com/moxygen)