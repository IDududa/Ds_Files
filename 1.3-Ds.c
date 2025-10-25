#include <stdio.h>

typedef struct 
{
    float Realpart;
    float Imagepart;

}Complex;

   void Create(Complex *C,float x,float y)
    {
        C->Realpart = x;
        C->Imagepart = y;
    }

    float GetReal(Complex C)
    {
        return C.Realpart;
    }

    float GetImag(Complex C)
    {
        return C.Imagepart;
    }

    Complex Add(Complex c1,Complex c2)
    {
        Complex sum;
        sum.Imagepart = c1.Imagepart + c2.Imagepart;
        sum.Realpart = c1.Realpart + c2.Realpart;
        return sum;
    }

    Complex Sub(Complex c1,Complex c2)
    {
        Complex difference;
        difference.Imagepart = c1.Imagepart - c2.Imagepart;
        difference.Realpart = c1.Realpart - c2.Realpart;
        return difference;
    }


int main()
{
    Complex C;
    Complex C2;
    Create(&C,5.0,10.0);
    Create(&C2,2.0,12.0);
    float a = GetImag(C);
    printf("实数C的虚部: %.2f\n",a);
    Complex Complex_Add = Add(C,C2);
    
    float Add_Image = GetImag(Complex_Add);
    float Add_Real = GetReal(Complex_Add);
    printf("实数和的实部：%.2f\n",Add_Real);
    printf("实数和的虚部： %.2f\n",Add_Image);


    return 0;
}