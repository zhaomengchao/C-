//������
#include <iostream>
 #include <string>
 #define ADD(x, y) ((x) + (y)) 
 #define CMP(x, y) ((x) > (y))
 int main()
 {        
 double a, b, c;
 while (std::cin >> a >> b >> c)
 {
 //�����߽���������������бȽ�
 if (CMP(ADD(a, b), c) &&  CMP(ADD(b, c), a) && CMP(ADD(a, c), b))
 {            
 std::cout << "Yes" << std::endl;
 }
 else 
 {            
 std::cout << "No" << std::endl;
        
}  