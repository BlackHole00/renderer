#pragma once 

#include <std/macro/macros.h>

#define container_of(_type) STD_CAT(_type, Container)
#define contained_of(_type) _type

#define _STD_AS_CONTAINER_POINTER_VA_ARGS(...) STD_GET_LAST_VA_ARGS(__VA_ARGS__)
#define _STD_AS_CONTAINER_TYPE_VA_ARGS(...) STD_GET_ALL_BUT_LAST_VA_ARGS_WITH_COMMAS(__VA_ARGS__)
#define _STD_AS_CONTAINED_POINTER_VA_ARGS(...) STD_GET_LAST_VA_ARGS(__VA_ARGS__)
#define _STD_AS_CONTAINED_TYPE_VA_ARGS(...) STD_GET_ALL_BUT_LAST_VA_ARGS_WITH_COMMAS(__VA_ARGS__)

#define as_container(...) ((container_of(_STD_AS_CONTAINER_TYPE_VA_ARGS(__VA_ARGS__))*) \
	(((usize)(_STD_AS_CONTAINER_POINTER_VA_ARGS(__VA_ARGS__))) - (usize)(sizeof(_STD_AS_CONTAINER_TYPE_VA_ARGS(__VA_ARGS__)))))
#define as_contained(...) ((contained_of(_STD_AS_CONTAINED_TYPE_VA_ARGS(__VA_ARGS__))) \
	(((usize)(_STD_AS_CONTAINED_POINTER_VA_ARGS(__VA_ARGS__))) + (usize)(sizeof(_STD_AS_CONTAINED_TYPE_VA_ARGS(__VA_ARGS__)))))
