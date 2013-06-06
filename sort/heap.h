#ifndef HEAP_H_
#define HEAP_H_ 1

/* This heap implementation use zero-based indexing array.
 * It's a max heap, ie, heap[0] is always the largest element.
 * After HEAP_SORT(), the array is sorted, and heap[0] is the smallest.
 * If you want a min heap and sort the array in descending order, 
 * you should define the LESS(a,b) function (or macro) so that
 * it returns true when (a>b).
 * -- xiongjg 		Tue Aug  3 14:02:20 CST 2004
 */


#define HEAP_FIX_UP(h, k, LESS, SWAP) 	do {		\
	register int _i_, _k_=(k);			\
	for (; _k_>0 && (_i_=(_k_-1)/2, LESS(h[_i_], h[_k_])); _k_=_i_)	\
		SWAP(h, _k_, _i_);			\
} while(0)

#define HEAP_FIX_DOWN(h, k, N, LESS, SWAP)  do {	\
	register int _i_, _k_=(k), _n_=(N);		\
	for (; _i_ = 2*_k_+1, _i_ < _n_; _k_=_i_) {	\
		if (_i_ < _n_-1 && LESS(h[_i_], h[_i_+1])) ++_i_;	\
		if (LESS(h[_k_], h[_i_])) SWAP(h, _k_, _i_);	\
		else break;				\
	}						\
} while(0)

#define HEAP_FIX_UPDOWN(h, k, N, LESS, SWAP) do {	\
	register int _i_, _k_=(k), _n_=(N);		\
	int _saved_k_=_k_;				\
	for (; _k_>0 && (_i_=(_k_-1)/2, LESS(h[_i_], h[_k_])); _k_=_i_)	\
		SWAP(h, _k_, _i_);			\
	if (_k_ == _saved_k_) {				\
		for (; _i_ = 2*_k_+1, _i_ < _n_; _k_=_i_) {	\
			if (_i_ < _n_-1 && LESS(h[_i_], h[_i_+1])) ++_i_;	\
			if (LESS(h[_k_], h[_i_])) SWAP(h, _k_, _i_);	\
			else break;			\
		}					\
	}						\
} while(0)


#define HEAP_PUSH(h, N, e, LESS, SWAP)	do {	\
	h[N] = e;				\
	HEAP_FIX_UP(h, N, LESS, SWAP);		\
	++N;					\
} while(0)


#define HEAP_POP(h, N, e, LESS, SWAP)  do {	\
	--N;					\
	SWAP(h, 0, N);				\
	HEAP_FIX_DOWN(h, 0, N, LESS, SWAP);	\
	e = h[N];				\
} while(0)


#define HEAP_PUT(h, k, N, e, LESS, SWAP) do {	\
	h[k] = e;				\
	HEAP_FIX_UPDOWN(h, k, N, LESS, SWAP);	\
} while(0)


/* NB: *h* must be a heap. That is, *h* must constructed by HEAP_PUSH()
 * or by HEAPIFY().
 */
#define HEAP_SORT(h, NN, LESS, SWAP)	do {		\
	register int _nn_ = (NN);			\
	while (_nn_ > 0) {				\
		--_nn_;					\
		SWAP(h, 0, _nn_);			\
		HEAP_FIX_DOWN(h, 0, _nn_, LESS, SWAP);\
	}						\
} while(0)


/* Heapify an array in place */
#define HEAPIFY(a, NN, LESS, SWAP) 	do {		\
	register int _kk_, _nn_ = (NN);			\
	for (_kk_ = (_nn_-2)/2; _kk_ >= 0; --_kk_)	\
		HEAP_FIX_DOWN(a, _kk_, _nn_, LESS, SWAP);	\
} while(0)

#define BSEARCH_POS(a, N, key, r, p, CMP)	do {	\
	int _l_, _u_, _i_, _r_, _comp_;			\
	_l_ = 0; _u_ = (N); _r_ = -1;			\
	while (_l_ < _u_) { 				\
		_i_ = (_l_ + _u_) / 2;			\
		_comp_ = CMP(key, a[_i_]);		\
		if (_comp_ < 0) _u_ = _i_;		\
		else if (_comp_ > 0) _l_ = _i_ + 1;	\
		else { _r_ = _i_; break; }		\
	}						\
	(r) = _r_;					\
	(p) = _r_ >= 0 ? _r_ : _l_;			\
} while(0)

#define BSEARCH(a, N, key, r, CMP)	do {		\
	int _p_;					\
	BSEARCH_POS(a, N, key, r, _p_, CMP);		\
} while(0)


#endif

