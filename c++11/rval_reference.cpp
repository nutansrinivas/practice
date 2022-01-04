//lvalue reference can be used to alias an existing object
//std::string str = "india";
//std::string & lref_str = str;

//rvalue reference can be used to extend the lifetimes of temporary objects(note, lvalue reference to const can extend the lifetime of temporary objects too), but they not modifiabe through them)
//std::string && rref_str = str; //error, as rref can't bind to lvalue
//std::string && rref_str = str + str ;
//const std::string & lref_str = str + str;
//std
