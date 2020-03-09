//Gegeben sei eine Reihe von Zahlen, finden Sie die längste zusammenhängende Teilfolge so,
// dass alle zwei beliebige aufeinanderfolgende Elemente relativ prim sind
#include<assert.h>
#include<iostream>


int isPrime(int n)  //check if a number is prime
{

    int d, ok = 0;
    if (n < 2)
        return 0;
    for (d = 2; d * d <= n; d++)
    {
        if (n % d == 0)
        {
            ok = 1;
            return 0;
        }
    }
    return 1;
}



int longestSequence(const int arr[], int size)
{

    int currentSeq = 0;  //we need an overall maximum sequence and a current one, to compare every sequence
    int maxSeq = 0;

    for (int i = 0; i < size; i++)

    {
        int ok = 0;
        if (isPrime(arr[i]) == 1)
            ok = 1;

        {

            currentSeq++;              //if the number is prime, we add a +1 to the currentSeq, update the max, and 
            if (currentSeq > maxSeq)   //go to the next index
            {
                maxSeq = currentSeq;
                i++;
            }
            else currentSeq = 0;

            ok = 0;

            if (isPrime(arr[i]) == 1)  //if the next number is also prime, repeat the process

                ok = 1;

            if (ok == 1)

            {
                currentSeq++;
                if (currentSeq > maxSeq)
                {
                    maxSeq = currentSeq;
                    i++;
                }
                else currentSeq = 0;
            }

        }
        if (ok == 0)        //reset the currentSeq
            currentSeq = 0;



    }
    if (currentSeq > maxSeq)
        maxSeq = currentSeq;

    return maxSeq;
}

int first_n_prime_numbers(int nr)
{
    unsigned int i, d, ok, count = 0;

    for (i = 2; i <= std::numeric_limits<double>::infinity(); i++)
    {
        ok = 1;   //we set variable "ok" to 1 and if the number we are currently checking is proven to be:
        if (i % 2 == 0 && i != 2) //1.even (except for 2), we set the flag to 0, as the number isn't prime
            ok = 0;
        else
            d = 3;
        while (d * d <= i && ok == 1) //
        {
            if (i % d == 0)  //2.to have dividents, then we do the same thing
                ok = 0;
            else
                d = d + 2;
        }
        if (ok == 1)
        {
            std::cout << i << " ";
            count++;
            if (count == nr) //we verify if we splayed the first n prime numbers
                break;
        }
    }
    return 0;
}