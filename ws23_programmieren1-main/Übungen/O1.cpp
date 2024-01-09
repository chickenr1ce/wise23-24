#include <iostream>
#include <fstream>
#include <vector>
#include <time.h>


using namespace std;

class NumberBox

{
    private:

        vector<double> numbers;
        size_t maxCapacity;

    public:

        NumberBox(size_t capacity) : maxCapacity(capacity)
        {
            cout << "NumberBox constructor called with capacity " << maxCapacity << "." << endl;
        }

        void add_a_number(double number)
        {
            if (numbers.size() < maxCapacity) //returns number of elements in vector
            {
                numbers.push_back(number);
                cout << "Added number " << number << " to NumberBox." << endl;
            }
            else
            {
                cout << "NumberBox is full. Cannot add more numbers." << endl;
            }
        }

        void show_all_numbers_in_box()
        {
            cout << "Numbers currently in the box: ";
            for (double number : numbers) //current element is assigned to number
            {
                cout << number << " ";
            }
            cout << endl;
        }

        void get_min_max(double* minVal, double* maxVal)
        {
 
            *minVal = *maxVal = numbers[0];

            for (double num : numbers)
            {
                if (num < *minVal)
                {
                    *minVal = num;
                }

                if (num > *maxVal)
                {
                    *maxVal = num;
                }
            }
        }

        double get_arithmetic_mean()
        {
            double sum = 0;
            for (double num : numbers)
            {
                sum = sum+num;
            }

            double arithmetic = sum/numbers.size();
            return sum / static_cast<double>(numbers.size());
        }
};

int main()
{
        NumberBox myBox(10);

        myBox.add_a_number(1.0);
        myBox.add_a_number(4.0);
        myBox.add_a_number(7.0);
        myBox.show_all_numbers_in_box();

        myBox.add_a_number(11.0);
        myBox.add_a_number(44.0);
        myBox.add_a_number(77.0);
        myBox.show_all_numbers_in_box();
            

        double minval, maxval;
        myBox.get_min_max(&minval,&maxval);
        printf("Minimum value of all numbers in box is: %.1f\n", minval);
        printf("Maximum value of all numbers in box is: %.1f\n", maxval);

        printf("Arithmetic mean of all numbers in box is: %.1f\n", myBox.get_arithmetic_mean());


        myBox.add_a_number(100.0);
        myBox.add_a_number(200.0);
        myBox.add_a_number(300.0);
        myBox.add_a_number(400.0);
        myBox.add_a_number(500.0);
        myBox.add_a_number(600.0);
        
}