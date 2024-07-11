#include <std/runtime/allocators/system_allocator.h>

#include <assert.h>
#include <stdlib.h>
#include <memory.h>

Slice(byte) systemallocator_alloc(void*, usize size, bool zeroed) {
	if (zeroed) {
		return slice_from(byte)(calloc(1, size), size);
	} else {
		return slice_from(byte)(malloc(size), size);
	}
}

void systemallocator_dealloc(void*, Slice(byte) slice) {
	free(slice.data);
}

Slice(byte) systemallocator_realloc(void*, Slice(byte) slice, usize size, bool zeroed) {
	if (zeroed) {
		void* new_ptr = calloc(1, size);
		memcpy(new_ptr, slice.data, (size > slice.length) ? size : slice.length);
		free(slice.data);

		return slice_from(byte)(new_ptr, size);
	} else {
		return slice_from(byte)(realloc(slice.data, size), size);
	}
}

void systemallocator_dealloc_all(void*) {
	// "The SystemAllocator does not support deallocating all resources"
	assert(false);
}

auto singleton_of(vtable_of(SystemAllocator)) = (vtable_of(Allocator)){
	.alloc       = systemallocator_alloc,
	.dealloc     = systemallocator_dealloc,
	.realloc     = systemallocator_realloc,
	.dealloc_all = systemallocator_dealloc_all
};
SystemAllocator singleton_of(SystemAllocator) = (SystemAllocator){
	.vtable = &singleton_of(vtable_of(SystemAllocator)),
	.allocator_data = nullptr,
};
