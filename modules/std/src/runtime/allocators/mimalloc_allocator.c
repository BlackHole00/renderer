#include <std/runtime/allocators/mimalloc_allocator.h>

#include <mimalloc/mimalloc.h>

static Slice(byte) mimallocallocator_alloc(void*, usize size, bool zeroed) {
	if (zeroed) {
		return slice_from(byte)(mi_calloc(1, size), size);
	} else {
		return slice_from(byte)(mi_malloc(size), size);
	}
}

static void mimallocallocator_dealloc(void*, Slice(byte) slice) {
	mi_free(slice.data);
}

static Slice(byte) mimallocallocator_realloc(void*, Slice(byte) slice, usize size, bool zeroed) {
	if (zeroed) {
		void* new_ptr = mi_calloc(1, size);
		memcpy(new_ptr, slice.data, (size > slice.length) ? size : slice.length);
		mi_free(slice.data);

		return slice_from(byte)(new_ptr, size);
	} else {
		return slice_from(byte)(mi_realloc(slice.data, size), size);
	}
}

static void mimallocallocator_dealloc_all(void*) {
	// "The MimallocAllocator does not support deallocating all resources"
	assert(false);
}

static auto singleton_of(vtable_of(MimallocAllocator)) = (vtable_of(Allocator)){
	.alloc       = mimallocallocator_alloc,
	.dealloc     = mimallocallocator_dealloc,
	.realloc     = mimallocallocator_realloc,
	.dealloc_all = mimallocallocator_dealloc_all
};

MimallocAllocator singleton_of(MimallocAllocator) = (MimallocAllocator){
	.vtable = &singleton_of(vtable_of(MimallocAllocator)),
	.allocator_data = nullptr,
};

