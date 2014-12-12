/* sum_primes.rs sums all the prime numbers up to the user's specification */
// (C) GPL, Edmund Higham, Nov 2014

use std::io;
use std::num;

fn is_prime(n: int) -> bool {
    let mut prime: bool = true;

    if (n as f64).sqrt() as int >= 2 {

        if n % 2 == 0 {
            prime = false;

        } else {
            for i in range(3i,(n as f64).sqrt() as int) {
                if n % i == 0 {
                    prime = false;
                    break;
                }
                i += 1;
            }
        }
    }
    return prime;
}

fn main(){

    let n: int = 5;

    println!("{} is prime? {}",n,is_prime(n));

}