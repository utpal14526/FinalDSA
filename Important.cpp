
// points to remember in middle of contest

// Strings->>> KMP and TRies , Z function  , Plaindromic Sustring  Manchester's algo // string HASh
// Binary search + two pointers
// Binary search + kmp
// to find how many pattern occurs in my substring
// 1. i-th point trick
// Generate all possibilities
// Discard some one
// 2. Bit trick or bitmask
// 3. Inclusion exclusion
// 4. Make dependency and solve topo
// 5. Dp
// 6. Meet in the middle
// 7. trie --> substring and bits
// 8. stack monotics
// 9. two pointers
// 10. Venn diagram
// 11. string --> kmp laga skte hai/ manchester's algo
// 12. String hash or z- function
// 13. Dp on trees
// 14. Matrix expo --> to further reduce  time complexity
// 15. +1 -1 to balance the things --> in the range to that two guantities are equal
// 16.  mod mai dekhoge prime factors
// zero -1 bfs
// whenever we have a directed graph with no driected cycle  dp apply is good option here
// venn diagram
// to find all permutate of a string use next_permutation(s.begin(),s.end())
// arr[n][m]--> always use n<m  -->
// never use LONG_MAX please in dp

// check without taking any element in comparsion

// hey whenever you have to store a map of small no of keys try to build it with a bitmask--> beneficial instead of storing a map
// bitmask

// i have a string i want to find how many times this pattern appear in my string

//  abadeabadeaba
//  aba
//  KMP algo
//  Z function Algo  Z-box

// Think of optimizing states in the dp by using less complexity variable or
// meet in the middle
// bits optimize
// sqrt decompose
// bitset --> powerful tool to know everything in bit

// dp mai matrix multiplication in Log(N) --> can be used

// sometimes binary search double mai krni hoti hai

// In a range we have a vlaue Mo's algorithm can be better choice for answering my answers

// in  the queries caclcutae fast sparse table, binary lifting can work
// dp on number theory

// sum of bitwise xor of all subsequences of arrays= 2^(n-1)*bit  bit is bitwise or of all elements.

// lcm and gcd result

// count all good subarrays  = total - bad subarrays
// a+b = (a XOR b) + (a AND b)*2

// ll findXorinrange(ll x)
// {
//     ll txor;
//     if (x % 4 == 0)
//         txor = x;
//     else if (x % 4 == 1)
//         txor = 1;
//     else if (x % 4 == 2)
//         txor = x + 1;
//     else
//         txor = 0;

//     return txor;
// }

//  // (k)^(k+2^i)^(k+2^i+2^i).....
// (k^k^k^k^....) n times ^ (0⋅x⊕1⋅x⊕2⋅x⊕…⊕(n−1)⋅x)

// in segment tree alot of techniques are there   compress array size
//   make buckets for each elee in segmented array
//   where each index uses a range sum   sqrt idea  mainly in Salary Quesries Cses

// lower_bound({a, b}) : Finds the first pair where : first > a, or
//                                                                   first == a and second >= b.upper_bound({a, b}) : Finds the first pair where : first > a,
//     or
//         first == a and second > b.