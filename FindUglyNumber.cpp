/*
Ugly numbers are the numbers whose prime factors are 2,3 and 5. 1 is an ugly number by convention. 
This program uses dynamic programming concept. 
*/
#include <iostream>

class UglyNumber
{
	public:
		int min (int a, int b, int c)
		{
			if(a<b)
			{
				return (a<c)?a:c;
			}
			else
			{
				return (b<c)?b:c;
			}
		}
		int getNthUglyNumber(int _n)
		{
			int uglyNumber[100];
			uglyNumber[0] = 1;
			
			int i2 = 0;
			int i3 = 0;
			int i5 = 0;

			
			int next_multiple_of_2 = uglyNumber[i2]*2;
			int next_multiple_of_3 = uglyNumber[i3]*3;
			int next_multiple_of_5 = uglyNumber[i5]*5;
		
			int nextUgly = 1;
			for(int i = 1; i < _n; i++)
			{
				nextUgly = min(next_multiple_of_2, next_multiple_of_3, next_multiple_of_5);
				std::cout<<"next_multiple_of_2:"<<next_multiple_of_2<<" :: next_multiple_of_3:"<<next_multiple_of_3<<" :: next_multiple_of_5:"<<next_multiple_of_5<<std::endl;
				uglyNumber[i] = nextUgly;
				if(nextUgly == next_multiple_of_2)
				{
					i2++;
					next_multiple_of_2 = uglyNumber[i2]*2;;
				}
				if(nextUgly == next_multiple_of_3)
				{
					i3++;
					next_multiple_of_3 = uglyNumber[i3]*3;
				}
				if(nextUgly == next_multiple_of_5)
				{
					i5++;
					next_multiple_of_5 = uglyNumber[i5]*5;
				}
			}
			for(int i = 0; i<_n; std::cout<<uglyNumber[i]<<" ", i++);
			return nextUgly;
		}
};

int main()
{
	UglyNumber obj;
	int n = obj.getNthUglyNumber(20);
	std::cout<<"ugly number:"<<n<<std::endl;
}
