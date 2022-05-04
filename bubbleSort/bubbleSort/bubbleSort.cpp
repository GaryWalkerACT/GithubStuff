// bubbleSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// iterates through each element from index 0 to n, and outputs it to std::cout
//don’t forget to #include <iostream> 
void print_array(int array[], int n);


void swap(int& a, int& b); //swaps the contents of a and b

void BubbleSort(int array[], int n);
void OptimisedBubbleSort(int array[], int n);
void CocktailShakerSort(int array[], int n);

bool Compare(int first, int second);

int swaps;
int comparisons;

int main()
{
    //Define our data
    const int array_size = 50;

    int array_to_be_sorted[array_size] = {
        14,65,63,1,54,
        89,84,9,98,57,
        71,18,21,84,69,
        28,11,83,13,42,
        64,58,78,82,13,
        9,96,14,39,89,
        40,32,51,85,48,
        40,23,15,94,93,
        35,81,1,9,43,
        39,15,17,97,52
    };

    //Print the unsorted array
    std::cout << "Unsorted" << std::endl;
    print_array(array_to_be_sorted, array_size);

    swaps = 0;
    comparisons = 0;
    std::cout << "Bubble Sort" << std::endl;
    BubbleSort(array_to_be_sorted, array_size);

    std::cout << "Number of swaps: " << swaps << std::endl;
    std::cout << "Number of comparisons: " << comparisons << std::endl;
    std::cout << std::endl;

    // disorder the array again
    int new_array_to_be_sorted[array_size] = {
    14,65,63,1,54,
    89,84,9,98,57,
    71,18,21,84,69,
    28,11,83,13,42,
    64,58,78,82,13,
    9,96,14,39,89,
    40,32,51,85,48,
    40,23,15,94,93,
    35,81,1,9,43,
    39,15,17,97,52
    };


    swaps = 0;
    comparisons = 0;
    std::cout << "Optimised Bubble Sort" << std::endl;
    OptimisedBubbleSort(new_array_to_be_sorted, array_size);

    std::cout << "Number of swaps: " << swaps << std::endl;
    std::cout << "Number of comparisons: " << comparisons << std::endl;
    std::cout << std::endl;

    // disorder the array again
    int extra_new_array_to_be_sorted[array_size] = {
    14,65,63,1,54,
    89,84,9,98,57,
    71,18,21,84,69,
    28,11,83,13,42,
    64,58,78,82,13,
    9,96,14,39,89,
    40,32,51,85,48,
    40,23,15,94,93,
    35,81,1,9,43,
    39,15,17,97,52
    };


    swaps = 0;
    comparisons = 0;
    std::cout << "Coctail Shaker Sort" << std::endl;
    CocktailShakerSort(extra_new_array_to_be_sorted, array_size);

    std::cout << "Number of swaps: " << swaps << std::endl;
    std::cout << "Number of comparisons: " << comparisons << std::endl;

    print_array(extra_new_array_to_be_sorted, array_size);


    //system(“pause”);
    return 0;

}

void BubbleSort(int array[], int n)
{
    //Bail for single element or invalid indices
    if (n < 2)
        return;

    //Track if list is sorted
    bool sorted = false; //set to false to ensure the while loop starts up
    while (!sorted)
    {
        sorted = true;

        for (int i = 0; i < n - 1; ++i)
        {
            //if (array[i] < array[i + 1]) // descending order
            //if (array[i] > array[i + 1]) // Ascending order
            if (Compare(array[i], array[i + 1])) // Ascending order
                {
                swap(array[i], array[i + 1]);
                sorted = false;
            }
        }
    }
}

void OptimisedBubbleSort(int array[], int n)
{
    //Bail for single element or invalid indices
    if (n < 2)
        return;

    //Track if list is sorted
    bool sorted = false; //set to false to ensure the while loop starts up
    while (!sorted)
    {
        sorted = true;


        for (int i = 0; i < n - 1; ++i)
        {
            //if (array[i] < array[i + 1]) // descending order
            //if (array[i] > array[i + 1]) // Ascending order
            if (Compare(array[i], array[i + 1])) // Ascending order
            {
                swap(array[i], array[i + 1]);
                sorted = false;
            }
        }

        n--; // The next iteration finished one place short of the previous
    }
}

void CocktailShakerSort(int array[], int n)
{
    //Bail for single element or invalid indices
    if (n < 2)
        return;

    int m = 0; // start element of the loop

    //Track if list is sorted
    bool sorted = false; //set to false to ensure the while loop starts up
    while (!sorted)
    {
        sorted = true;


        for (int i = m; i < n - 1; ++i)
        {
            //if (array[i] < array[i + 1]) // descending order
            //if (array[i] > array[i + 1]) // Ascending order
            if (Compare(array[i], array[i + 1])) // Ascending order
            {
                swap(array[i], array[i + 1]);
                sorted = false;
            }
        }

        if (sorted) break; // No changes made so it is sorted

        n--; // The next iteration finished one place short of the previous

        // Cycle through the array again going downwards
        // Looking for the smallest number
        for (int i = n-1; i >= m; --i)
        {
            //if (array[i] < array[i + 1]) // descending order
            //if (array[i] > array[i + 1]) // Ascending order
            if (Compare(array[i], array[i+1])) // Ascending order
            {
                swap(array[i], array[i + 1]);
                sorted = false;
            }
        }

        m++; // The next iteration starts one place after the previous
    }
}


void print_array(int array[], int n)
{
    // print out the array so we can see the contents
    for (int i = 0; i < n; ++i)
    {
        std::cout << array[i] << ",\t";
        if (i % 10 == 9) std::cout << std::endl;
    }
    std::cout << std::endl;
    std::cout << std::endl;
}

void swap(int& a, int& b)
{
    // swap the the elements around

    swaps++; // count the number of swaps done

    // make the swaps
    int temp = a;
    a = b;
    b = temp;

}

bool Compare(int first, int second) {
    comparisons++; // Count the number of comparisons

    if (first > second)
    {
        return true;
    }
    else {
        // first integer is not greater than second integer
        return false;
    };
}