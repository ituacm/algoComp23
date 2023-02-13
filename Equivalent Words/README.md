# Equivalent Words

Omer loves to find new patterns on his own. One day, while watching the world cup, he creates the definition of "equivalent words". According to his definition, if the letter frequencies of two words are equal, they are equivalent. For example, **cronaldo** and **neymarjr** are equivalent words. Because the letter frequencies for the word **cronaldo** is 1-1-1-1-1-2-1 (a: 1, c: 1, d: 1, l: 1, n: 1, o: 2, r: 1), while for the word **neymarjr** it is 1-1-1-1-1-2-1 (a: 1, e: 1, j: 1, m: 1, n: 1, r: 2, y: 1). The frequency and number of letters in both strings are equal to each other.

However, **leomessi** and **cronaldo** are not equivalent, because the letter frequency for the word **leomessi** is 2-1-1-1-1-2, while for the word **cronaldo** it is 1-1-1-1-1-2-1. *So they are not in the same league ;).*

Omer has bunch of words listed in his mind. As he is watching the world cup, Murat approaches him: "Okay, I'm going to give you some words. For each word I give, can you tell me its equivalent?". Omer tries his best but he cannot concentrate because he is currently amazed by Messi's moves. 

Can you fulfill Murat's request for Omer and give him a rest while he is watching the world cup?

## Input Format

- First line contains $2$ space separated integers $m$ and $n$ where $m$ is the length of the word list, $n$ is the length of the query list.
- Following $m$ lines contain each member of Omer's list where each line has one single string.
- Following $n$ lines contain each member of Murat's list where each line has one single string.

It is guaranteed that all strings consist of lowercase English letters.

## Constraints

$1 \leq m \leq 10^5 $

$1 \leq n \leq 10^4 $

$1 \leq w \leq 20$ where $w$ is the length of each word.

## Output Format

For each query from Murat, print $1$ line containing the indexes of the given word's equivalents in Omer's list. Indexes must be printed in ascending order.

## Sample Input 1

```
12 3
pepguardiola
josemourinho
jurgenklopp
fatihterim
senolgunes
carloancelotti
leomessi
cronaldo
neymarjr
robben
muller
mbappe
rnazario
luissuarez
dybala
```

## Sample Output 1

```
6
3
9 10 11
```