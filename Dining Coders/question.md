# Dining Coders

The name evokes something, right? Nevermind...

Some coders who love different tastes sit around a circular dining table to eat some food. They are quite indecisive and try to select which foods they will eat. Initially, everyone orders one portion of food each and they also have an agreed food to put in the middle of the table. There will always be one food in front of each coder, and there is only one additional food in the middle of the table at all times. As coders, they have an analytical way of thinking so they do not care about how the foods are named; instead, they assign some ids to them.

The coders want to taste as many flavors as possible, so the waiters are trying to help them browse the menu in more detail. There are two options. They may either suggest putting new food in the middle of the table or taking away the food that is already in the middle to open up space and provide more options.

When the waiters put a portion of new food in the middle of the table, the coder whose food has the smallest id will take the food that was previously in the middle of the table and his initial food will be taken away.

When the waiters take away the food in the middle of the table, the coder whose food has the biggest id will put their food in the middle and the waiters will bring them new food.

If, at any point, there can be two or more coders who can have their food with the same id, choose the coder with the smaller index.

## Input format:
First line consists of ~3~ integers ~n~, ~m~ and ~c~ which are the number of coders, number of waiter's suggestions and the id of initial food in the middle of the table respectively.

Second line contains ~n~ integers denoting id's of coders' foods as ~f_1~, ~f_2~, ..., ~f_n~ where ~f_i~ is ~i~th coder's food.

Following ~m~ lines contain ~2~ integers ~t~ and ~f~ which are query type and new food's id respectively. For ~t = 1~ queries, put given new food to the middle of the table. For ~t = 2~ queries, pick up the food from the middle of the table.

## Constraints

~1 \leq n \leq 10^5~

~1 \leq m \leq 5\times10^4~

~0 \leq c, f_i \leq 10^6~

~t \in \{1, 2\}~

## Output Format:
For each query type 1, print the id of the food that is removed from the table and the index of the people (indexes starts from 1 goes to n).

For each query type 2, print the id of the food that is removed from the middle of the table.

## Sample Input:
```
3 5 2
1 2 3
1 4
2 1
1 18
2 8
1 4
```

## Sample Output:
```
1 1
4
1 3
18
2 1
```