/**
 *   @file: integers.cc
 * @author: Brody Reynolds
 *   @date: 10/11/2021
 *  @brief: This program provides the ability to find multiple solution through the menu displayed
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <math.h>
using namespace std;

/**
 * getNumDigits - finds and returns the length of an integer
 * @param number - the value is to be used to find its length
 * @return length - the length of integer
 */
int getNumDigits(int number);

/**
 * getNthDigit - finds and returns the nth digit when determining the position
 * @param number , n - the number value is used to find the n which is the nth digit
 * @return - the nth digit will be returned
 */
int getNthDigit(int number, int n);

/**
 * getSumDigits - finds and returns the sum of integers inserted
 * @param number - the value used to find total sum
 * @return sum - the total sum of integer
 */
int getSumDigits(int number);

/**
 * isPalindrome - finds and returns if an integer is a palindrome or not
 * @param number - the value to used to find its a palindrome or not
 * @return true, false - if the num1 == num2 than it will return as a true palindrome but otherwise its not a palindrome
 */
bool isPalindrome(int number);

/**
 * getInteger - returns the number if > 0
 * @param - none delcared in function decleration but is declared within the function itself as 'number'
 * @return - returns number from the users keyboard if > 0
 */
int getInteger();

int main(int argc, char const *argv[])
{
    int number;
    int choice;
    do // This the menu of choices for the seprate situations and functions
    {
        cout << "1. Find the number of digits in an integer." << endl;
        cout << "2. Find the nth digit in an integer." << endl;
        cout << "3. Find the sum of all digits of an integer." << endl;
        cout << "4. Is the integer a palindrome?." << endl;
        cout << "5. Quit" << endl;
        cout << "Enter a choice: ";
        cin >> choice;

        if (choice == 1) // Will find the length of inserted digits
        {

            while (choice == 1)
            {

                number = getInteger();
                int length;

                if (number >= 0)
                {
                    length = getNumDigits(number);

                    cout << number << " has " << length << " digits." << endl;
                    break;
                }
            }
            break;
        }

        else if (choice == 2) // Will find the nth digits with the given integer
        {

            while (choice == 2)
            {
                number = getInteger();
                int newNumber;
                int position;

                cout << "Enter a position: ";
                cin >> position;

                newNumber = getNumDigits(number);

                if (position > newNumber) // If position number is greater than the digits themselves = error
                {
                    cout << "Invalid position" << endl;
                }
                else
                {
                    cout << "Digit number " << position << " is " << getNthDigit(number, position) << "." << endl;
                    break;
                }
            }
            break;
        }

        else if (choice == 3) // Will find the sum of the inserted digits
        {
            while (choice == 3)
            {
                int sum;
                number = getInteger();
                sum = getSumDigits(number);

                cout << "The sum of all digits in " << number << " is " << sum << "." << endl;
                break;
            }

            break;
        }

        else if (choice == 4) // Will find if the integer has the same beginning and end digits
        {
            while (choice == 4)
            {
                int pal;

                number = getInteger();
                pal = isPalindrome(number);

                cout << "The number " << number << " is ";

                if (pal) // If the first and last digits the same
                {
                    cout << "Palindrome.";
                    break;
                }
                else // If anything else than its not a palindrome
                {
                    cout << "Not a palindrome.";
                    break;
                }
            }

            break;
        }
        else if (choice == 5)
        {
            cout << "Done!";
            return 0;
        }

    } while (choice != 5);

    return 0;
}

int getNumDigits(int number)
{
    int length = 0, i;

    while (number != 0)
    {
        i = number % 10;      // Help find the individual digits
        length++;             // Adds to the count of the length
        number = number / 10; // Reduces the number and runs it again until it reaches 0
    }

    return length; // Final number for the amount of digits there are
}

int getInteger()
{
    int number;

    do // If inserted number < 0 than it will repeat command
    {
        cout << "Enter a positive integer: ";
        cin >> number;

    } while (number <= 0);

    return number;
}

int getNthDigit(int number, int n)
{
    int count = 0, i;

    while (number != 0)
    {
        i = number % 10; // Helps to find the individual digits
        count++;

        if (count == n) // When the count == n (position) than return the found digit position
        {
            return i;
        }
        number = number / 10; // Reduces the number and runs until it equals 0
    }
    return 0; // Quits program
}

int getSumDigits(int number)
{
    int sum = 0, i;

    while (number != 0)
    {
        i = number % 10;      // Helps to find the individual digits
        sum = sum + i;        // Adds to the total sum
        number = number / 10; // Reduces the number and runs until it equals 0
    }

    return sum; // Final sum
}

bool isPalindrome(int number)
{
    int num1;
    num1 = number;
    int num2 = 0, i;

    while (number != 0)
    {
        i = number % 10;      // Helps to find the individual digits
        num2 = num2 * 10 + i; // Calculates the num2 values for future comparison
        number = number / 10; // Reduces the number and runs until it equals 0
    }

    if (num2 == num1) // Helps to figure out when the first and final digits equal each other
    {
        return true;
    }
    else
    {
        return false;
    }
}
