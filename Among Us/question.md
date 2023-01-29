# Among Us

Among Us is a game where imposters main desire is to kill all crewmates in a spaceship. Daria is a good among us player and she is the imposter of this game. She selects a terrible bad player to kill, Efe. Efe is a crewmate and he is at the bottom right of the spaceship while Daria is at the top left.

Since Daria is a very curious player, she is trying to calculate the number of different ways to reach Efe following the rules of the game: The imposter, Daria, can only move right or down through corridors. She can use vents to move quicker. Vents are secret passages that have one entrance and one exit. A vent's entrance is always located at the top left of its exit.

Remember, since Efe is a terrible player he doesn't even move. Help Daria to kill Efe.

## Input Format

First line contains three integers
~m~, ~n~ and ~v~.
- ~m~ is the height of the spaceship.
- ~n~ is the widht of the spaceship.
- ~v~ is the number of vents.

The next ~m~ lines contain ~n~ ones and zeros. Ones are the corridors and zeros are the walls. Imposter can't go through walls. It is guaranteed that top left and bottom right of the spaceship are corridors.

The next ~v~ lines contain ~4~ integers. Entrance's vertical position, entrance's horizontal positon, exit's vertical position, exit's horizontal position.  It is guaranteed that all the vent entrances and exits are built on corridors.

## Constraints

- ~1 \leq m \leq 10^3~
- ~1 \leq n \leq 10^3~
- ~1 \leq v \leq 10^2~
- ~c_{ij}\in\{0,1\}~, where ~i\in\left[0,m-1\right]~ and ~j\in\left[0,n-1\right]~.

## Output Format

One integer in mod ~10^9+7~ denoting the number of different ways to go to the bottom right of the spaceship from the top left.

### Sample Input

<img src="https://contest.ituacm.com/static/images/questions/amongus.png" width="50%">

```
4 6 2
1 1 1 1 1 1
1 1 0 1 1 1
0 1 1 1 0 1
1 1 0 1 1 1
1 1 1 3
2 3 3 4
```

### Sample Output

```
15
```