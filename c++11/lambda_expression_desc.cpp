//constructs  a closure - an un named function object capable of capturing variables in scope
//syntax : [captures] (params) specs requires {body}   : c++11
//syntax : [captures] <tparams> requires (params) specs requires {body} 
//	capture - comman separated variable list 
//	tparams - template parameters 
//	params	- parameters similar to named functions
//	specs	- includes specifiers, exception, attributes and trailing return type
//			specifiers are - mutable, constexpr, consteval
//lambda functions are useful to send the function object as an argument to a function
//
