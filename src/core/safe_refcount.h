#ifndef SUNABA_SAFE_RETCOUNT_H
#define SUNABA_SAFE_RETCOUNT_H

#include <atomic>
#include <type_traits>

namespace sunaba_core {
template <class T>
class SafeNumeric {
	std::atomic<T> value;

	static_assert(std::atomic<T>::is_always_lock_free);

public:
	_ALWAYS_INLINE_ void set(T p_value) {
		value.store(p_value, std::memory_order_release);
	}

	_ALWAYS_INLINE_ T get() const {
		return value.load(std::memory_order_acquire);
	}

	_ALWAYS_INLINE_ T increment() {
		return value.fetch_add(1, std::memory_order_acq_rel) + 1;
	}

	// Returns the original value instead of the new one
	_ALWAYS_INLINE_ T postincrement() {
		return value.fetch_add(1, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T decrement() {
		return value.fetch_sub(1, std::memory_order_acq_rel) - 1;
	}

	// Returns the original value instead of the new one
	_ALWAYS_INLINE_ T postdecrement() {
		return value.fetch_sub(1, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T add(T p_value) {
		return value.fetch_add(p_value, std::memory_order_acq_rel) + p_value;
	}

	// Returns the original value instead of the new one
	_ALWAYS_INLINE_ T postadd(T p_value) {
		return value.fetch_add(p_value, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T sub(T p_value) {
		return value.fetch_sub(p_value, std::memory_order_acq_rel) - p_value;
	}

	// Returns the original value instead of the new one
	_ALWAYS_INLINE_ T postsub(T p_value) {
		return value.fetch_sub(p_value, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T exchange_if_greater(T p_value) {
		while (true) {
			T tmp = value.load(std::memory_order_acquire);
			if (tmp >= p_value) {
				return tmp; // already greater, or equal
			}
			if (value.compare_exchange_weak(tmp, p_value, std::memory_order_release)) {
				return p_value;
			}
		}
	}

	_ALWAYS_INLINE_ T conditional_increment() {
		while (true) {
			T c = value.load(std::memory_order_acquire);
			if (c == 0) {
				return 0;
			}
			if (value.compare_exchange_weak(c, c + 1, std::memory_order_release)) {
				return c + 1;
			}
		}
	}

	_ALWAYS_INLINE_ explicit SafeNumeric<T>(T p_value = static_cast<T>(0)) {
		set(p_value);
	}

	_ALWAYS_INLINE_ T bit_and(T p_value) {
		return value.fetch_and(p_value, std::memory_order_acq_rel);
	}

	_ALWAYS_INLINE_ T bit_or(T p_value) {
		return value.fetch_or(p_value, std::memory_order_acq_rel);
	}
};
}

#endif // !SUNABA_SAFE_RETCOUNT_H
