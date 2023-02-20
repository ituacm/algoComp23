# Octagonal Prism

Denis loves to play with prisms. One day he brings a prism to ITU and he talks about a puzzle related to this prism with Rojen. First of all, this prism is an octagonal prism and normally, each surface of it contains a different positive integer from other surfaces. But Denis wants to change the puzzle to make easier to solve for Rojen and he selects four rectangular surfaces of the prism: these surfaces are not adjacent and each one has the same integer value with its opposite surface.

Denis defines one more thing: corner values. Each corner has a value and it is equal to the multiplication of the integers of adjacent surfaces to that corner. Denis gives a number to Rojen and asks: "This number will be equal to the summation of corner values. If you can find valid number combinations for surfaces, tell me all the possible summation of surfaces in a sorted way.".

Since Denis was so helpful, each time he gives numbers that can be written as the product of 3 prime numbers and asks Rojen to find all possible valid surface numbers' summation. Can you help Rojen?

---

## Input Format

First line consists of one integer $q$ which is number of numbers that Denis will give to Rojen.

Next $q$ lines consist of one integer $n$.

---

## Output Format

For each query, print sorted space separated integers denoting all possible summations of surfaces. If there is no valid summation, print $-1$.

---

## Constraints

$1 \leq q \leq 5\times10^4$

$1 \leq n \leq 10^7$

---

## Sample Input

```
2
2431
105
```

## Sample Output

```
52 54 58
-1
```