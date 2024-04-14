#include "fractie.h"

int main() {

	Fractie f(8, 6), f1(f), f2(3, 5), fr, f3(5, 6), f4(1, 2), f5(3, 4);

	cout << "\n//Calculator fractie - Editia 2022\n";
	cout << (char)0xA9 << "EdisonSenpai. All rights reserved.\n\n";

	cout << " Numaratorul a este : " << f.GetA() << '\n';
	cout << " Numitorul b este : " << f.GetB() << '\n';

	cout << " Fractia este " << f.GetValue() << '\n';
	fr = f.GetInvers();
	cout << " Inversul fractiei este: " << " a = " << fr.GetA() << "  " << "b = " << fr.GetB() << '\n';

	f1.SetData(12, 7);
	cout << " Modificare val f1: " << " a = " << f1.GetA() << "  " << "b = " << f1.GetB() << '\n';

	cout << '\n';

	fr = f + f2;
	cout << " Operatorul + : " << " a = " << fr.GetA() << "  " << "b = " << fr.GetB() << '\n';

	fr = f - f2;
	cout << " Operatorul - : " << " a = " << fr.GetA() << "  " << "b = " << fr.GetB() << '\n';

	fr = f * f2;
	cout << " Operatorul * : " << " a = " << fr.GetA() << "  " << "b = " << fr.GetB() << '\n';

	fr = f / f2;
	cout << " Operatorul / : " << " a = " << fr.GetA() << "  " << "b = " << fr.GetB() << '\n';

	f2 = operator-(f2);
	cout << " Opusul lui f2 : " << " a = " << f2.GetA() << "  " << "b = " << f2.GetB() << '\n';

	f1.operator+=(f3);
	cout << " Operatorul += : " << " a = " << f1.GetA() << "  " << "b = " << f1.GetB() << '\n';

	f1.operator-=(f3);
	cout << " Operatorul -= : " << " a = " << f1.GetA() << "  " << "b = " << f1.GetB() << '\n';

	f1.operator*=(f3);
	cout << " Operatorul *= : " << " a = " << f1.GetA() << "  " << "b = " << f1.GetB() << '\n';

	f1.operator/=(f3);
	cout << " Operatorul /= : " << " a = " << f1.GetA() << "  " << "b = " << f1.GetB() << '\n';

	cout << '\n';

	cout << " Operatorul boolean == : " << (f4.operator==(f5)) << '\n';

	cout << " Operatorul boolean != : " << (f4.operator!=(f5)) << '\n';

	cout << " Operatorul boolean < : " << (f4.operator<(f5)) << '\n';

	cout << " Operatorul boolean <= : " << (f4.operator<=(f5)) << '\n';

	cout << " Operatorul boolean > : " << (f4.operator>(f5)) << '\n';

	cout << " Operatorul boolean >= : " << (f4.operator>=(f5)) << '\n';

	return 0;
}