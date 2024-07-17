/**
 * @module STD
 * @file modules/std/include/std/lang/singleton.h
 * @author Vicix (www.github.com/BlackHole00)
 */
#pragma once

#include <std/macro/macros.h>

#define singleton
#define singleton_of(_type) STD_CAT(_type, _singleton_instance)
