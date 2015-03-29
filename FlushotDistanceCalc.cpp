/*
For safety reasons, people are not allowed to stand very close to each other as the flu is not under control yet. However, many people were not aware of this precaution. A health and safety official recently examined the line and has determined that people need to spread out more in the line so that they are at least T units away from each other. This needs to be done as quickly as possible so we need to calculate the minimum distance D such that it is possible for every person to move at most D units so the distance between any two people is at least T. Specifically, D should be the minimum value such that there are locations x'i so that |xi - x'i| ≤ D for each person i and |x'i - x'j| ≥ T for any two distinct people i,j. Furthermore, since nobody can move past the receptionist we must also have that x'i ≥ 0.
*/
#include <iostream>

const double EPS = 1e-8;
class Flushot
{
	public:
		double max(const double _a, const double _b)
		{
			return (_a > _b)?_a:_b;
		}
		
		bool isDistanceEnough(const double _location_list[], int _number_of_people, double _min_dist, double _current_distance)
		{
			double position = max(_location_list[0]-_current_distance, 0.0);
			std::cout<<"1st pos:"<<position<<std::endl;
			for(int i = 1; i < _number_of_people; i++)
			{
				if(_location_list[i]+_current_distance >= position+_min_dist)
				{
					position = max(position+_min_dist, _location_list[i]-_current_distance);
					std::cout<<"next pos:"<<position<<std::endl;
				}
				else
				{
					std::cout<<"not possible"<<std::endl;
					return false;
				}
			}
			std::cout<<"possible"<<std::endl;
			return true;
		}
		double minBiggestMove(const double _location_list[], int _number_of_people, double _min_dist)
		{
			double low = 0.000;
			double hi = 1.0000;

			while(!isDistanceEnough(_location_list, _number_of_people, _min_dist, hi))
			{
				low = hi;
				hi *= 2.0000;
			}
			std::cout<<"low:"<<low<<" :: hi:"<<hi<<std::endl;
			double mid;
			while(low+EPS < hi)
			{
				std::cout<<"in loop: low:"<<low<<" :: hi:"<<hi<<std::endl;
				mid = (low + hi)/2;
				if(isDistanceEnough(_location_list, _number_of_people, _min_dist, mid))
				{
					hi = mid;	
				}
				else
				{
					low = mid;
				}
			}
			return low;
		}
};

int main()
{
	double location_list[] = {0,0.5,0.6,2.75};
	Flushot obj;	
	double d = obj.minBiggestMove(location_list, 4, 1.0);
	std::cout<<"Minimum Largest Move:"<<d<<std::endl;
}
