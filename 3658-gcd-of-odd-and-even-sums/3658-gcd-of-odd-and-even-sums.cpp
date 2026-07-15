class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // Sum of first n odd numbers = n²
        //int sumOdd = n * n;

        // Sum of first n even numbers = 2(1+2+...+n) = n(n+1)
        //int sumEven = n * (n + 1);

        // gcd(sumOdd, sumEven)
        // = gcd(n², n(n+1))
        // = n × gcd(n, n+1)
        // Consecutive numbers are always coprime,
        // so gcd(n, n+1) = 1.
        // Hence, answer = n.
        return n;
    }
};