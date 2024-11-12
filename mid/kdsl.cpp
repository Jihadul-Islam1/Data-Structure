#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int T;
    cin >> T;  // Read the number of test cases

    while (T--) 
    {
       long long int a, b, c;
        cin >> a >> b >> c;  // Read the lengths of the triangle sides
        long long s = (a + b + c) / 2;  // Compute the semi-perimeter of the triangle
        
        // Calculate the area using Heron's formula (we use the area squared, not the actual area)
        long long area = s * (s - a) * (s - b) * (s - c);  
        
        // If the area squared is negative or zero, something went wrong (but the problem guarantees valid triangles)
        if (area <= 0) 
        {
            cout << "Error: invalid triangle dimensions\n";
            continue;
        }
        
        // The numerator is 4 * area
        long long n = 4 * area;  
        // The denominator is 4 * s^2 (which represents the squared semi-perimeter)
        long long d = 4 * (s * s);  

        // Compute the greatest common divisor of the numerator and denominator
        int g = gcd(n, d);  
        
        // Reduce the fraction by dividing by the GCD
        n /= g;  
        d /= g;  

        // Output the reduced fraction
        cout << n << "/" << d << endl;  
    }

    return 0;
}
