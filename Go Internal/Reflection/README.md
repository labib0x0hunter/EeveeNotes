# Reflection
---
Rule
- Reflection goes from interface value to reflection object
```
interface{} -> reflect.Value, reflect.Type
```
- Reflection goes from reflection object to interface value
```
reflect.Value, reflect.Type -> interface{}
```