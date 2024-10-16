#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sort.h"

using namespace std;

// Main function to generate votes and count them
int main() 
{
    const int arrSize = 101;
    const int candidates = 5;
    int votes[arrSize];
    int voteCount[6] = {0}; // Count for candidates 1 to 5

    // Seed for random number generation
    srand(time(0));

    // Generate random votes from 1 to 5
    for (int i = 0; i < arrSize; i++) {
        votes[i] = rand() % candidates + 1; // Random number between 1 and 5
    }
    
    // Display the unsorted random votes
    cout << "Unsorted array: " <<endl;
    for (int i = 0; i < arrSize; i++) 
	{
        cout << votes[i] << " ";
    }
    cout << endl;
    cout << endl;

    // Sort the votes
    selectionSort(votes, arrSize);

    // Count the votes
    for (int i = 0; i < arrSize; i++) {
        voteCount[votes[i]]++;
    }
    
    // Display the sorted random votes
    cout << "Sorted array: " << endl;
    for (size_t i = 0; i < arrSize; i++) {
        cout << votes[i] << " ";
    }
    cout << endl;
    cout << endl;

    // Determine the winning candidate
    int maxVotes = 0;
    int winningCandidate = 0;

    for (int i = 1; i <= candidates; i++) {
        cout << "Candidate " << i << ": " << voteCount[i] << " votes" << endl;
        if (voteCount[i] > maxVotes) {
            maxVotes = voteCount[i];
            winningCandidate = i;
        }
    }

    // Output the winning candidate
    cout << "The winning candidate is Candidate " << winningCandidate << " with " << maxVotes << " votes." << endl;

    return 0;
}
