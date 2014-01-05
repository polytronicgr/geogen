#include <iostream>

#include "../GeoGen/GeoGen.hpp"
#include "../GeoGen/compiler/Compiler.hpp"

int main(){
	geogen::Generator g(5);
	/*
	metadata {\
StrItem: \"tralalal\",\
StrNumber: 5,\
StrSymbol: Symbol,\
KeyValSymbol: \
	{\
		SybSymbol: \"aaaa\"\
	}\
}\
	*/
	geogen::compiler::Compiler compiler;
	//HeightMap.Empty()        
	geogen::compiler::CompiledScript const* script = compiler.CompileScript(std::string("\
\
function aaa(x, y){\
	1+4;\
	return;\
		return 5;\
\
\
}  \
1 / 5;\
var a = 1 + 2;\
var b = true;\
var c = \"aaaa\";\
\
yield HeightMap.Empty() as \"aaa\";\
yield HeightMap.Empty();\
\
if(2 == 3){\
yield HeightMap.Empty();\
}\
\
\
if (2 == 3){\
\
yield HeightMap.Empty(); \
} else {\
yield HeightMap.Empty() as \"bbb\"; \
}\
\
while(a == true){\
	yield HeightMap.Empty() as \"ccc\"; \
	break;\
}\
\
for(var i = 0;i < 5;i+=1){\
	yield HeightMap.Empty() as \"ddd\"; \
}\
\
afield.bfield.cfield;\
funcname(parama, paramb, paramc);\
afield.bfield.cfield.funcname(parama, paramb, paramc);\
afield.bfield.cfield[parama, paramb, paramc];\
a ? b : c;\
lvalue1 = 1 + 2;\
lvalue2.fielda.fieldb = 1 + 2;\
lvalue2[parama] = 1 + 2;\
"));

	std::cout << script->GetRootCodeBlock().ToString();

/*

*/

	geogen::Number n(2);
	geogen::Number n2 = n / geogen::Number(3);
	//geogen::Number n5("3.14");

	std::cout << (double)n << " " << (double)n2 << " " << std::endl;

	return 0;
}
