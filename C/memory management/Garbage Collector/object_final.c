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

object_t* NewObjectString(char* s) {}
object_t* NewObjectArray(int size) {}
object_t* NewObjectVector3(object_t* x, object_t* y, object_t* z) {}

bool set_array(object_t* obj, int index, object_t* val) {}	// obj[index] = val
object_t* get_array(object_t* obj, int index) {}	// retrive obj[index]
int len(object_t* obj) {}	// length of object
object_t* add(object_t* a, object_t* b) {}	// merge two objects


void PrintObject(object_t* obj) {
	if (obj == NULL) {
		return;
	}
	switch (obj->Kind) {
		case INT:
			printf("%d\n", obj->Data.v_int);
			break;
		case FLOAT:
			printf("%0.3f\n", obj->Data.v_float);
			break;
		default:
			printf("unknown data types\n");
			break;
	}
}

int main() {

	object_t* obj1 = NewObjectInt(10);
	object_t* obj2 = NewObjectFloat(20.012);

	PrintObject(obj1);
	PrintObject(obj2);

	if (obj1) free(obj1);
	if (obj2) free(obj2);

	return 0;
}