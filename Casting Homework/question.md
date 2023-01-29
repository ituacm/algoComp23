# Casting Homework

Selim is a computer science student who has trouble doing character and integer conversions. Thereupon, Selim's programming teacher, Serhat, prepares a challenging but instructive assignment for him.
In the assignment, Serhat gives a word ~w~ and a target number ~t~. He asks Selim to find whether there are combinations of letters whose sums are equal to the given number, according to the alphabetical order of the letters in the word.

For example, for the word 'acb', the 'ab' combination equals 1+2 = 3, and the 'acb' combination equals 1+3+2 = 6. Remember that the number values of the letters are given with respect to their order in the alphabet.
However, Selim claims that these letter combinations may be too long and that he cannot calculate them all as quickly as requested. Convinced by these reasons, Serhat puts a limit on the length of combinations to be considered as ~k_{max}~. He then asks Selim to calculate for each integer ~k_{i}~ in the range ~[1,k_{max}]~ print ~1~ if it is possible to get target sum with ~k_i~ letters, else print ~0~.

Selim really wants to ace this assignment but doesn't know how. You are expected to assist him.

## Input Format

The first line contains a string ~w~ consisting of lowercase English letters only. 

The following line contains the target sum ~t~ and the length of the maximum combination ~k_{max}~

## Constraints

- ~1 \leq length\ of\ w \leq 20 ~
- ~1 \leq t \leq 520~
- ~1 \leq k_{max} \leq 20~

## Output Format

For each ~k_i~, print ~1~ if at least one combination exists, else print ~0~, where ~k_{i} \in [1,k_{max}]~.

## Sample Input 1
<pre>
serhat
24 6
</pre>

## Sample Output 1

<pre>0 1 1 0 0 0</pre>

## Sample Explanation 1

For two letters 'e' and 's', for three letters 'a', 'e' and 'r' satisfies the conditions.