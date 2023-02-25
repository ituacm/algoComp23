# Bridge Construction

Due to global warming, climate is very unstable and not normal. Istanbul is one of the cities which are effected by this situation. One day, there was a terrible storm in Istanbul Ayazağa and as a result, ITU was flooded. After the storm, some areas were flooded and some of them are not. Let us call flooded areas as water and not flooded areas as land. You are given a $n \times n$ map of ITU that any cell is either water or land. Waters and lands are represented with $0$ and $1$ respectively.

At this situation, the bravest persons of ITU which are Fatih and Omer, decide to help people. To do so, Fatih and Omer decide to use their deep knowledge about making bridges to connect lands. Their strategy is connecting lands with a bridge and making the largest possible land to help more people. They are masters of bridge construction; so their bridges can be built anywhere, even in the middle of flooded areas. But their resources are limited, therefore they can construct only one bridge using at most $3$ adjacent cells (adjacency should be considered only in horizontal and vertical directions). Can you help Fatih and Omer to find the largest possible land area?

NOTE: This question has two valid solutions. You can find them within the same folder.

---

## Input Format

First line contains one integer $n$ which is the width and height of the given map.

The next $n$ lines contain $n$ ones and zeros. Ones are the land cells and zeros are the water cells.

---

## Output Format

Print one integer which is the maximum possible area of lands. Note that bridges also count as land in all cases.

---

## Constraints

- $1 \leq n \leq 300$

---

### Sample Input

```
5
1 1 0 0 0
1 1 0 0 0
0 0 0 0 0
0 0 0 1 1
1 0 0 1 1
```

### Sample Output

```
11
```
