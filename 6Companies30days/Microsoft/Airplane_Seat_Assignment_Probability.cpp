class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        return n==1?1:0.5;
    }
};
/*
Q & A
Q1: Say if there are n passengers and the first passenger took the 3rd seat. Now, like you explained, there are n - 1 passengers and n - 1 seats left. But when the 2nd passenger comes in, he doesn't have 2 options to make it possible for the nth passenger to take the nth seat. Instead, he only has one option, which is to take the 2nd seat because it is not occupied by the first passenger. I don't see how that is the case of a subproblem of (n - 1). Could you shed some light please, thanks!
A1: For any case, we can get rid of those sitting on own seats (except the first passenger) and get a problem of n' (= n - k, where k is the number of passengers sitting on own seats), then re-number (without changing the relative order) them as passenger 1, 2, ..., n', hence the result is in same form, the only difference is to change n to n'.
Except n' = 1, results for n' of other values are independent on n'. In short, changing from n to n' will not influence the result.

Q2: What would have happened if we didn't knew which one of them lost the ticket?
A2: If last one lost ticket, the Prob. is 1; otherwise 0.5.
Proof:
Assume there are n' passengers totally, and the (k + 1)th passenger lost his ticket. First k ones definitely seat on their own seats Let n = n' - k, we get a problem of n, which is exactly same as the original problem.
*/