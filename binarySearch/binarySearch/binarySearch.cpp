// binarySearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

int binary_search(int array[], int start_index, int end_index, int key);
void print_array(int a[], int n, int start, int end, int pivot);
const int array_size = 25;


int main()
{
    //Define our data
    int array_to_be_sorted[array_size] = {
        14,65,63,1,54,
        89,84,9,98,57,
        71,18,21,84,69,
        28,11,83,13,42,
        64,58,78,82,13
    };

    // Sort the array using inbuilt sort (found in <algorithm>
    //std::sort(&array_to_be_sorted[0], &array_to_be_sorted[array_size]); // pointer as arithmetic version

    // alternative sort version
    std::sort(array_to_be_sorted, array_to_be_sorted + array_size); // pointers as iterators version


    while (true) {
        std::cout << std::endl << std::endl << "Enter a number to find in the sequence: -1 to end" << std::endl;
        int search_key = -1; // end condition. user will overwrite this, or not
        std::cin >> search_key;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // numbers only
        if (search_key == -1)
            // User wants to end the loop
            break;

        int return_code = binary_search(array_to_be_sorted, 0, array_size - 1, search_key);
        if (return_code == -1)
            std::cout << "Couldn't find " << search_key << " in the list" << std::endl;
        else
            std::cout << "Found " << search_key << " at position " << return_code << std::endl;
    }
    return 0;
}


int binary_search(int array[], int start_index, int end_index, int key) {
    while (start_index <= end_index)
    {
        // find the midpoint
        int pivot = (start_index + end_index) / 2;

        print_array(array, array_size, start_index, end_index, pivot);


        // if we have found the searched for 'key' then exit
        if (array[pivot] == key)
            return pivot;

        // determine if we are to the left or right of the ky
        if (key < array[pivot])
            // key is on our left (asuming ascending values
            // move the right to the middle minus one
            end_index = pivot - 1;
        else
            // key is on our right (asuming ascending values
            // move the left to the middle plus one
            start_index = pivot + 1;
    }

    // we havent found the key
    // return "-1" as the index (an invalid index)
    return -1;
}

void print_array(int a[], int n, int start, int end, int pivot)
{
    for (int i = 0; i != n; ++i)
        {
        if (i == start)
            std::cout << "[";
        else if (i == pivot)
            std::cout << "<";

        if (i<start || i>end)
            // outside of the range. print placeholders instead
            std::cout << (a[i] < 10 ? "." : "..");
        else
            std::cout << a[i];

        //if (i + 1 != pivot)
        //    std::cout << (i == end ? "]" : (i + 1 != start ? (i != pivot ? " " : ">") : ""));

        if (i + 1 != pivot) {
            if (i == end) {
                std::cout << "]";
            }
            else if (i + 1 != start)
            {
                if (i != pivot) {
                    std::cout << " ";
                }
                else std::cout << ">";
            }
        }
    }
    std::cout << std::endl ;
}