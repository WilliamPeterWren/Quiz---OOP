#include "Color.h"

/*
	0 black			1 blue				2 green				3 aqua
	4 red			5 purple			6 yellow			7 white
	8 gray			9 light blue		10 light green		11 light aqua
	12 light red	13 light purple		14 light yellow		15 bright white
*/


/* set color question */
void SET_COLOR(const char& color) {

	WORD wColor;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi)) {
		wColor = (csbi.wAttributes & 0xF0) + (color & 0x0F);
		SetConsoleTextAttribute(hStdOut, wColor);
	}
}

/* apply color */
void PrintChangeColor(const std::wstring& question) {

	/*
	0 black			1 blue				2 green				3 aqua
	4 red			5 purple			6 yellow			7 white
	8 gray			9 light blue		10 light green		11 light aqua
	12 light red	13 light purple		14 light yellow		15 bright white
	*/

	int n = question.length();
	std::wstring temp;
	std::wstring temp_class, shiftleft, datatype, dot, typenew, arrow, imple, superthis;

	for (int i = 0; i < n; i++) {

		if (question[i] == L' ') {

			std::wstringstream ss(temp);
			std::wstring tmp;
			while (ss >> tmp) {}

			/* IMPORTANT for enter new line : do not touch */
			if (tmp == L"williammikiejames") {
				tmp = L"";
				std::wcout << L"\n\t";

				temp = L"";
				continue;
			}
			/* IMPORTANT for enter new line : do not touch */

			/* first check */
			if (temp_class == L"class" || temp_class == L"interface") {
				
				SET_COLOR(lightgreen);
				temp_class = L"";
			}

			if (typenew == L"new") {
				
				SET_COLOR(lightgreen);
				typenew = L"";
			}

			if (shiftleft == L"System.out.print" || shiftleft == L"System.out.println" || shiftleft == L"Console.Write" || shiftleft == L"Console.WriteLine") {
				
				SET_COLOR(lightaqua);
				shiftleft = L"";
			}

			if (shiftleft == L"=" || shiftleft == L"<<" || shiftleft == L"+=" || shiftleft == L">=" || shiftleft == L"<=" || shiftleft == L">>" ||
				shiftleft == L"-=" || shiftleft == L"/=" || shiftleft == L"%=" || shiftleft == L"*="
				) {

				SET_COLOR(lightred);
				shiftleft = L"";
			}

			if (datatype == L"int" || datatype == L"void" || datatype == L"double" || datatype == L"float" || datatype == L"long" || datatype == L"base" ||
				datatype == L"short" || datatype == L"super" || datatype == L"string" || datatype == L"String" || datatype == L"string&" || datatype == L"T" ||
				datatype == L"char" || datatype == L"char[]" || datatype == L"bool"
				) {

				SET_COLOR(lightyellow);
				datatype = L"";
			}

			if (dot == L".") {

				SET_COLOR(lightyellow);
				dot = L"";
			}

			if (arrow == L"->") {

				SET_COLOR(lightyellow);
				arrow = L"";
			}

			if (imple == L"implements") {

				SET_COLOR(lightyellow);
				imple = L"";
			}

			if (superthis == L"this." || superthis == L"this->" || superthis == L"sizeof" || superthis == L"this" || superthis == L"base" || superthis == L"super" ||
				superthis == L"super();" || superthis == L"this();"
				) {

				SET_COLOR(lightyellow);
				superthis = L"";
			}

			/* end of first check */

			/* continue step */
			if (tmp == L"System.out.print") {

				SET_COLOR(lightgreen);
				PrintFunny(L"System.");

				SET_COLOR(aqua);
				PrintFunny(L"out.");

				SET_COLOR(lightyellow);
				PrintFunny(L"print");

				shiftleft = temp;
				temp = L"";

				continue;
			}

			if (tmp == L"System.out.println") {

				SET_COLOR(lightgreen);
				PrintFunny(L"System.");

				SET_COLOR(aqua);
				PrintFunny(L"out.");

				SET_COLOR(lightyellow);
				PrintFunny(L"println");

				shiftleft = temp;
				temp = L"";

				continue;
			}

			if (tmp == L"Console.Write") {
				SET_COLOR(lightgreen);
				PrintFunny(L"Console.");

				SET_COLOR(lightyellow);
				PrintFunny(L"Write");

				shiftleft = temp;
				temp = L"";

				continue;
			}

			if (tmp == L"Console.WriteLine") {

				SET_COLOR(lightgreen);
				PrintFunny(L"Console.");

				SET_COLOR(lightyellow);
				PrintFunny(L"WriteLine");

				shiftleft = temp;
				temp = L"";

				continue;
			}

			if (tmp == L"Console.ReadLine") {

				SET_COLOR(lightgreen);
				PrintFunny(L"Console.");

				SET_COLOR(lightyellow);
				PrintFunny(L"ReadLine");

				temp = L"";

				continue;
			}

			if (tmp == L"Rectangle::" || tmp == L"Geeks::" || tmp == L"Test::" || tmp == L"Circle::" ||
				tmp == L"A::" || tmp == L"Point::" || tmp == L"Add::" || tmp == L"Time::" || tmp == L"Quiz::" ||
				tmp == L"BaseA::" || tmp == L"Polygon::" || tmp == L"Triangle::" || tmp == L"B::" || tmp == L"Test<T>::" ||
				tmp == L"Calc<T>::" || tmp == L"args)" || tmp == L"args" || tmp == L"Animal::" || tmp == L"Teacher::" ||
				tmp == L"&Rectangle::"
				) {

				SET_COLOR(lightaqua);
				PrintFunny(tmp);

				temp = L"";
				SET_COLOR(lightwhite);
				continue;
			}

			if (tmp == L"this." || tmp == L"this->" || tmp == L"sizeof" || tmp == L"this" || tmp == L"base" || tmp == L"super" || tmp == L"super();" ||
				tmp == L"this();"
				) {
				superthis = tmp;
				SET_COLOR(lightblue);
				PrintFunny(tmp);
				temp = L"";
				SET_COLOR(lightwhite);
				continue;
			}

			if (tmp == L"->") {
				arrow = tmp;
				std::wcout << L"\b";
				SET_COLOR(lightblue);
				PrintFunny(tmp);
				temp = L"";
				SET_COLOR(lightwhite);
				continue;
			}

			if (tmp == L"strcpy_s" || tmp == L"Test().") {
				SET_COLOR(lightyellow);
				PrintFunny(tmp);
				temp = L"";
				SET_COLOR(lightwhite);
				continue;
			}

			if (tmp == L".") {
				dot = tmp;
				std::wcout << L"\b";
				PrintFunny(tmp);
				temp = L"";
				SET_COLOR(lightwhite);
				continue;
			}
			/* end continue step */


			/* set color: 2 */
			if (tmp == L"string" || tmp == L"String" || tmp == L"string&") {
				datatype = tmp;
				SET_COLOR(green);
			}

			if (tmp == L"//" || tmp == L"Dòng" || tmp == L"//you" || tmp == L"code" || tmp == L"here," ||
				tmp == L":" || tmp == L"//access" || tmp == L"variable" || tmp == L"your" ||
				tmp == L"T>" || tmp == L"T" || tmp == L"(T" || tmp == L"method" || tmp == L"declaration" ||
				tmp == L"variable" || tmp == L"here" || tmp == L"string)" || tmp == L"/*" || tmp == L"*/" ||
				tmp == L"//your" || tmp == L"//method" || tmp == L"access" || tmp == L"T," ||
				tmp == L"Object[]" || tmp == L"Exception" || tmp == L"(Exception"
				) {
				SET_COLOR(green);
			}

			if (tmp == L"(String" || tmp == L"(Integer" || tmp == L"(String[]" || tmp == L"(string" || tmp == L"(string[]") {
				std::wcout << L"\b";
				SET_COLOR(green);
			}

			/* end set color: 2 */


			/* set color: 8 */
			if (tmp == L"=" || tmp == L"<<" || tmp == L"*" || tmp == L"<" || tmp == L"+=" || tmp == L">=" || tmp == L"<=" || tmp == L"&" ||
				tmp == L"+" || tmp == L"-" || tmp == L"==" || tmp == L"++" || tmp == L"--" || tmp == L"[]" || tmp == L"&&" || tmp == L"||" ||
				tmp == L">" || tmp == L"/" || tmp == L"!=" || tmp == L">>" || tmp == L"-=" || tmp == L"%" ||
				tmp == L"/=" || tmp == L"%=" || tmp == L"*=" ||
				tmp == L"System.out.print" || tmp == L"System.out.println") {
				shiftleft = tmp;
				SET_COLOR(gray);
			}

			if (tmp == L"{" || tmp == L"}" || tmp == L"{}" || tmp == L"};" || tmp == L"()" || tmp == L"#include"
				) {
				SET_COLOR(gray);
			}
			/* end set color: 8 */


			/* set color: 9 */
			if (tmp == L"int" || tmp == L"void" || tmp == L"double" || tmp == L"float" || tmp == L"long" || tmp == L"base" || tmp == L"short" ||
				tmp == L"super" || tmp == L"T" || tmp == L"char" || tmp == L"char[]" || tmp == L"bool"
				) {
				datatype = tmp;
				SET_COLOR(lightblue);
			}

			if (tmp == L"->") {
				arrow = tmp;
				SET_COLOR(lightblue);
			}

			if (tmp == L"new") {
				typenew = tmp;
				SET_COLOR(lightblue);
			}

			if (tmp == L"class" || tmp == L"<class" || tmp == L"interface") {
				temp_class = tmp;
				SET_COLOR(lightblue);
			}

			if (tmp == L"(int" || tmp == L"(double" || tmp == L"(float" || tmp == L"(const" || tmp == L"<int" || tmp == L"<int>" || tmp == L"<char>" ||
				tmp == L"<int," || tmp == L"<float>" || tmp == L"(long" || tmp == L"(char" || tmp == L"(short" || tmp == L"(new" || tmp == L"(byte" ||
				tmp == L"(int," || tmp == L"(Double"
				) {
				std::wcout << L"\b";
				SET_COLOR(lightblue);
			}

			if (tmp == L"private:" || tmp == L"protected:" || tmp == L"public:" ||
				tmp == L"public" || tmp == L"private" || temp == L"protected" ||
				tmp == L"const" || tmp == L"const;" ||
				tmp == L"friend" || tmp == L"delete" || tmp == L"delete[]" || tmp == L"static" ||
				tmp == L"char" || tmp == L"char*" || tmp == L"operator" || tmp == L"int)" ||
				tmp == L"(int)" || tmp == L"int&" ||
				tmp == L"template" ||
				tmp == L"*this;" ||
				tmp == L"override" || tmp == L"virtual" || tmp == L"interface" ||
				tmp == L"abstract" || tmp == L"char[]" ||
				tmp == L"namespace" || tmp == L"extends" ||
				tmp == L"throws" || tmp == L"final" || tmp == L"instanceof" ||
				tmp == L"(final" || tmp == L"this" || tmp == L"null" || tmp == L"<float>" ||
				tmp == L"instanceof" || tmp == L"&operator"
				) {
				SET_COLOR(lightblue);
			}

			if (tmp == L"implements") {
				imple = tmp;
				SET_COLOR(lightblue);
			}
			/* end set color: 9 */


			/* set color: 10 */
			if (tmp == L"(Point" || tmp == L"(Point," || tmp == L"(A*" || tmp == L"(A" || tmp == L"(Time" || tmp == L"(Base" || tmp == L"(ADouble" || tmp == L"(Vehicle" ||
				tmp == L"(AInteger" || tmp == L"(FirstClass" || tmp == L"(AA&" || tmp == L"(AA" || tmp == L"(AAA" || tmp == L"(Object" || tmp == L"(Integer" ||
				tmp == L"(T"
				) {
				std::wcout << L"\b";
				SET_COLOR(lightgreen);
			}

			if (tmp == L"A" || tmp == L"~A()" || tmp == L"A()" || tmp == L"A();" || tmp == L"A*" || tmp == L"AA" || tmp == L"Add" || tmp == L"ABC" ||
				tmp == L"Array" || tmp == L"~Array()" || tmp == L"AAA" || tmp == L"~AAA()" || tmp == L"AInteger()" || tmp == L"AInteger" || tmp == L"AInteger&" ||
				tmp == L"ADouble" || tmp == L"Animal" || tmp == L"Animal()" ||

				tmp == L"B*" || tmp == L"Base()" || tmp == L"~Base()" || tmp == L"Base" || tmp == L"BaseA()" || tmp == L"BaseB()" || tmp == L"BB" ||
				tmp == L"Box" || tmp == L"Box&" || tmp == L"BaseA," || tmp == L"B" || tmp == L"B()" || tmp == L"~B()" || tmp == L"B," || tmp == L"BaseClass" ||
				tmp == L"BankAccount" ||

				tmp == L"C()" || tmp == L"~C()" || tmp == L"Complex" || tmp == L"Complex&" || tmp == L"Cube()" || tmp == L"Count()" || tmp == L"CombinedQuiz" ||
				tmp == L"Car" || tmp == L"Car()" || tmp == L"Child" || tmp == L"Circle" || tmp == L"ClassA" || tmp == L"Calc<int>" || tmp == L"Calc<float>" ||
				tmp == L"Coordinate" || tmp == L"Cord" || tmp == L"Calc" || tmp == L"Cat" || tmp == L"C" || tmp == L"Cube" || tmp == L"CombinedQuiz" ||


				tmp == L"Demo" || tmp == L"~Demo" || tmp == L"Demo()" || tmp == L"Dog" ||
				tmp == L"Derive()" || tmp == L"~Derive()" || tmp == L"Derive" || tmp == L"Derived()" || tmp == L"~Derived()" || tmp == L"Derived" ||
				tmp == L"Distance" || tmp == L"Distance&" || tmp == L"Distance()" ||

				tmp == L"Employee" ||

				tmp == L"Frac" || tmp == L"Frac()" || tmp == L"Frac&" || tmp == L"Four" || tmp == L"Faculty," || tmp == L"Faculty" || tmp == L"FirstClass" ||

				tmp == L"Geeks" || tmp == L"~Geeks()" || tmp == L"Geek()" || tmp == L"Geeks()" || tmp == L"Game" ||

				tmp == L"Human" || tmp == L"Human&" || tmp == L"HistoryQuiz" || tmp == L"HistoryQuiz()" ||

				tmp == L"Inter" || tmp == L"ITestInterface" || tmp == L"ITestInterface()" ||

				tmp == L"Lop1" || tmp == L"Lop2" || tmp == L"Lion" || tmp == L"Lion()" || tmp == L"Liger()" || tmp == L"Liger" ||

				tmp == L"MyClass" || tmp == L"Maths" || tmp == L"MathQuiz()" || tmp == L"MathQuiz" || tmp == L"Motorcycle" || tmp == L"MyClass()" ||
				tmp == L"Motorcycle()" || tmp == L"Maths()" ||

				tmp == L"NetworkDevice" ||

				tmp == L"OperatorOverload()" || tmp == L"OperatorOverload" || tmp == L"OverLoad" || tmp == L"OverLoad()" || tmp == L"Oscillating" ||
				tmp == L"One" || tmp == L"One()" ||

				tmp == L"Point" || tmp == L"POINT" || tmp == L"Point)" || tmp == L"PrintData" || tmp == L"Person" || tmp == L"Parent" ||
				tmp == L"PaintCost" || tmp == L"Plane" || tmp == L"Polygon" ||

				tmp == L"RectangleInt" || tmp == L"RectangleFloat" || tmp == L"RectangleFloat;" || tmp == L"RectangleA" ||
				tmp == L"Rectangle" || tmp == L"~Rectangle" || tmp == L"~Rectangle()" || tmp == L"Rectangle()" || tmp == L"Rectangle&" ||

				tmp == L"Sum()" || tmp == L"Sum" || tmp == L"~Sum" || tmp == L"Sum();" || tmp == L"Student" || tmp == L"Student()" ||
				tmp == L"SecondClass" || tmp == L"Sphere()" || tmp == L"Sphere" || tmp == L"Square" || tmp == L"~Shape()" || tmp == L"Shape*" ||
				tmp == L"Shape" ||

				tmp == L"Test" || tmp == L"~Test()" || tmp == L"Test()" || tmp == L"Test" || tmp == L"Test&" ||
				tmp == L"Tiger()" || tmp == L"Tiger," || tmp == L"TA" || tmp == L"Two," || tmp == L"TestImplementation()" ||
				tmp == L"Two" || tmp == L"Three" || tmp == L"TestChild" || tmp == L"Table()" || tmp == L"Table" ||
				tmp == L"TestInner" || tmp == L"TestImplementation" || tmp == L"Two()" || tmp == L"Three()" || tmp == L"Test()" ||
				tmp == L"Teacher" || tmp == L"Teacher()" || tmp == L"Time" || tmp == L"TestClass()" ||
				tmp == L"TestClass" || tmp == L"TestClass&" || tmp == L"(Time" || tmp == L"Triangle" ||

				tmp == L"USBDevice" || tmp == L"USBDevice," ||

				tmp == L"Vehicle" || tmp == L"Vehicle*" ||

				tmp == L"Worker" || tmp == L"WorkingStudent" || tmp == L"WirelessAdapter" || tmp == L"WirelessAdaptor"
				) {
				SET_COLOR(lightgreen);
			}
			/* end set color: 10 */


			/* set color: 11 */
			if (tmp == L"ostream&" || tmp == L"(ostream&" || tmp == L"ostream" || tmp == L"(ostream" || tmp == L"@Override") {
				SET_COLOR(lightaqua);
			}

			if (tmp == L"(args);") {
				std::wcout << L"\b";
				SET_COLOR(lightaqua);
			}
			/* end set color: 11 */


			/* set color: 12 */
			if (tmp == L"<cmath>" || tmp == L"Java" || tmp == L"C#" || tmp == L"C++") {
				SET_COLOR(lightred);
			}
			/* end set color: 12 */


			/* set color: 13 */
			if (tmp == L"return" || tmp == L"for" || tmp == L"SIZE" || tmp == L"SIZE;" || tmp == L"SIZE)" || tmp == L"if" || tmp == L"else" ||
				tmp == L"try" || tmp == L"catch" || tmp == L"PI"
				) {
				SET_COLOR(lightpurple);
			}
			/* end set color: 13 */


			/* end set color: 15 */
			if (tmp == L"cout" || tmp == L"std::cout<<" || tmp == L"cin") {
				SET_COLOR(lightwhite);
			}

			if (tmp == L".") {
				dot = tmp;
				SET_COLOR(lightwhite);
			}
			/* end set color: 15 */

			/* NOT set color */
			if (tmp == L"(x)" || tmp == L"(x),") {
				std::wcout << L"\b";
			}
			/* end NOT set color */


			/* Print single word */
			PrintFunny(tmp);
			std::wcout << " ";

			temp = L"";
			SET_COLOR(lightwhite);
			/* end Print single word */
		}
		else {
			temp += question[i];
		}
	}
}