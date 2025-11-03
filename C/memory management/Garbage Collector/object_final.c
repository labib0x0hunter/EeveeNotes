#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct Object object_t; // alias for ordering

// length and data
typedef struct Array {
	int len;
	object_t** data;	// (object*) * 
} array_t;

// combination of 3 objects.
typedef struct Vector3 {
	object_t* x;
	object_t* y;
	object_t* z;
} vector3_t;

// object kind, what kind of data type
typedef enum {
	INT,
	FLOAT,
	STRING,
	ARRAY,
	VECTOR3,
} object_kind_t;

// object value, original value of the object
typedef union {
	int v_int;
	float v_float;
	char* v_string;
	array_t v_array;
	vector3_t v_vector3;
} object_data_t;

// object, it stores the data and metadata of itself
struct Object {
	object_kind_t Kind;	// what kind of object
	object_data_t Data;	// Actual value
};

object_t* NewObjectInt(int val) {
	object_t* obj = (object_t*) malloc(sizeof(object_t));
	if (obj == NULL) {
		return NULL;
	}
	obj->Kind = INT;
	obj->Data.v_int = val;
	return obj;
}

object_t* NewObjectFloat(float val) {
	object_t* obj = (object_t*) malloc(sizeof(object_t));
	if (obj == NULL) {
		return NULL;
	}
	obj->Kind = FLOAT;
	obj->Data.v_float = val;
	return obj;
}

object_t* NewObjectString(char* val) {
	object_t* obj = (object_t*) malloc(sizeof(object_t));
	if (obj == NULL) {
		return NULL;
	}
	obj->Kind = STRING;
	obj->Data.v_string = val;	// is there any problem ?? we just copied the pointer to obj.
								// or just strcpy() string...
	return obj;
}

object_t* NewObjectArray(int size) {
	object_t* obj = (object_t*) malloc(sizeof(object_t));
	if (obj == NULL) {
		return NULL;
	}
	obj->Kind = ARRAY;
	obj->Data.v_array.len = size;
	obj->Data.v_array.data = (object_t*) malloc(sizeof(object_t) * size);
	if (obj->Data.v_array.data == NULL) {
		free(obj);
		return NULL;
	}
	return obj;
}

object_t* NewObjectVector3(object_t* x, object_t* y, object_t* z) {
	if (x == NULL || y == NULL || z == NULL) {
		return NULL;
	}
	object_t* obj = (object_t*) malloc(sizeof(object_t));
	if (obj == NULL) {
		return NULL;
	}
	obj->Kind = VECTOR3;
	obj->Data.v_vector3.x = x;
	obj->Data.v_vector3.y = y;
	obj->Data.v_vector3.z = z;
	return obj;
}

// obj[index] = val
bool set_array(object_t* obj, int index, object_t* val) {
	if (obj == NULL || val == NULL) return false;
	if (obj->Kind != ARRAY) return false;
	if (index >= obj->Data.v_array.len) return false;
	obj->Data.v_array.data[index] = val;
	return true;
}

// retrive obj[index]
object_t* get_array(object_t* obj, int index) {
	if (obj == NULL) return NULL;
	if (obj->Kind != ARRAY) return NULL;
	if (index >= obj->Data.v_array.len) return NULL;
	return obj->Data.v_array.data[index];
}

// length of object
int len(object_t* obj) {
	if (obj == NULL) return -1;
	switch (obj->Kind) {
		case INT:
			return 1;
		case FLOAT:
			return 1;
		case STRING:
			return strlen(obj->Data.v_string);
		case ARRAY:
			return obj->Data.v_array.len;
		case VECTOR3:
			return 3;
		default:
			return -1;
	}
}

// merge two objects of same kind except INT and FLOAT..
object_t* add(object_t* a, object_t* b) {
	if (a == NULL && b == NULL) return NULL;
	// if (a->Kind != b->Kind) return NULL;

	switch (a->Kind) {
		case INT: {
			switch (b->Kind) {
				default:
					return NULL;
			}
			break;
		}
		case FLOAT: {
			switch (b->Kind) {
				default:
					return NULL;
			}
			break;
		}
		case STRING: {
			if (b->Kind != STRING) return NULL;
			break;
		}
		case ARRAY: {
			if (b->Kind != ARRAY) return NULL;
			break;
		}
		case VECTOR3: {
			if (b->Kind != VECTOR3) return NULL;
			break;
		}
		default:
			return NULL;
	}
}

// Print
void PrintObject(object_t* obj, char delim) {
	if (obj == NULL) {
		return;
	}
	switch (obj->Kind) {
		case INT:
			printf("%d%c", obj->Data.v_int, delim);
			break;
		case FLOAT:
			printf("%0.3f%c", obj->Data.v_float, delim);
			break;
		case ARRAY:
			for (int i = 0; i < obj->Data.v_array.len; i++) {
				PrintObject(obj->Data.v_array.data[i], ' ');
			}
			printf("%c", delim);
			break;
		default:
			printf("unknown data types\n");
			break;
	}
}

int main() {

	object_t* obj1 = NewObjectInt(10);
	object_t* obj2 = NewObjectFloat(20.012);

	PrintObject(obj1, '\n');
	PrintObject(obj2, '\n');

	if (obj1) free(obj1);
	if (obj2) free(obj2);

	return 0;
}